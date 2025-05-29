#include "nkg.h"
// FUNCTION FOR MOVEING KNIGHT DEPENDS ON WARNSDORF STRATEGY

void	move_knight(t_board *board, t_knight *knight, int move[3]) 
{
	knight->h_pos += move[1];
	knight->v_pos += move[0];
	board->cells[knight->v_pos][knight->h_pos] = true;
}

// FINDING FURTHER POSSIBLE MOVES OF POSITION
short	possible_moves(t_board *board, int h_pos, int v_pos) 
{
	short c = 0;

	if (h_pos - 2 >= 0) 
	{
		if (v_pos - 1 >= 0 && board->cells[v_pos - 1][h_pos - 2] == false) 
			c++;
		if (v_pos + 1 < board->v_size && board->cells[v_pos + 1][h_pos - 2] == false)
			c++;
	}
	if (h_pos + 2 < board->h_size) 
	{
		if (v_pos - 1 >= 0 && board->cells[v_pos - 1][h_pos + 2] == false) 
			c++;
		if (v_pos + 1 < board->v_size && board->cells[v_pos + 1][h_pos + 2] == false)
			c++;
	} 
	if (v_pos - 2 >= 0) 
	{
		if (h_pos - 1 >= 0 && board->cells[v_pos - 2][h_pos - 1] == false) 
			c++;
		if (h_pos + 1 < board->h_size && board->cells[v_pos - 2][h_pos + 1] == false)
			c++;
	}
	if (v_pos + 2 < board->v_size) 
	{
		if (h_pos - 1 >= 0 && board->cells[v_pos + 2][h_pos - 1] == false) 
			c++;
		if (h_pos + 1 < board->h_size && board->cells[v_pos + 2][h_pos + 1] == false)
			c++;
	}
	return c;
}

int	optimal_move(int v_pos,int h_pos, int moves[8][3], t_board *board, bool checked[8])
{
	int min_index = -1;
	int min_count = 0;
	int s_v;
	int s_h;
	bool **cells = board->cells;

	for (int i = 0; i < 8; i++) {
		// Getting the steps
		s_v = moves[i][0];s_h = moves[i][1];
		// It means checked that way
		if (checked[i] == 1)
			continue;
		// Getting out of bounds
		if (h_pos + moves[i][1] < 0 || moves[i][1] + h_pos >= board->h_size 
			|| v_pos + moves[i][0] < 0 || v_pos + moves[i][0] >= board->v_size)
			continue;
		if (cells[v_pos + s_v][h_pos + s_h] == true)
			continue;
		// selecting less possible moves to move
		int count = possible_moves(board,h_pos + moves[i][1],v_pos + moves[i][0]);
		if (count < min_count || min_count == 0) {
			min_count = count;
			min_index = i;
		}
	}
	return min_index;
}


t_cell *main_solution(t_board *board) 
{

}

// Solution is for open tour not closed
t_cell *solve_for_one(t_board *board, int moves[8][3], int v_pos, int h_pos, int counter) 
{
	// Initing part of path
	t_cell *path = malloc(sizeof(t_cell ));
	path->next = NULL;
	path->y = v_pos;
	path->x = h_pos;

	// Array of checked direction to avoid multi checking the same way
	bool checked[8] = {0,0,0,0,0,0,0,0};
	
	// Getting the board by bool
	bool **cells = board->cells;

	// Matching true for future checking avoiding moveing the visited place
	cells[v_pos][h_pos] = true;

	// If we got all fields filled
	if (counter == (board->h_size * board->v_size) - 1)
		return path;

	printf("%d%d\n",v_pos,h_pos);
	// Getting index each time for backtracking case
	while (1)
	{
		// Getting the index of optimal move
		int index = optimal_move(v_pos, h_pos, moves, board, checked);

		// If there is no possible moves from that cell (tupik) returning NULL for backtrack for one lvl higher 
		// It is less possible because we use warnsdorff heruistic for this 
		// So the algorithm will not last too long in
		if (index == -1)
		{
			cells[v_pos][h_pos] = false;
			free(path);
			return NULL;
		}
		
		// Getting the next positions
		int n_h = h_pos + moves[index][1];
		int n_v = v_pos + moves[index][0];

		// Matching that path selected to avoid infinite selecting
		
		// Recursive calling
		path->next = solve_for_one(board,moves,n_v,n_h,++counter);

		if (path->next != NULL)
			return path;
	}
	return path;
}

void	solution(t_board *board, t_screen *screen) 
{
	t_knight **head = safe_malloc(sizeof(t_knight *));
	t_knight *first_knight = safe_malloc(sizeof(t_knight));
	
	// ADDING FLAG FOR CHECKED ROUTES NOT TRY IN SITUATION OF BACKTRACK (GOING FROM LESS POSSIBLE TO MOST BY WARNSDORF)
	// {MOVE_VERTICAL, MOVE_HORIZONTAL, CHECKED THAT_WAY}

	int moves[8][3] = {{-1,2,0},{-1,-2,0},{-2,-1,0},{-2,1,0},{1,-2,0},{1,2,0},{2,1,0},{2,-1,0}};

	// This just checking for one
	if (can_visited_by_one(board) == true)
	{
		// If it is solving
		t_cell *path = solve_for_one(board, moves,0,0,0);
		
		// getting path for drawing ...draw_path;
		
		
		return;
	}

	// Part for multiple knights checking
	first_knight->h_pos = 0;
	first_knight->v_pos = 0;
	first_knight->next = NULL;

	board->cells[first_knight->v_pos][first_knight->h_pos] = true;
	// int n = optimal_move(0,0,moves,board);

	*head = first_knight;
}