.SUFFIXEX : .c .o

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit\
			-Llibft -lft -Lft_printf -lftprintf
INCLUDE = -I./includes -I./libft -I./mlx -I./ft_printf/include

SRCS_DIR = ./srcs/
SRCS_NAME =	main.c \
			init.c \
			init_2.c \
			load_texture.c \
			free_or_error.c \
			free_or_error_2.c \
			get_next_line.c \
			parsing_cub_3.c \
			parse_line_3.c \
			parse_map_3.c \
			fill_map_3.c \
			check_map_valid_4.c \
			main_loop_5.c \
			cast_floor_ceiling_6.c \
			cast_wall_7.c \
			cast_sprite_8.c \
			sprite_sort_8.c \
			deal_key_9.c \
			control_player_10.c \
			bmp.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJS_DIR = ./obj/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

MLX_DIR = ./mlx
MLX = ./mlx/libmlx.a

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = ./ft_printf/libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(PRINTF) $(MLX) 
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJS) $(LIBS_FLAGS) 

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(LIBFT) :
		$(MAKE) -C $(LIBFT_DIR) all

$(PRINTF) :
		$(MAKE) -C $(PRINTF_DIR) all

$(MLX) :
		$(MAKE) -C $(MLX_DIR) all


clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re