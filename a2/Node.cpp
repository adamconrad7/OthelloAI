#include "Node.h"
#include <iostream>
//
// using std::vector;
// using std::pair;

Node::Node(OthelloBoard* _b, pair<int, int> _moves,  int _utility, bool _turn, Node* _parent, vector<Node*> _children): b(_b), moves(_moves), utility(_utility), turn(_turn), parent(_parent), children(_children){

}

Node::Node(OthelloBoard* _b, pair<int, int> _moves,  int _utility, bool _turn, Node* _parent): b(_b), moves(_moves), utility(_utility), turn(_turn), parent(_parent){
  // vector<Node*> kids;
  children = {};

}

void Node::set_children(vector<Node*> rhs){
  children = rhs;
}


void Node::print_node(){
  std::cout<<"Printing node:{"<<std::endl;
  // std::cout<<"{"<<std::endl;
  std::cout << "Move: "<<moves.second<<", "<<moves.first<< '\n';
  std::cout << "Utility: "<<utility << '\n';
  std::cout << "Turn: "<<turn << '\n';

  std::cout << "Parent: "<<parent<< '\n';

  b->display();
  std::cout<<"}"<<std::endl;
  std::cout<<'\n'<<std::endl;

}

bool Node::has_children(){
  return !children.empty();
}
//
// Player::Player(char symb) : symbol(symb) {
//
// }
