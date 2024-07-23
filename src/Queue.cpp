#include <iostream>
#include <stdexcept>

#include "Queue.h"

/**
 * QueueNode constructor.
 *
 * Sets data to newData, prev and next pointer to null.
 * @param newData Data for the node(int).
 */
QueueNode::QueueNode(int newData) {
  data = newData;
  prev = nullptr;
  next = nullptr;
};

/**
 * Queue constructor.
 *
 * Sets head and tail pointer to null.
 */
Queue::Queue() {
  head = nullptr;
  tail = nullptr;
};

/**
 * Push method for the queue.
 *
 * Push a new node to the tail of the queue.
 * @param data Data for the new node.
 */
void Queue::push(int data) {

  QueueNode *newNode = new QueueNode(data);

  if (head == nullptr && tail == nullptr) {
    head = newNode;
    tail = newNode;

    head->next = tail;
    tail->prev = head;
    return;
  }

  newNode->prev = tail;
  tail->next = newNode;

  tail = newNode;
};

/**
 * Pop method for the queue.
 *
 * Pop the head from the queue.
 */
void Queue::pop() {
  if (head == nullptr) {
    throw std::logic_error("[ERROR] Queue is empty!");
  }

  QueueNode *currentNode = head;
  head = head->next;

  delete currentNode;
};

/**
 * Print method for the queue.
 *
 * Prints every node on the queue with space as separator.
 */
void Queue::print() {
  QueueNode *currentNode = head;

  while (currentNode != nullptr) {
    std::cout << currentNode->data << " ";
    currentNode = currentNode->next;
  }
  std::cout << std::endl;
};

/**
 * Access head of the queue.
 *
 * Returns data from the head of the queue.
 */
int Queue::front() {
  if (head == nullptr) {
    throw std::logic_error("[ERROR] Queue is empty!");
  }

  return head->data;
};

/**
 * Access tail of the queue.
 *
 * Returns data from the tail of the queue.
 */
int Queue::back() {
  if (tail == nullptr) {
    throw std::logic_error("[ERROR] Queue is empty!");
  }

  return tail->data;
};

Queue::~Queue() {
  std::cout << "Queue destructor" << std::endl;

  QueueNode *currentNode = head;

  while (currentNode != nullptr) {
    QueueNode *temp = currentNode;
    currentNode = currentNode->next;
    delete temp;
  }
};
