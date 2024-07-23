#ifndef STACK_H
#define STACK_H

struct StackNode {
  int data;
  StackNode *before;
  // Constructors
  StackNode();
  StackNode(int newData);
};

class Stack {
private:
  StackNode *head;

public:
  Stack();

  void push(int data);

  void pop();

  void print();

  int top();

  ~Stack();
};

#endif
