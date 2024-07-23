#include <iostream>

#include "Test.h"

int main() {
  std::cout << "Hello world" << std::endl;

  Test test;

  // Test linked list functionality
  test.linkedList();

  // Test stack functionality
  test.stack();

  // Test queue functionality
  test.queue();

  return 0;
}
