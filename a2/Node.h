#ifndef NODE
#define NODE

#include "OthelloBoard.h"
#include <utility>
#include <vector>



using std::vector;
using std::pair;

class Node{
  public:

    OthelloBoard* b;
    pair<int, int> moves; //moves to make this state from parent
    int utility;
    bool turn;
    Node* parent;
    vector<Node*> children;

    Node(OthelloBoard* b, pair<int, int> moves, int utility, bool turn, Node* parent, vector<Node*> children);
    Node(OthelloBoard* b, pair<int, int> moves, int utility, bool turn, Node* parent);
    void set_children(vector<Node*> rhs);
    bool has_children();

    void print_node();
};

#endif
