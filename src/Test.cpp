#include <iostream>
#include <stdexcept>

#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "Test.h"

void Test::linkedList() {
  LinkedList list;

  std::cout << "\nPopulating list with 10 data: " << std::endl;
  for (int i = 0; i < 10; i++) {
    list.append(i + 1);
  }

  list.print();

  std::cout << "\nDeleting node at index 0: " << std::endl;
  list.deleteAt(0);

  list.print();

  std::cout << "\nDeleting node at index 8: " << std::endl;
  list.deleteAt(8);

  list.print();

  std::cout << "\nDeleting node at index 5: " << std::endl;
  list.deleteAt(5);

  list.print();

  std::cout << "\nDeleting node at index 10: " << std::endl;
  try {
    list.deleteAt(10);
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\nInsert node at index 3 with 999: " << std::endl;
  list.insertAt(3, 999);

  list.print();

  std::cout << "\nInsert node at index -3 with 123: " << std::endl;
  try {
    list.insertAt(-3, 999);
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\nAccessing node at index 3: " << std::endl;
  std::cout << list.at(3) << std::endl;

  std::cout << "\nAccessing node at index 3 using subscript operator: "
            << std::endl;
  std::cout << list[3] << std::endl;
};

void Test::stack() {

  Stack stack;

  std::cout << "\nInitialize stack with 10 nodes: " << std::endl;
  for (int i = 0; i < 10; i++) {
    stack.push(i + 1);
    stack.print();
  }

  std::cout << "\nPush 999 to the stack: " << std::endl;
  stack.push(999);

  stack.print();

  std::cout << "\nCurrent top: " << std::endl;
  std::cout << stack.top() << std::endl;

  std::cout << "\nPop nodes till empty using while(true): " << std::endl;
  while (true) {
    try {
      stack.pop();
      stack.print();
    } catch (std::logic_error &e) {
      std::cout << e.what() << std::endl;
      break;
    }
  }

  return;
};

void Test::queue() {

  Queue queue;

  std::cout << "Sets queue with 10 node: " << std::endl;
  for (int i = 0; i < 10; i++) {
    queue.push(i + 1);
  }
  queue.print();

  std::cout << "Push 999 to the queue: " << std::endl;
  queue.push(999);

  queue.print();

  std::cout << "Pop the queue: " << std::endl;
  queue.pop();

  queue.print();

  std::cout << "Front element of the queue: " << std::endl;
  std::cout << queue.front() << std::endl;

  std::cout << "Back elemenet of the queue: " << std::endl;
  std::cout << queue.back() << std::endl;

  std::cout << "Emptying the queue using while(true) pop: " << std::endl;
  while (true) {
    try {
      queue.pop();
      queue.print();
    } catch (std::logic_error &e) {
      std::cerr << e.what() << std::endl;
      break;
    }
  }
}
