# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 08:42:07 by baalbade          #+#    #+#              #
#    Updated: 2023/05/01 08:42:10 by baalbade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME ########################################################################
NAME				:=	so_long

# SRCS FILES ##################################################################

GAME_DIR			:=	game/
GAME_FILES			:=	\
						controls.c \
						errors.c \
						graphics.c \
						map.c
GAME				:=	$(addprefix $(GAME_DIR), $(GAME_FILES))

PRINTF_DIR			:=	ft_printf/
PRINTF_FILES		:=	\
						ft_print_char.c \
						ft_print_hexa.c \
						ft_print_nb.c \
						ft_print_ptr.c \
						ft_print_str.c \
						ft_print_unsigned.c \
						ft_printf.c
PRINTF				:=	$(addprefix $(PRINTF_DIR), $(PRINTF_FILES))

GNL_DIR				:=	gnl/
GNL_FILES			:=	\
						get_next_line.c \
						get_next_line_utils.c
GNL					:=	$(addprefix $(GNL_DIR), $(GNL_FILES))

LIBFT_DIR			:=	libft/
LIBFT_FILES			:=	\
						ft_atoi.c \
						ft_isdigit.c \
						ft_itoa.c \
						ft_putchar \
						ft_putstr.c \
						ft_split.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_strjoin.c \
						ft_strlen.c \
						ft_strncpy.c
LIBFT				:=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILES))



# INGREDIENTS #################################################################
LIBMLX				:=	./mlx_linux/libmlx_Linux.a
LIBMLX_TARGET		:=	./mlx_linux/
MAKE_LIBMLX			:=	make -C $(LIBMLX_TARGET)

SRCS_DIR			:=	./srcs/
INC_DIR				:=	./inc/

SRCS				:=	\
						$(GAME) \
						$(PRINTF) \
						$(GNL) \
						$(LIBFT) \
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR			:=	.build
OBJS        		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        		:=	$(OBJS:.o=.d)

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -g3
IFLAGS				:=	$(addprefix -I, $(INC_DIR))
LDFLAGS				:=	-Lmlx_linux -lmlx_Linux -L$(LIBMLX) -Imlx_linux -lXext -lX11 -lm -lz

# USTENSILS	###################################################################
RM					:=	rm -rf
DIR_DUP				=	mkdir -p $(@D)

# RECIPES #####################################################################
all: $(NAME)

$(NAME): $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

-include $(DEPS)

$(LIBMLX):
	$(MAKE_LIBMLX)

clean:
	$(MAKE_LIBMLX) clean
	$(RM) $(BUILD_DIR) $(DEPS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

############
#   SPEC   #
############
.PHONY: all clean fclean re
# .SILENT:
