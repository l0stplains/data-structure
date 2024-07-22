#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class LinkedList {
private:
  Node *head;

public:
  LinkedList();

  void append(int data);

  void print();

  void deleteAt(int index);

  void insertAt(int index, int data);

  int at(int index);

  int operator[](int index);

  ~LinkedList();
};

#endif
