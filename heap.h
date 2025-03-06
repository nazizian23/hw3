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
  std::vector<T> data_;//stores heap elements
  int m_;//heap arity
  PComparator comp_;//comparator for priority
  //gets parent index
  size_t parent(size_t index) const {
    return (index-1)/m_;
  }
  //gets first child index
  size_t firstChild(size_t index) const{
    return index*m_+1;
  }
  void heapifyUp(size_t index);//Bubble up new element 
  void heapifyDown(size_t index);// sift down element


};


// Add implementation of member functions here


//constructor
template<typename T,typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): m_(m),comp_(c){
  if(m<2){
    throw std::invalid_argument("Heap arity must be >=2=");// validates arity

  }
}

//Destructor
template<typename T,typename PComparator>
Heap<T,PComparator>::~Heap(){

}

//Push item to heap 
template<typename T,typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data_.push_back(item);//add to end
  heapifyUp(data_.size()-1);//Bubble up

}

//Check if heap is empty
template<typename T,typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data_.empty();

}

//Gets heap size
template<typename T,typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data_.size();

}

//Bubble up element to maintain heap properties
template<typename T,typename PComparator>
void Heap<T,PComparator>::heapifyUp(size_t index){
  while(index>0){
    size_t p_ind=parent(index);
    if(!comp_(data_[p_ind],data_[index])){//If the parent lacks priority, swap with parent and move up
      std::swap(data_[index],data_[p_ind]);
      index=p_ind;
    }
    else{
      break;//Stops when done
    }
  }
}


//Sift down element to maintain heap properties
template<typename T,typename PComparator>
void Heap<T,PComparator>::heapifyDown(size_t index){
  size_t size=data_.size();
  while(firstChild(index)<size){
    size_t best_child=firstChild(index);
    size_t last_child=std::min(firstChild(index)+m_,size);

    for(size_t child=best_child+1;child<last_child;++child){
      if(comp_(data_[child],data_[best_child])){//Find highest priority child
        best_child=child;
      }
    }

    if(comp_(data_[best_child],data_[index])){//If the child has priority, swap with it and move down
      std::swap(data_[index],data_[best_child]);
      index=best_child;

    }
    else{
      break;
    }
  }
  
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
    throw std::underflow_error("Heap top on empty heap");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];//Return the root



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
    throw std::underflow_error("Heap pop on empty heap");



  }
  data_[0]=data_.back();//Replace root with last element
  data_.pop_back();//remove last element

  if(!empty()){
    heapifyDown(0);//sift down new root
  }



}



#endif

