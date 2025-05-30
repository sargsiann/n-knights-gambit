#include "nkg.h"

int main(int argc, char **av) 
{
	t_board		*board;
	t_screen	*screen; 
	
	board = init_board(argc,av);
	screen = init_screen();
	draw_board(board,screen);
	solution(board,screen);
	fflush(stdout);
	mlx_loop(screen->connection);	
}