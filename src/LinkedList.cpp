#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>

/**
 * Linked List constructor.
 *
 * Sets head to null on construct.
 */
LinkedList::LinkedList() { head = nullptr; };

/**
 * Append node method.
 *
 * Append a new node to the end of the list.
 * @param data Data (int) for the new node.
 */
void LinkedList::append(int data) {

  Node *newNode = new Node(data);

  if (head == nullptr) {
    head = newNode;
    head->data = data;
    return;
  }

  Node *currentNode = head;
  while (currentNode->next != nullptr) {
    currentNode = currentNode->next;
  }

  (*currentNode).next = newNode;

  return;
};

/**
 * Print method for the list.
 *
 * Prints every node on the list with space as separator.
 */
void LinkedList::print() {
  Node *currentNode = head;

  while (currentNode != nullptr) {
    std::cout << currentNode->data << " ";
    currentNode = currentNode->next;
  }

  std::cout << std::endl;

  return;
};

/**
 * Delete node method.
 *
 * Delete a node on the desired index.
 * @param index Index of the node that will be deleted.
 */
void LinkedList::deleteAt(int index) {

  if (head == nullptr) {
    throw std::logic_error("[ERROR] List is empty!");
  }

  if (index == 0) {
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
  }

  int currentIndex = 0;

  Node *currentNode = head;
  Node *beforeNode = nullptr;

  while (currentNode != nullptr) {

    // 0 index pos
    if (currentIndex == index) {
      beforeNode->next = currentNode->next;
      delete currentNode;
      return;
    }

    currentIndex++;
    beforeNode = currentNode;
    currentNode = currentNode->next;
  }

  throw std::invalid_argument("[ERROR] Index out of range!");
};

/**
 * Insert node method.
 *
 * Insert a new node to the desired index.
 * @param index Index for the new node.
 * @param data Data (int) for the new node.
 */
void LinkedList::insertAt(int index, int data) {

  Node *newNode = new Node(data);

  if (index == 0) {
    newNode->next = head;
    head = newNode;
    return;
  }

  int currentIndex = 0;

  Node *currentNode = head;

  while (currentNode != nullptr) {
    if (currentIndex == index - 1) {
      newNode->next = currentNode->next;
      currentNode->next = newNode;
      return;
    }

    currentIndex++;
    currentNode = currentNode->next;
  }

  throw std::invalid_argument("[ERROR] Index out of range!");
};

/**
 * At method for the list.
 *
 * Get node value at specific index.
 * @param index Index of the node.
 */
int LinkedList::at(int index) {

  int currentIndex = 0;

  Node *currentNode = head;

  while (currentNode != nullptr) {
    if (currentIndex == index) {
      return currentNode->data;
    }
    currentIndex++;
    currentNode = currentNode->next;
  }

  throw std::invalid_argument("[ERROR] Index out of range!");
};

/**
 * Subscripting operator.
 *
 * Overloading the subscript operator for node accessing of the list using
 * index.
 * @param index Index of the node.
 */
int LinkedList::operator[](int index) { return this->at(index); }

LinkedList::~LinkedList() {

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
