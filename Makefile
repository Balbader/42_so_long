# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 17:08:02 by baalbade          #+#    #+#              #
#    Updated: 2023/08/03 17:08:04 by baalbade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################
#   	      NAME 				 #
##################################
NAME				:=	so_long


##################################
#    	    SRCS FILES			 #
##################################
FT_PRINTF_DIR		:=	ft_printf/
FT_PRINTF_FILES		:=	ft_print_char.c \
						ft_print_hexa.c \
						ft_print_nb.c \
						ft_print_ptr.c \
						ft_print_str.c \
						ft_print_unsigned.c \
						ft_printf.c
FT_PRINTF			:=	$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))

GNL_DIR				:=	gnl/
GNL_FILES			:=	get_next_line.c \
						get_next_line_utils.c
GNL					:=	$(addprefix $(GNL_DIR), $(GNL_FILES))

LIBFT_DIR			:=	libft/
LIBFT_FILES			:=	ft_free_tab.c \
						ft_free_tabs.c \
						ft_itoa.c \
						ft_memcpy.c \
						ft_split.c \
						ft_strdup.c \
						ft_strjoin.c \
						ft_strlen.c \
						ft_strncmp.c
LIBFT				:=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILES))

MAP_CHECK_DIR		:=	map_check/
MAP_CHECK_FILES		:=	ft_check_format.c \
						ft_check_if_open.c \
						ft_check_path.c \
						ft_count_content.c \
						ft_flood_fill.c \
						ft_map_size.c \
						ft_validate_content.c \
						ft_validate_map.c
MAP_CHECK			:=	$(addprefix $(MAP_CHECK_DIR), $(MAP_CHECK_FILES))

MAP_PARSING_DIR		:=	map_parsing/
MAP_PARSING_FILES	:=	ft_parse_map.c \
						ft_read_map.c
MAP_PARSING			:=	$(addprefix $(MAP_PARSING_DIR), $(MAP_PARSING_FILES))

RENDER_DIR			:=	render/
RENDER_FILES		:=	ft_confirm_move.c \
						ft_copy_img.c \
						ft_get_pixel.c \
						ft_is_obstacle.c \
						ft_move_player.c \
						ft_put_pixel.c \
						ft_put_sprite_to_map.c \
						ft_render.c \
						ft_render_map.c \
						ft_render_player.c
RENDER				:=	$(addprefix $(RENDER_DIR), $(RENDER_FILES))

SET_TEXTURE_DIR		:=	set_texture/
SET_TEXTURE_FILES	:=	ft_init_textures.c \
						ft_set_collectibles.c \
						ft_init_win.c \
						ft_load_texture_to_img.c \
						ft_set_floor.c \
						ft_set_map_exit.c \
						ft_set_mid_wall.c \
						ft_set_player.c \
						ft_set_wall.c
SET_TEXTURE			:=	$(addprefix $(SET_TEXTURE_DIR), $(SET_TEXTURE_FILES))

UTILS_DIR			:=	utils/
UTILS_FILES			:=	ft_check_file_ext.c \
						ft_check_main_args.c \
						ft_close_win.c \
						ft_duplicate_map.c \
						ft_find_pos.c \
						ft_handle_key.c \
						ft_map_error.c
UTILS				:=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))


##################################
#   		INGREDIENTS 		 #
##################################
INC_DIR				:=	./inc/

SRCS_DIR			:=	./srcs/
SRCS				:=	\
						$(FT_PRINTF) \
						$(GNL) \
						$(LIBFT) \
						$(MAP_CHECK) \
						$(MAP_PARSING) \
						$(RENDER) \
						$(SET_TEXTURE) \
						$(UTILS) \
						main.c
SRCS				:=	$(SRCS:%=$(SRCS_DIR)/%)

MLX					:=	inc/mlx_linux/libmlx.a
INC_MLX				:=	./inc/mlx_linux/
LIB					:=	-L ./inc/mlx_linux -lmlx -lXext -lX11

BUILD_DIR			:=	.build
OBJS				:=	$(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS				:=	$(OBJS:.o=.d)


CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -fsanitize=address -static-libsan
IFLAGS				:=	$(addprefix -I, $(INC_DIR))

RM					:=	rm -r -f
DIR_DUP				=	mkdir -p $(dir $@)


##################################
#   		COLORS 				 #
##################################
RED     			:= \033[0;31m
GREEN   			:= \033[0;32m
YELLOW  			:= \033[0;33m
RESET   			:= \033[0m


##################################
#   		RECIPES				 #
##################################
all: $(MLX) $(NAME)

$(NAME): $(OBJS)
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB) 
	@echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) ready!"

$(MLX):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling minilibx..."
	@make -sC $(INC_MLX) > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Minilibx ready!"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@make -sC $(INC_MLX) clean > /dev/null
	@$(RM) $(BUILD_DIR) $(DEPS)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@$(RM) $(NAME)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Binary file removed."

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
