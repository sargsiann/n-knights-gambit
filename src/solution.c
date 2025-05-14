#include "nkg.h"

// FUNCTION FOR CHOSEING PROBABLY SAFIER POSITIONS 
void	choose_positions(t_board *board, t_knight *knights) 
{

}

// FUNCTION FOR MOVEING KNIGHT DEPENDS ON WARNSDORF STRATEGY

void	move_knight(t_board *board, t_knight *knight, int move[2]) 
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

int	optimal_move(int v_pos,int h_pos, int moves[8][2], t_board *board)
{
	int min_index = 0;
	int min_count = 0;

	for (int i = 0; i < 8; i++) {
		if (h_pos + moves[i][1] < 0 || moves[i][1] + h_pos >= board->h_size 
			|| v_pos + moves[i][0] < 0 || v_pos + moves[i][0] >= board->v_size)
			continue;
		int count = possible_moves(board,h_pos + moves[i][1],v_pos + moves[i][0]);

		if (count < min_count || min_count == 0) {
			min_count = count;
			min_index = i;
		}
	}
	return min_index;
}

// FUNC FOR CHECKING IF KNIGHT OR KNIGHTS REACHED AMOUT OF MOVES NEEDED
bool	check_finish();

void	solution(t_board *board, t_screen *screen) 
{
	t_knight **head = safe_malloc(sizeof(t_knight *));
	t_knight *first_knight = safe_malloc(sizeof(t_knight));
	int moves[8][2] = {{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2},{1,2},{2,1},{2,-1}};

	first_knight->h_pos = 0;
	first_knight->v_pos = 0;
	first_knight->next = NULL;

	board->cells[first_knight->v_pos][first_knight->h_pos] = true;
	for (int i = 0;i < board->v_size; i++) {	
		for (int j = 0;j < board->h_size; j++) {
			
		}
	}
	*head = first_knight;
}