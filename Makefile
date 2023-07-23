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
FT_PRINTF_DIR		:=	ft_printf/
FT_PRINTF_FILES		:=	\
						ft_print_char.c \
						ft_printf.c \
						ft_print_hexa.c \
						ft_print_nb.c \
						ft_print_ptr.c \
						ft_print_str.c \
						ft_print_unsigned.c
FT_PRINTF			:=	$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))


GNL_DIR				:=	gnl/
GNL_FILES			:=	ft_get_next_line.c
GNL					:=	$(addprefix $(GNL_DIR), $(GNL_FILES))

MAP_DIR				:=	map/
MAP_FILES			:=	\
						ft_free_map.c \
						ft_get_map_line.c \
						ft_parse_map.c \
						ft_run_map.c
MAP					:=	$(addprefix $(MAP_DIR), $(MAP_FILES))

MAP_CHECK_DIR		:=	map_check/
MAP_CHECK_FILES		:=	\
						ft_check_column.c \
						ft_check_content.c \
						ft_check_format.c \
						ft_check_map_viability.c \
						ft_check_wall.c \
						ft_flood_fill.c
MAP_CHECK			:=	$(addprefix $(MAP_CHECK_DIR), $(MAP_CHECK_FILES))

RENDER_DIR			:=	render/
RENDER_FILES		:=	\
						ft_print_img.c \
						ft_render.c \
						ft_render_background.c \
						ft_render_main.c \
						ft_render_other.c
RENDER				:=	$(addprefix $(RENDER_DIR), $(RENDER_FILES))

RENDER_MOUV_DIR		:=	render_mouv/
RENDER_MOUV_FILES	:=	\
						ft_render_down.c \
						ft_render_left.c \
						ft_render_right.c \
						ft_render_top.c
RENDER_MOUV			:=	$(addprefix $(RENDER_MOUV_DIR), $(RENDER_MOUV_FILES))

SET_DIR				:=	set/
SET_FILES			:=	\
						ft_set_content.c \
						ft_set_image.c
SET					:=	$(addprefix $(SET_DIR), $(SET_FILES))

TEXTURE_DIR			:=	texture/
TEXTURE_FILES		:=	\
						ft_check_collectible.c \
						ft_end_game.c \
						ft_key_press.c
TEXTURE				:=	$(addprefix $(TEXTURE_DIR), $(TEXTURE_FILES))

UTILS_DIR			:=	utils/
UTILS_FILES			:=	\
						ft_atoi.c \
 						ft_is_duplicate.c \
						ft_isdigit.c \
						ft_itoa.c \
 						ft_print_error.c \
						ft_putchar.c \
						ft_putstr.c \
						ft_split.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_strjoin.c \
						ft_strlen.c \
						ft_strncpy.c
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

# INGREDIENTS
LIBMLX				:=	./mlx_linux/libmlx_Linux.a
LIBMLX_TARGET		:=	./mlx_linux/
MAKE_LIBMLX			:=	make -C $(LIBMLX_TARGET)

SRCS_DIR			:=	./srcs/
INC_DIR				:=	./inc/

SRCS				:=	\
						$(FT_PRINTF) \
						$(GNL) \
						$(MAP) \
						$(MAP_CHECK) \
						$(RENDER) \
						$(RENDER_MOUV) \
						$(SET) \
						$(TEXTURE) \
						$(UTILS) \
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


# SPEC
.PHONY: all clean fclean re
# .SILENT:
