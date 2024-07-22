#include <iostream>
#include <stdexcept>

#include "Node.h"
#include "Stack.h"

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
  Node *newNode = new Node(data);

  if (newNode == nullptr) {
    throw std::runtime_error("[ERROR] Memory is full!");
  }

  if (head == nullptr) {
    head = newNode;
    return;
  }

  newNode->next = head;

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

  Node *tempNode = head;

  head = head->next;

  delete tempNode;

  return;
};

/**
 * Stack print method.
 *
 * Prints every node on the stack with space as separator.
 */
void Stack::print() {

  Node *currentNode = head;

  while (currentNode != nullptr) {
    std::cout << currentNode->data << " ";
    currentNode = currentNode->next;
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

  Node *currentNode = head;

  while (currentNode != nullptr) {
    Node *temp = currentNode;
    currentNode = currentNode->next;
    delete temp;
  }

  return;
}
