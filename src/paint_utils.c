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
	sleep(1);
}

void	draw_path(t_cell *path,t_screen *s) 
{
	if (!path)
		return ;
	int s_x = (path->x) * CELL_LENGHT + WIDTH/2  + CELL_LENGHT/2 - 200;
	int s_y = (path->y) * CELL_LENGHT + HEIGHT/2 + CELL_LENGHT/2 - 200;

	int e_x,e_y;

	path = path->next;
	while (path)
	{
		e_x = (path->x) * CELL_LENGHT + WIDTH/2  + CELL_LENGHT/2 - 200;
		e_y = (path->y) * CELL_LENGHT + HEIGHT/2 + CELL_LENGHT/2 - 200;
		draw_line_dda(s_x,s_y,e_x,e_y,s->image_s);
		mlx_put_image_to_window(s->connection,s->window,s->image_s->img,0,0);
		usleep(1 * 80000);
		path = path->next;
		s_x = e_x;
		s_y = e_y;
	}
}

void	draw_line_dda(float s_x, float s_y, float e_x, float e_y, t_image *image) 
{
	// Getting absolute distance between endpoints 
	float dx = abs(e_x - s_x);
	float dy = abs(e_y - s_y);

	// Defining maximum steps 
	float steps = dx > dy ? dx : dy;

	// Getting steps for x and y
	float step_x = (e_x - s_x) / steps;
	float step_y = (e_y - s_y) / steps;

	// The drawing
	my_pixel_put(s_y,s_x,image,0xff0000);
	for (int i = 0; i < 7; i++) {
		my_pixel_put(s_y,s_x + i,image,0xff0000);
		my_pixel_put(s_y,s_x - i,image,0xff0000);
		my_pixel_put(s_y + i,s_x,image,0xff0000);
		my_pixel_put(s_y - i,s_x,image,0xff0000);
	}
	while (steps > 0)
	{
		my_pixel_put(s_y,s_x,image,0xff0000);
		my_pixel_put(s_y,s_x - 1,image,0xff0000);
		my_pixel_put(s_y,s_x + 1,image,0xff0000);
		s_x += step_x;
		s_y += step_y;
		steps--;
	}
}