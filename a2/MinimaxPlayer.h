/*
 * MinimaxPlayer.h
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */

#ifndef MINIMAXPLAYER_H
#define MINIMAXPLAYER_H

#include "OthelloBoard.h"
#include "Player.h"
#include "Node.h"
#include <vector>
#include <utility>


using std::vector;
using std::pair;

/**
 * This class represents an AI player that uses the Minimax algorithm to play the game
 * intelligently.
 */
class MinimaxPlayer : public Player {
public:

	/**
	 * @param symb This is the symbol for the minimax player's pieces
	 */
	MinimaxPlayer(char symb);

	/**
	 * Destructor
	 */
	virtual ~MinimaxPlayer();


		// struct node{
		// 	OthelloBoard* b;
		// 	struct node** parent;
		// 	pair<int, int> moves; //moves to make this state from parent
		// 	int utility;
		// };


	/**
	 * @param b The board object for the current state of the board
	 * @param col Holds the return value for the column of the move
	 * @param row Holds the return value for the row of the move
	 */
  void get_move(OthelloBoard* b, int& col, int& row, char c);


    /**
     * @return A copy of the MinimaxPlayer object
     * This is a virtual copy constructor
     */
  MinimaxPlayer* clone();
	vector<pair<int, int>> find_moves(OthelloBoard* b, char sym);
	// vector<OthelloBoard*> succ(vector<pair<int,int>> moves, OthelloBoard* b);
	// vector<Node*>  succ(vector<pair<int, int>> moves, Node* init);
	vector<Node*>  succ(Node* init, vector<pair<int, int>> moves);
	//	Node* build_tree(Node* init);
	void build_tree(Node* init);
	int minimax(Node* n, bool isMax);

	void print_tree(Node* n);
	//
	// bool tree;
	//



//		void step(OthelloBoard* b, char sym);

private:

};


#endif
