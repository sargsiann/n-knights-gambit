# Checking The OS 

UNAME_S := $(shell uname -s)

NAME = nkg

CC = cc

# CFLAGS = -Wall -Wextra -Werror

# DEPENDENCIES

DEPS = Makefile includes/nkg.h



# Flags and Libs Depend on the OS

ifeq ($(UNAME_S),Linux)
	MLX_C_FLAGS = -Imlx_linux -O3
	MLX_DIR = mlx_linux
	MLX_L_FLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S),Darwin)
	MLX_C_FLAGS = -Imlx_mac 
	MLX_DIR = mlx_mac
	MLX_L_FLAGS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
else
	$(error "Unsupported OS: $(UNAME_S)")
endif

# Define the source files

SRCS = $(shell find src -name "*.c")

# Define the object files

OBJS = $(SRCS:.c=.o)

# Rules

%.o : %.c $(DEPS)
	$(CC) -I includes $(MLX_C_FLAGS) $(CFLAGS) -c $< -o $@

# targets

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) -I includes $(MLX_C_FLAGS) $(CFLAGS) -o $@ $^ $(MLX_L_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re