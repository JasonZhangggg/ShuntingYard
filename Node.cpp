/*
Jason Zhang
Shunting Yard
2/20/2020
*/

#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

//Constructor
Node::Node(char* newVal) {
  val = new char[strlen(newVal)+1];
  strcpy(val, newVal);
  next = NULL;
  right = NULL;
  left = NULL;
}

//get val of node
char* Node:: getVal(){
  return val;
}
//set next val of node
void Node::setNext(Node* newNext){
  next = newNext;
}

//get the next val of node
Node* Node::getNext(){
  return next;
}

//next 4 functions are used for the binary expression tree
//set right. 
void Node::setRight(Node* newRight){
  right = newRight;
}
//get right
Node* Node::getRight(){
  return right;
}
//set left
void Node::setLeft(Node* newLeft){
  left = newLeft;
}
//get left
Node* Node::getLeft(){
  return left;
}

//deconstructor
Node::~Node(){
  delete[] val;
  next = NULL;
}
