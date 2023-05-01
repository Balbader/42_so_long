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
NAME=so_long

# SRCS FILES ##################################################################




# INGREDIENTS #################################################################
LIBFT				:=	./libft/libft.a
LIBFT_TARGET		:=	./libft/
MAKE_LIBFT			:=	make -C $(LIBFT_TARGET)

LIBMLX				:=	./mlx_linux/libmlx_Linux.a
LIBMLX_TARGET		:=	./mlx_linux/
MAKE_LIBMLX			:=	make -C $(LIBMLX_TARGET)

LDFLAGS				:=	-Lmlx_linux -lmlx_Linux -L$(LIBMLX) -Imlx_linux -lXext -lX11 -lm -lz

SRCS_DIR			:=	./srcs/
INC_DIR				:=	./inc/ \
						./libft/includes/

SRCS				:=	\
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR			:=	.build
OBJS				:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS				:=	$(OBJS:.o=.d)

CC					:=	Clang
CFLAGS				:=	-Wall -Wextra -Werror -g3
IFLAGS				:=	$(addprefix -I, $(INC_DIR))
LDLIBS				:=	$(addprefix -l:, $(LIBS))

# USTENSILS	###################################################################
RM					:=	rm -rf
MAKEFLAGS			+=	--no-print-directory
DIR_DUP				:=	mkdir -p $(@D)

# RECIPES #####################################################################
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	cd ./mlx_linux && ./configure && $(MAKE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

.c.o:
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE_LIBFT)

$(LIBMLX):
	$(MAKE_LIBMLX)

-include $(DEPS)

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
