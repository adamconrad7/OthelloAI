/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include <utility>
#include <climits>
#include "MinimaxPlayer.h"

using std::vector;
using std::pair;


MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb){

}

MinimaxPlayer::~MinimaxPlayer() {

}


//finds valid moves player matching @symbol can make with @board
vector<pair<int, int>> MinimaxPlayer::find_moves(OthelloBoard* b, char sym){
	vector<pair<int, int>> moves;
	for(int i = 0; i<4; i++){
		for(int j=0; j<4; j++){
			if(	b->is_legal_move(i, j, sym) ){
				pair <int, int> move;
				move.first = i;
				move.second = j;
				moves.push_back(move);
			}
		}
	}
	return moves;
};

//returns a vector of the nodes that can be reached from init
vector<Node*>  MinimaxPlayer::succ(Node* init, vector<pair<int, int>> moves){

	vector<Node*> kids;
	char sym;
	init->turn ? sym = 'X' : sym = 'O';
	for(auto m: moves){
		OthelloBoard* nwbord = new OthelloBoard(*init->b); //makes clone of init board
		nwbord->play_move(m.first, m.second, sym);//plays a move
		Node* n = new Node(nwbord, m, init->utility, !init->turn, init);
		kids.push_back(n);
	}
	return kids;
}

//returns minimax value for a given node
int MinimaxPlayer::minimax(Node* init, bool isMax){
	int best;
	char sym;
	char n_sym;

	isMax ? sym = 'X' : sym = 'O';
	isMax ? n_sym = 'O' : n_sym = 'X';

	if(!init->b->has_legal_moves_remaining(sym)){
		//Instead of writing seperate utility function, utility is calculated here
		int mscore = init->b->count_score(sym);
		int oppscore = init->b->count_score(n_sym);
		if(mscore > oppscore){
			return 1;
		}else if(mscore < oppscore){
			return -1;
		}else{
			return 0;
		}
	}
	if(isMax){
		best = INT_MIN;
		vector<pair<int, int>> moves = find_moves(init->b, sym);//find moves that can be made from init
		vector<Node*> children = succ(init, moves);//make new nodes from those moves
		init->set_children(children);//give new nodes to their parent
		for(auto child: init->children){
			best = std::max(best, minimax(child, false));
		}
		return best;
	}else{
		best = INT_MAX;
		vector<pair<int, int>> moves = find_moves(init->b, sym);//find moves that can be made from init
		vector<Node*> children = succ(init, moves);//make new nodes from those moves
		init->set_children(children);//give new nodes to their parent
		for(auto child: init->children){
			best = std::min(best, minimax(child, true));
		}
		return best;
	}
}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row, char sym) {
	pair<int, int> move = {-1,-1};
	Node* root = new Node(b, move, 0, false, NULL);
	int bestScore = INT_MIN;
	int score;
	vector<pair<int, int>> moves = find_moves(b, sym);
	vector<Node*> nodes = succ(root, moves);
	for(auto node: nodes){
		score = minimax(node, false);
		if(score > bestScore){
			bestScore = score;
			move = node->moves;
		}
	}
	col = move.first;
	row = move.second;
}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
