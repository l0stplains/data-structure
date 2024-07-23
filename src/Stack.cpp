#include <iostream>
#include <stdexcept>

#include "Stack.h"

/**
 * StackNode constructor.
 *
 * Sets data to newData and prev pointer to null.
 * @param newData Data for the node(int).
 */
StackNode::StackNode(int newData) {
  data = newData;
  prev = nullptr;
}

/**
 * Stack constructor.
 *
 * Sets head to null on construct.
 */
Stack::Stack() { head = nullptr; }

/**
 * Stack push method.
 *
 * Push a new node to the stack with data as param.
 * @param data Data of the new pushed node.
 */
void Stack::push(int data) {
  StackNode *newNode = new StackNode(data);

  if (newNode == nullptr) {
    throw std::runtime_error("[ERROR] Memory is full!");
  }

  if (head == nullptr) {
    head = newNode;
    return;
  }

  newNode->prev = head;

  head = newNode;

  return;
};

/**
 * Stack pop method.
 *
 * Pop a node from the top of the stack.
 */
void Stack::pop() {

  if (head == nullptr) {
    throw std::logic_error("[ERROR] Stack is empty!");
  }

  StackNode *tempNode = head;

  head = head->prev;

  delete tempNode;

  return;
};

/**
 * Stack print method.
 *
 * Prints every node on the stack with space as separator.
 */
void Stack::print() {

  StackNode *currentNode = head;

  while (currentNode != nullptr) {
    std::cout << currentNode->data << " ";
    currentNode = currentNode->prev;
  }

  std::cout << std::endl;
}

/**
 * Stack top method.
 *
 * Return the data of the top node on the stack.
 */
int Stack::top() { return head->data; }

Stack::~Stack() {

  if (head == nullptr) {
    return;
  }

  StackNode *currentNode = head;

  while (currentNode != nullptr) {
    StackNode *temp = currentNode;
    currentNode = currentNode->prev;
    delete temp;
  }

  return;
}
