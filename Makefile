NAME = fractol

RM_DIR = rm -rf

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

HEADER_1 = headers/fractol.h

HEADER_2 = projects/headers_2/first_layer.h

SRCS_DIR = srcs/

OBJ_DIR = obj/

LIB_DIR = projects/lib/

LIB = first_layer.a

SRCS_FILES = main.c valid_args.c error_msg.c init.c hooks_handler.c draw.c mandelbrot.c destroy_fractal.c julia.c burning_ship.c \

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR), $(SRCS_FILES:.c=.o))

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(HEADER_1) $(HEADER_2)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_1) -I $(HEADER_2)

all: $(LIB_PATH) $(NAME)

$(LIB_PATH): check_if_exist

$(NAME): $(SRCS) $(O_SRCS)
	clear
	$(MAKE) -C projects all
	$(MAKE) -C minilibx-linux all
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm $(LIB_DIR)$(LIB)
	clear

check_if_exist:
	if [ -d "$(LIB_DIR)" ]; then \
		$(MAKE) -C projects fclean; \
	fi

clean:
	$(MAKE) -C projects/ clean
	$(MAKE) -C minilibx-linux clean
	$(RM_DIR) $(OBJ_DIR)
	$(RM) $(O_SRCS)
	clear

fclean: clean 
	$(RM_DIR) $(LIB_DIR)
	$(RM) $(NAME)
	clear

re: fclean all
	clear

norm:
	norminette *

.PHONY: all clean fclean re push norm
.SILENT:
