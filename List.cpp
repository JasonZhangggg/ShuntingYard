/*
Jason Zhang
*/
#include <iostream>
#include <cstring>
#include "Node.h"
#include "List.h"

using namespace std;

List::List(char* newVal){
  head = new Node(newVal);
}

void List::push(char* newVal){
  Node* temp = new Node(newVal);
  temp->setNext(head);
  head = temp;
  return;
//  if(head == NULL){
//    head = new Node(newVal);
//    return;
//  }
//  if(head->getNext() == NULL){
//    head->setNext(new Node(newVal));
//    return;
//  }
//  head = head->getNext();
//  push(newVal);
}

char* List::s_pop(){
  if(head == NULL){
    return NULL;
  }
  char* val = copy(head->getVal());
  Node* temp = head->getNext();
  delete head;
  head = temp;
  return val;
}
char* List::q_pop(){
  return get_end(head, true);  
}
char* List::s_peek(){
  return head->getVal();
}
char* List::q_peek(){
  return get_end(head, false);
}
char* List::get_end(Node* &current, bool del){
  if(head == NULL){
    return NULL;
  }
  if(current->getNext() == NULL){
    char* val = copy(current->getVal());
    if(del){
      current = NULL;
      delete current;
    }
    return val;
  }
  if(current->getNext()->getNext() == NULL){
    char* val = copy(current->getNext()->getVal());
    if(del){
      current->setNext(NULL);
      delete current->getNext();
    }
    return val;
  }
  Node* next = current->getNext();
  get_end(next, del);
}
char* List::copy(char* in){
  char* out = new char[strlen(in)+1];
  strcpy(out, in);
  return out;
}
List::~List(){
  delete head;
}