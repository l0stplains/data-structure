#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct LinkedListNode {
  int data;
  LinkedListNode *next;
  // Constructors
  LinkedListNode();
  LinkedListNode(int newData);
};

class LinkedList {
private:
  LinkedListNode *head;

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
