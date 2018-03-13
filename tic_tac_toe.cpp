#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
#define XP 1
#define OP 0
#define DRAW 2

struct game
{
	int alpha =  -INF, beta = INF;
	string board =  "---------";
	int active_turn = XP;
	int win = -5;
	
};

game choice;

int score(game g)
{
	if(g.win == XP)
		return 10;
	else if(g.win == OP)
		return -10;
	else
		return 0;

}

bool terminal(game & g)
{
	/*
		|0|1|2|
		|3|4|5|
		|6|7|8|

		checking if someone win or draw
		terminal tested and works fine

	*/
	if(g.board[0] == 'X' && g.board[1] == 'X' && g.board[2] == 'X')
	{
		g.win = XP;
		return true;
	}else if(g.board[0] == 'O' && g.board[1] == 'O' && g.board[2] == 'O')
	{
		g.win = OP;
		return true;
	}

	if(g.board[3] == 'X' && g.board[4] == 'X' && g.board[5] == 'X')
	{
		g.win = XP;
		return true;
	}else if(g.board[3] == 'O' && g.board[4] == 'O' && g.board[5] == 'O')
	{
		g.win = OP;
		return true;
	}

	if(g.board[6] == 'X' && g.board[7] == 'X' && g.board[8] == 'X')
	{
		g.win = XP;
		return true;
	}else if(g.board[6] == 'O' && g.board[7] == 'O' && g.board[8] == 'O')
	{
		g.win = OP;
		return true;
	}

	if(g.board[0] == 'X' && g.board[3] == 'X' && g.board[6] == 'X')
	{
		g.win = XP;
		return true;
	}else if(g.board[0] == 'O' && g.board[3] == 'O' && g.board[6] == 'O')
	{
		g.win = OP;
		return true;
	}

	if(g.board[1] == 'X' && g.board[4] == 'X' && g.board[7] == 'X')
	{
		cout << "hello" << endl;
		g.win = XP;
		return true;
	}else if(g.board[1] == 'O' && g.board[4] == 'O' && g.board[7] == 'O')
	{
		g.win = OP;
		return true;
	}

	if(g.board[2] == 'X' && g.board[5] == 'X' && g.board[8] == 'X')
	{
		g.win = XP;
		return true;
	}else if(g.board[2] == 'O' && g.board[5] == 'O' && g.board[8] == 'O')
	{
		g.win = OP;
		return true;
	}

	//for diagonal check
	if(g.board[0] == 'X' && g.board[4] == 'X' && g.board[8] == 'X')
	{
		g.win = XP;
		return true;
	}else if(g.board[0] == 'O' && g.board[4] == 'O' && g.board[8] == 'O')
	{
		g.win = OP;
		return true;
	}

	if(g.board[2] == 'X' && g.board[4] == 'X' && g.board[6] == 'X')
	{
		g.win = XP;
		return true;
	}else if(g.board[2] == 'O' && g.board[4] == 'O' && g.board[6] == 'O')
	{
		g.win = OP;
		return true;
	}
	bool full = true;
	for(int i = 0; i < 9; i++)
	{
		if(g.board[i] == '-' )
			full = false;
	}
	if(full)
	{
		g.win = DRAW;
		return full;
	}
	else
		return full;

}

vector<string> get_available_moves(game g)
{
	vector<string> mv;
	string st;
	for(int i = 0; i < 9; i++)
	{
		if(g.board[i] == '-')
		{
			st = g.board;
			if(g.active_turn == XP)
				st[i] = 'X';
			if(g.active_turn == OP)
				st[i] = 'O';
			mv.push_back(st);
		}
	}

	return mv;
}

game get_new_state(int turn, string st)
{
	game ng;
	ng.board = st;
	ng.active_turn = 1 - turn;

	return ng;
}

int min_max(game g)
{
	if(terminal(g))
		return score(g);

	vector<int> scores;
	vector<string> moves = get_available_moves(g);
	for(int i = 0; i < moves.size(); i++)
	{
		game possible_game = get_new_state(g.active_turn,moves[i]);

		scores.push_back(min_max(possible_game));
	}

	//max_score_calculation
	//1 for max player
	if(g.active_turn == 1)
	{
		int max_score_index = distance(scores.begin(), max_element(scores.begin(), scores.end() ));
		game gc;
		gc.board = moves[max_score_index];
		gc.active_turn = 0; 
		choice = gc;
		return scores[max_score_index];
	}else
	{
		//min score calculation
		int min_score_index = distance(scores.begin(), min_element(scores.begin(), scores.end() ));
		game gc;
		gc.board = moves[min_score_index];
		gc.active_turn = 0; 
		choice = gc;
		

		return scores[min_score_index];
	}


}


int main()
{

	game t;
	cin >>t.board ;
	t.active_turn = XP;
	//terminal test
	// cout << terminal(t) << endl;
	// cout << t.win << endl;

	//get available moves
	// vector<string> mvs = get_available_moves(t);

	// for(int i = 0; i < mvs.size() ; i++)
	// {
	// 	cout << mvs[i] << endl;


	// }
	min_max(t);
	cout << choice.board << endl;

	return 0;
}