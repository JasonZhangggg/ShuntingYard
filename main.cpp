#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Node.h"
#include "List.h"

using namespace std;

vector<char*>* split(char*);
List* shuntingYard(vector<char*>*);
bool checkDigit(char*);
int getPrec(char*);
int main(){
  char* input = new char();
  cin.getline(input, 80);
  vector<char*>* in = split(input);
  List* postfix = shuntingYard(in);
  while(postfix->s_peek() != NULL){
    cout<<postfix->s_pop()<<endl;
  }
  return 0;
}

vector <char*>* split (char* in){
  vector<char*>* out = new vector<char*>;
  int count = 0;
  char* temp = new char[strlen(in)]();
  for(int i = 0; i<strlen(in); i++){
    if(in[i] == ' '){
      out->push_back(temp);
      count = 0;
      temp = new char[strlen(in)]();
    }
    else{
      temp[count] = in[i];
      count++;
    }
    if(i == strlen(in)-1){
      out->push_back(temp);
    }
  }
  return out;
}

List* shuntingYard(vector<char*>* in){
  List* out_queue = new List();
  List* op_stack = new List();
  vector<char*>::iterator i;
  for(i = in->begin(); i !=in->end();i++){
    char* val = (*i);
    if(checkDigit(val)){
      cout<<"1"<<endl;
      out_queue->push(val);
    }
    else if(strcmp(val, "(") == 0){
      op_stack->push(val);
    }
    else if(strcmp(val, ")") == 0){
      while(strcmp(op_stack->s_peek(), "(") != 0){
	out_queue->push(op_stack->s_pop());
      }
      op_stack->s_pop();
    }
    else{
      cout<<"2"<<endl;
	int c_prec = getPrec(val);
	char* next = op_stack->s_peek();
	int n_prec = getPrec(next);
	cout<<c_prec<<endl;
	cout<<next<<endl;
	while(next && n_prec>c_prec || (n_prec == c_prec && strcmp(next, "^") != 0) && strcmp(next, "(") != 0){
	  out_queue->push(op_stack->s_pop());
	  next = op_stack->s_peek();
	}
	op_stack->push(val);
	cout<<"3"<<endl;
    }
  }
  while(op_stack->s_peek() != NULL){
    out_queue->push(op_stack->s_pop());
  }
  return out_queue;
}

bool checkDigit(char* in){
  for(int i = 0; i<strlen(in);i++){
    if(!isdigit(in[i])){
	return false;
    }
  }
  return true;
}
int getPrec(char* in){
  if(strcmp(in, "+") == 0 || strcmp(in, "-") == 0){
    return 1;
  }
  else if(strcmp(in, "*") == 0 || strcmp(in, "/") == 0){
    return 2;
  }
  else if(strcmp(in, "^") == 0){
    return 3;
  }
  return -1;
}
