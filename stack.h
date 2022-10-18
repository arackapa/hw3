#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream> 

using namespace std; 

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
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
    typename std::vector<T> data; 
    size_t datasize; 
};

template<typename T>
Stack<T>::Stack(){
    datasize = 0; 
}; 

template<typename T>
Stack<T>::~Stack(){

}; 

template<typename T>
bool Stack<T>::empty() const {
    if (data.std::vector<T>::size() > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}; 

template<typename T>
size_t Stack<T>::size() const {
    return datasize; 
};

template<typename T>
void Stack<T>::push(const T& item){
    data.std::vector<T>::push_back(item); 
    datasize++; 
}; 

template<typename T>
void Stack<T>::pop(){
  // throw error if stack is empty 
  if (datasize == 0)
  {
    throw std::underflow_error("The stack is empty."); 
  }
  // use vector functionality and adjust size accordingly 
  data.std::vector<T>::pop_back(); 
  datasize--; 
}; 

template<typename T>
const T& Stack<T>::top() const {
  // throw error if stack is empty 
  if (datasize == 0)
  {
    throw std::underflow_error("The stack is empty."); 
  }
  return data.std::vector<T>::back(); 
};

#endif