
#ifndef NODE_H
#define NODE_H

struct Node {

  int data;

  Node* left;
  Node* right;
  Node* parent;

  Node() {}

  Node(int in_data) : data(in_data) {} 

};

#endif 
