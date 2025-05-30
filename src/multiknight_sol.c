#include "nkg.h"

int moves[8][3] = {{-1,2,0},{-1,-2,0},{-2,-1,0},{-2,1,0},{1,-2,0},{1,2,0},{2,1,0},{2,-1,0}};

static int moves_for_fill(t_board *b) 
{
	int moves = 0;
	for (int i = 0; i < b->v_size; i++) {
		for (int j = 0; j < b->h_size; j++) {
			if (!b->cells[i][j])
				moves++;
		}	
	}
	return moves;
}

// If the current knight can cover the remaining part of board
t_cell  *can_fill_by_itself(int needed, t_board *b) 
{
	t_cell *path;
	// Checking from every free position in board if the knight can cover it with one exact move 
	for (int i = 0; i < b->v_size; i++) {
		for (int j = 0; j < b->h_size; j++) {
			// If we got free cell
			if (!b->cells[i][j])
			{
				// Getting path
				path = solve_for_one(b,i,j,0,needed);
				if (path)
					return path;
			}
		}	
	}
	// Cant fill by itself
	return NULL;
}

t_cell **choose_optimal_path(t_cell **paths,int size, t_board *b,t_knight *current, t_knight **knights)
{
	// For first checking if current knight can fill remained board (if yes returning the path)
	int		needed = moves_for_fill(b) - 1;
	t_cell *path = can_fill_by_itself(needed,b);

	print_path(path);
	// if no getting the optimal path remained for others
}