#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack {
private:
  Node *head;

public:
  Stack();

  void push(int data);

  void pop();

  void print();

  int top();

  ~Stack();
};

#endif
