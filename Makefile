# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 12:14:32 by baalbade          #+#    #+#              #
#    Updated: 2023/06/28 12:14:34 by baalbade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME				:=	so_long

# SRCS FILES
LOGIC_DIR			:=	logic/
LOGIC_FILES			:=	\
						map.c \
						map_check.c \
						render.c \
						render_mouv.c \
						texture.c \
						utils.c
LOGIC				:=	$(addprefix $(LOGIC_DIR), $(LOGIC_FILES))

MAP_DIR				:=	map/
MAP_FILES			:=	\
						ft_free_map.c \
						ft_get_map.c \
						ft_parse_map.c \
						ft_run_map.c
MAP					:=	$(addprefix $(MAP_DIR), $(MAP_FILES))

MAP_CHECK_DIR		:=	map/
MAP_CHECK_FILES		:=	\
						ft_check_column.c \
						ft_check_content.c \
						ft_check_format.c \
						ft_check_line.c \
						ft_check_other.c
MAP_CHECK				:=	$(addprefix $(MAP_CHECK_DIR), $(MAP_CHECK_FILES))

RENDER_DIR			:=	render/
RENDER_FILES		:=	\
						ft_print_img.c \
						ft_render.c \
						ft_render_background.c \
						ft_render_main.c \
						ft_render_other.c
RENDER				:=	$(addprefix $(RENDER_DIR), $RENDER_FILES)

# INGREDIENTS
LIBFT				:=	./libft/libft.a
LIBFT_TARGET		:=	./libft/
MAKE_LIBFT			:=	make -C $(LIBFT_TARGET)

LIBMLX				:=	./mlx_linux/libmlx_Linux.a
LIBMLX_TARGET		:=	./mlx_linux/
MAKE_LIBMLX			:=	make -C $(LIBMLX_TARGET)

SRCS_DIR			:=	./srcs/
INC_DIR				:=	./inc/

SRCS				:=	\
						$(LOGIC) \
						$(MAP) \
						$(MAP_CHECK) \
						$(RENDER) \
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR			:=	.build
OBJS        		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        		:=	$(OBJS:.o=.d)

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -g3
IFLAGS				:=	$(addprefix -I, $(INC_DIR))
LDFLAGS				:=	-Lmlx_linux -lmlx_Linux -L$(LIBMLX) -Imlx_linux -lXext -lX11 -lm -lz


# USTENSILS
RM					:=	rm -rf
DIR_DUP				=	mkdir -p $(@D)


# RECIPES
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

-include $(DEPS)

$(LIBFT):
	$(MAKE_LIBFT)

$(LIBMLX):
	$(MAKE_LIBMLX)

clean:
	$(MAKE_LIBFT) clean
	$(MAKE_LIBMLX) clean
	$(RM) $(BUILD_DIR) $(DEPS)

fclean:
	$(MAKE) clean
	$(MAKE_LIBFT) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all


# SPEC
.PHONY: all clean fclean re
# .SILENT:
