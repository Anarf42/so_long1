# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 09:32:57 by anruiz-d          #+#    #+#              #
#    Updated: 2025/04/04 13:02:56 by anruiz-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# --- Project name --- #
NAME	=	so_long
LIBFT	=	libft.a
MLX42	=	libmlx42.a

# -- Directories --- #

DIR_SRCS	:=	src
DIR_OBJS	:=	obj
DIR_INC		:=	include
MLX42_DIR	:=	MLX42
MLX42_A		:=	$(MLX42_DIR)/build/$(MLX42)
MLX42_INC	:=	$(MLX42_DIR)/include

# --- Source files --- #

LONG_SRC_FILES	=	so_long.c draw_map.c moves_player.c set_map.c validate_map.c \
					utils.c validate_map_01.c

LONG_SRC_DIR	=	$(addprefix $(DIR_SRCS)/, $(LONG_SRC_FILES))

# --- object files --- #

LONG_OBJ_FILES	=	$(LONG_SRC_DIR:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

# --- Compiler and tools --- # 

CC		=	cc
FLAGS	=	-Wall -Wextra -Werror -mmacosx-version-min=15.3 -g3 -fsanitize=address
INCLUDE = -I $(DIR_INC) -I $(MLX42_INC)
RM		=	rm -rf
MKDIR	=	mkdir -p


OS = $(shell uname)
ifeq ($(OS), Linux)
	MLX_FLAGS = -lglfw -lm -ldl -lX11 -lpthread -lXrandr -lXi
else
	MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
endif

###################################################
#		DEFAULT TARGET		  	  #
###################################################
 	
all:	$(MLX42_A) $(NAME)
		
###################################################
#		Program Target	  #
###################################################

$(MLX42_A):
			cmake -B $(MLX42_DIR)/build $(MLX42_DIR)
			cmake --build $(MLX42_DIR)/build

$(NAME):	$(LONG_OBJ_FILES)
			make -C libft
			$(CC) $(FLAGS) $(LONG_OBJ_FILES) $(INCLUDE) libft/$(LIBFT) $(MLX42_A) $(MLX_FLAGS) -o $(NAME)

###################################################
#		OBJECT FILE RULE		  #
###################################################

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@$(MKDIR) $(DIR_OBJS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

###################################################
#		CLEANING RULES			  #
###################################################

clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(MLX42_DIR)/build
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clien fclean re