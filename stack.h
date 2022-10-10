#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector <typename T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
    std::vector <typename T> items;
};

template <typename T>
bool Stack<T>::empty() const {
  // check if empty
  if (items.empty()) {
    return true;
  }
  else {
    return false;
  }
}

template <typename T>
size_t Stack<T>::size() const {
  // return the size of stack ie vector
}

template <typename T>
void Stack<T>::pop() {
  // check if empty before popping if empty then 
  // I should throw std::underflow_error
}

template <typename T>
const T& Stack<T>::top() const {
  // if empty throws std::underflow_error
  // else do othershit
  return 
}


#endif