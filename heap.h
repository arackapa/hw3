#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 
#include <iostream> 

using namespace std; 

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void printHeap();

private:
  /// Add whatever helper functions and data members you need below
  typename std::vector<T> data; 
  size_t datasize;
  int mary; 
  PComparator comparison; 
  void TrickleDown();
  void TrickleUp(); 
   
};

// Add implementation of member functions here

template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c) 
{
  // initialize members
  datasize = 0; 
  mary = m; 
  comparison = c; 
}

template <typename T, typename Comparator>
Heap<T,Comparator>::~Heap()
{

};

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    throw std::underflow_error("The heap is empty.");
    // ================================
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
    return data.std::vector<T>::front(); 
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
        throw std::underflow_error("The heap is empty.");
    // ================================
  }
  // for pop, we remove top element, put last element in the place 
  data[0] = data.std::vector<T>::back();
  data.std::vector<T>::pop_back(); 
  TrickleDown(); 
  datasize--; 
  // make index 0 = vector.back() 
  // vector.pop back to remove that vector 
  // then do trickle down 
  // we have index 0, do formula (i*m) + 1 to (i*m) + m 
  // look at which is smallester or largest depending on comparator 
  // then start again from the top with this new index 
  // go until we begin searching out of bounds 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  // for push, we place element at the very back, then we compare with parent until we get to the top 
  // so to get parent we do (i-1)/m 
  // do this until the index we are searching for is too much or when comparison stops 
  data.std::vector<T>::push_back(item); 
  TrickleUp(); 
  datasize++; 
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return datasize == 0; 
};

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return datasize; 
};

template <typename T, typename PComparator>
void Heap<T,PComparator>::TrickleDown(){
  unsigned int parentIndex = 0; 
  unsigned int childStartIndex = parentIndex * mary + 1; 
  unsigned int childEndIndex = parentIndex * mary + mary; 
  unsigned int currentIndex = childStartIndex; 

  while (currentIndex < datasize)
  {
     
    // cout << "START OF LOOP CURRENT INDEX = " << currentIndex << endl; 
    T bestFit = data[currentIndex];
    unsigned int bestIndex = currentIndex; 
    while (currentIndex < datasize && currentIndex <= childEndIndex)
    {
      if(comparison(data[currentIndex], bestFit))
      {
        bestFit = data[currentIndex]; 
        bestIndex = currentIndex; 
      }
      currentIndex++; 
    }

    // cout << "Best Fit from Comparison: " << bestFit << endl;
    // cout << "Parent we are looking at: " << data[parentIndex] << endl; 
    // now we have the best fit of the children, now its time to swap
    if (comparison(bestFit, data[parentIndex]))
    {
      T temp = data[parentIndex];
      data[parentIndex] = data[bestIndex]; 
      data[bestIndex] = temp;
      parentIndex = bestIndex; 
    }
    else
    {
      // cout << "BREAKING" << endl; 
      break; 
    }
    childStartIndex = parentIndex * mary + 1; 
    childEndIndex = parentIndex * mary + mary;  
    currentIndex = childStartIndex;
  }
};

template <typename T, typename PComparator>
void Heap<T,PComparator>::TrickleUp(){
  // only have to look at parent node 
  int currentIndex = datasize; 
  int parent; 
  while (currentIndex != 0)
  {
    parent = (currentIndex - 1 ) / mary; 
    if (parent < 0) parent = 0; 

    if (comparison(data[currentIndex], data[parent]))
    {
      T temp = data[parent];
      data[parent] = data[currentIndex];
      data[currentIndex] = temp; 
      currentIndex = parent;   
    }
    else
    {
      break; 
    }
  }
}; 

template <typename T, typename PComparator>
void Heap<T,PComparator>::printHeap(){
  for (unsigned int i = 0; i < datasize; i++)
  {
    cout << data[i] << " "; 
  }
  cout << endl; 
};


#endif

