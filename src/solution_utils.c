#include "nkg.h"

bool	can_visited_by_one(t_board *b)
{
	int m = b->v_size < b->h_size ? b->v_size : b->h_size;
	int n = b->v_size > b->h_size ? b->v_size : b->h_size;
	
	if (m <= 2)
		return false;
	if (m == 3 && (n == 4 || n == 6 || n == 8))
		return false;
	if (m == 4 && n == 4)
		return false;
	return true;
}

void	print_path(t_cell *path) 
{
	printf("adhkhdak");
	while (path)
	{
		printf("%d %d \n",path->y,path->x);
		path = path->next;
	}	
}