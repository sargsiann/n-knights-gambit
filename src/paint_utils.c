#include "nkg.h"

void	my_pixel_put(int i, int j, t_image *img, int color) 
{
	char *address = img->address + (i * img->line_size + j * (img->bits_p_pixel / 8));

	if (i >= HEIGHT || j >= WIDTH || i < 0 || j < 0)
		return ;
	// ARGB -> BGRA
	if (img->endian == 0) {
		address[0] = (unsigned char)(color); // b
		address[1] = (unsigned char)(color >> 8); // g 
		address[2] = (unsigned char)(color >> 16);// r
		address[3] = (unsigned char)(color >> 24); // a
		return ;
	}
	// ARGB -> argb
	address[0] = (unsigned char)(color >> 24);
	address[1] = (unsigned char)(color >> 16);
	address[2] = (unsigned char)(color >> 8);
	address[3] = (unsigned char)(color);
}

void	fill_cell(int i, int j, t_image *img) 
{
	int color = (i + j) % 2 == 0 ? 0xffffff : 0x0000000;

	int y = i * CELL_LENGHT + HEIGHT/2 - 200;
	int x = j * CELL_LENGHT + WIDTH/2 - 200;

	for (int z = 0; z < CELL_LENGHT; z++) {
		for (int w = 0; w < CELL_LENGHT; w++) 
		{
			my_pixel_put(y + z,x + w,img,color);
		}
	}
}


void	draw_board(t_board *board, t_screen *screen) 
{
	bool **cells = board->cells;

	for (int i = 0; i < board->v_size; i++) {
		for (int j = 0; j < board->h_size; j++) {
			fill_cell(i,j,screen->image_s);
		}
	}
	mlx_put_image_to_window(screen->connection,screen->window,screen->image_s->img,0,0);
}
