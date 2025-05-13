#ifndef NKG_H
# define NKG_H

// INCLUDES

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
	int v_pos;
	int	h_pos;
}	t_knight;

typedef	struct s_cell
{
	int		v_pos;
	int		h_pos;
	bool	visited;
}	t_cell;


#endif