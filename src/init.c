#include "nkg.h"

t_board	*init_board(int ac, char **av) 
{
	t_board *board;
	board = safe_malloc(sizeof(t_board));

	board->v_size = V_SIZE;
	board->h_size = H_SIZE;
	if (ac == 3) {
		board->v_size = atoi(av[1]) != 0 ? atoi(av[1]) : V_SIZE;
		board->h_size = atoi(av[2]) != 0 ? atoi(av[2]) : H_SIZE;
	}

	board->cells = safe_malloc(sizeof(bool *) * board->v_size);
	for (int i = 0; i < board->v_size; i++) {
		board->cells[i] = safe_malloc(sizeof(bool) * board->h_size);
		for (int j = 0; j < board->h_size; j++) {
			board->cells[i][j] = false;
		}
	}	
	return board;
}

t_screen *init_screen() 
{
	t_screen *sc = safe_malloc(sizeof(t_screen));

	sc->connection = mlx_init();
	sc->window = mlx_new_window(sc->connection,WIDTH,HEIGHT,"N KNIGHTS GAMBIT");
	sc->image_s = safe_malloc(sizeof(t_image));
	sc->image_s->img = mlx_new_image(sc->connection,WIDTH,HEIGHT);
	sc->image_s->address = mlx_get_data_addr(sc->image_s->img,&sc->image_s->bits_p_pixel,&sc->image_s->line_size,&sc->image_s->endian);
	
	return sc;
}
