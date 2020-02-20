/*
Jason Zhang
Shunting Yard
2/20/2020
*/
#include <iostream>
#include <cstring>
#include "Node.h"
#ifndef LIST_H
#define LIST_H

using namespace std;

class List{
 public:
  List();
  //push node
  void push(char*);
  //pop node from stack
  char* s_pop();
  //pop node from 
  char* q_pop();
  //peek node from queue
  char* s_peek();
  //peek node from stack
  char* q_peek();
  //push node
  void pushNode(Node*);
  //peek node
  Node* peek_node();
  //get the end val
  char* get_end(Node*&, bool);
  //push to end
  void push_end(Node*&, char*, Node*, bool);
  //get end node
  Node* getEndNode(Node*&);
  //get a copy of a char*
  char* copy(char*);
  //deconstructor
  ~List();
 private:
  //head
  Node* head;
};
#endif
