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




# INGREDIENTS #################################################################
LIBFT				:=	./libft/libft.a
LIBFT_TARGET		:=	./libft/
MAKE_LIBFT			:=	make -C $(LIBFT_TARGET)

LIBMLX				:=	./mlx_linux/libmlx_Linux.a
LIBMLX_TARGET		:=	./mlx_linux/
MAKE_LIBMLX			:=	make -C $(LIBMLX_TARGET)

SRCS_DIR			:=	./srcs/
INC_DIR				:=	./inc/ \
						./libft/includes/

SRCS				:=	main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR			:=	.build
OBJS        		:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        		:=	$(OBJS:.o=.d)

CC					:=	clang
CFLAGS				:=	-Wall -Wextra -Werror -g3
IFLAGS				:=	$(addprefix -I, $(INC_DIR))
LDFLAGS				:=	-Lmlx_linux -lmlx_Linux -L$(LIBMLX) -Imlx_linux -lXext -lX11 -lm -lz

# USTENSILS	###################################################################
RM					:=	rm -rf
DIR_DUP				=	mkdir -p $(@D)

# RECIPES #####################################################################
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

############
#   SPEC   #
############
.PHONY: all clean fclean re
# .SILENT:
