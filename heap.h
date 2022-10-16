#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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

private:
  /// Add whatever helper functions and data members you need below

  // will need an item member that will store the data within the
  // heap and then will need to do the appropriate actions on data member
  // should be a vector
  int ary_; // this is the how many children heap has 
  int size_ = 0; // this is useful with array stored heap
  std::vector<std::pair<T, int>> heap; // int is the priority while t is item
  Comparator compareItems;
  void trickleUp(int currIndex);
  void trickleDown(int currIndex, int endIndex);
  int findBestChildIndex(int currIndex, int endIndex);
  
  // need to implement trickle up that would work for heapify and also 
  // could possibly need trickle down for it 



};

// Add implementation of member functions here

// heap constructor 
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m=2, PComparator c = PComparator()) : compareItems(c) {
  // we need to do something with this comparator as it will be the 
  // key in determining if the heap will be a max or min heap/=
  // check c and evaluate it. The comparator is fueled by the less in std
  ary_ = m > 2 ? m : 2;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  // push the item to the last available position and from there need to 
  // perform a trickle up and see if heap satisfies the properties
  heap.push_back(item);
  size_++;
  // call the trickleUp on the last item
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return size_ == 0;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int currIndex) {
  int parentIndex = (currIndex - 1) / ary_;
  while (currIndex > 0 && compareItems(head[currIndex], head[parentIndex])) {
    std::swap(heap[currIndex], head[parentIndex]);
    currIndex = parentIndex;
    parentIndex = (currIndex - 1) / ary_;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int currIndex, int endIndex) {
  int firstChildIndex = currIndex * ary_ + 1;
  int bestIndex = findBestChildIndex(currIndex, endIndex); // returns the best index to swap
  // check to ensure that the items should be swapped 
  if (compareItems(heap[currIndex], heap[bestIndex])) {
    std::swap(heap[currIndex], heap[bestIndex]);
  }
  while (firstChildIndex <= endIndex) {
    int nextIndex = currIndex * ary_ + 2;
    int nextChildIndex = nextIndex <= endIndex ? nextIndex : -1;
    int indexToSwap;
    if (nextChildIndex != -1 && compareItems(heap[nextChildIndex], heap[firstChildIndex])) {
        indexToSwap = firstChildIndex;
    }
    else if (nextChildIndex != -1 && !compareItems(heap[nextChildIndex], heap[firstChildIndex])) {
      indexToSwap = nextChildIndex;
    }
  }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return size_;
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::exception("Cannot top empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0].first; // should this be arrow or period dereferencer?
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::exception("Cannot pop empty heap");
  }
  // we need to lose the first element in the vector 
  // and the size need to decrement as well
  heap[0] = heap[size - 1];
  // get rid of the last element so we arent double counting
  heap.pop_back();
  size--;
  // call trickle down on the first element of the heap since is new
  trickleDown(0);
}

template <typename T, typename PComparator>
int Heap<T,PComparator>::findBestChildIndex(int currIndex, int endIndex) {
  int smallestChild = currIndex * ary_ + 1;
  int indexToSwap = smallestChild;
  int childCounter = 1;
  while (smallestChild < size_) {
    if (childCounter > ary_) {
      break; // ensures function only deals with valid children
    }
    int currentChildIndex = indexToSwap + childCounter;
    if (compareItems(heap[currentChildIndex], heap[smallestChild])) {
      indexToSwap = currentChildIndex;
    }


  }
  return -1;
}



#endif

