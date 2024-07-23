#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
  int data;
  QueueNode *prev;
  QueueNode *next;

  /** Constructor */
  QueueNode(int newData);
};

class Queue {
private:
  QueueNode *head;
  QueueNode *tail;

public:
  Queue();

  void push(int data);
  void pop();
  void print();

  int front();
  int back();

  ~Queue();
};

#endif
