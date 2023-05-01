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
LIBS				:=	libft.a

LIBS_TARGET			:=	./libft/libft.a
INCS				:=	./inc/ \
						./libft/includes/

SRCS_DIR			:=	./srcs/
SRCS				:=	\
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR			:=	.build
OBJS				:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS				:=	$(OBJS:.o=.d)

CC					:=	Clang
CFLAGS				:=	-Wall -Wextra -Werror -g3
IFLAGS				:=	$(addprefix -I, $(INCS))
LDFLAGS				:=	$(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS				:=	$(addprefix -l:, $(LIBS))

# USTENSILS	###################################################################
RM					:=	rm
RMFLAGS				:=	-r -f
MAKEFLAGS			+=	--no-print-directory
DIR_DUP				:=	mkdir -p $(@D)

# COLORS ######################################################################
RED					:=	'\033[0;31m'
GREEN				:=	'\033[1;32m'
ORANGE				:=	'\033[0;33m'
YELLOW				:=	'\033[1;33m'
NC					:=	'\033[0m'

# RECIPES #####################################################################
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo $(GREEN) "--> $(NAME) COMPILED !" $(NC)" \n"

%o: %.c
	@echo $(YELLOW) "COMPILING:" $(NC) $<
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(IFLAGS) -Imlx_linux -03 -c -o $@ $<
	@echo $(GREEN) "CREATED:" $(NC) $@ $(NC) "\n"

-include $(DEPS)

clean:
	$(RM) $(RMFLAGS) $(BUILD_DIR) $(DEPS)

fclean:
	$(MAKE) clean
	$(RM) $(RMFLAGS) $(NAME)
	@echo $(GREEN) "Successfully removed:" $(NC) $(NAME) $(NC) "\n"

re:
	$(MAKE) fclean
	$(MAKE) all

############
#   SPEC   #
############
.PHONY: all clean fclean re
.SILENT:
