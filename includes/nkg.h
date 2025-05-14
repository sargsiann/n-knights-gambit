#ifndef NKG_H
# define NKG_H

// DEFINING DEFAULT SIZES FOR VERTICAL AND HORIZONTAL BOARD

# define V_SIZE 3
# define H_SIZE 5
# define CELL_LENGHT 40

# define WIDTH 1200
# define HEIGHT 1000

// INCLUDES

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// STRUCTS

typedef struct s_image {
	char	*address;
	void	*img;
	int		endian;
	int		line_size;
	int		bits_p_pixel;
}	t_image;

typedef	struct s_screen {
	void	*connection;
	void	*window;
	t_image *image_s;
}	t_screen;

typedef struct s_knight {
	int 			v_pos;
	int				h_pos;
	struct s_knight *next;
}	t_knight;


typedef struct s_board {
	int 	v_size;
	int		h_size;
	bool	**cells;
}	t_board;

typedef struct s_path {
	int *path;
	int	size;
}	t_path;


// UTILS
void		*safe_malloc(size_t size);
void		exit_error(char *str);

// INITS
t_board		*init_board(int ac, char **av);
t_screen	*init_screen();

// DRAWING 
void	draw_board(t_board *board, t_screen *screen);
void	my_pixel_put(int i, int j, t_image *img, int color);

#endif