#include <iostream>
#include <cstring>
#include "Node.h"
#ifndef LIST_H
#define LIST_H

using namespace std;

class List{
 public:
  List();
  void push(char*);
  char* s_pop();
  char* q_pop();
  char* s_peek();
  char* q_peek();
  char* get_end(Node*&, bool);
  char* copy(char*);
  ~List();
 private:
  Node* head;
};
#endif
