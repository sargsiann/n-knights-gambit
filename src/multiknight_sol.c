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
t_cell  *can_fill_by_itself(int needed, t_board *b,t_screen *s) 
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
				
				// If we could solve it returning the path
				if (path)
					return path;
			}
		}	
	}
	// Cant fill by itself
	return NULL;
}


// Wee need to check the connectivity right, the best option can be if remained part will end up covering

bool	check_remained_connectivity(t_board *b) 
{
	int c = 0;

	
}


t_cell *get_op_path_from_pos(int v_pos, int h_pos, t_board *b) 
{

}

/* 
	fucntion for checking the optimal remained path, means 
	maximum connectivity of remained cells for knight move
	and (optional) minimum moves for filling the board
*/

t_cell *get_optimal_path_for_others(t_board *b) 
{
	// TMP will be compared each time w optimal to define whats is the optimal
	t_cell *tmp_path = NULL;
	t_cell *optimal_path = NULL;
	int optimal_connected;
	int tmp_connected;

	// Getting each free position in board
	for (int i = 0; i < b->v_size; i++) {
		for (int j = 0; j < b->v_size; j++) {
			if (b->cells[i][j] == false) 
			{
				// Getting maximum optimal path from that position
				tmp_path = get_op_path_from_pos(i,j,b);

			}
		}
	}
}

t_cell *choose_optimal_path(t_board *b,t_screen *screen)
{
	// For first checking if current knight can fill remained board (if yes returning the path)
	int		needed = moves_for_fill(b);
	t_cell *path = can_fill_by_itself(needed,b,screen);

	// If from this availability we can cover the board
	if (path != NULL)
		return path;

	path = get_optimal_path_for_others(b);
	// if no getting the optimal path remained for others

}