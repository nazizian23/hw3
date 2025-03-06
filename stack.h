#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack:public std::vector<T> 
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
};

//Default constructor
template<typename T>
Stack<T>::Stack(){

}
//Destructor
template<typename T>
Stack<T>::~Stack(){

}
//checks if stack empty 
template<typename T>
bool Stack<T>::empty() const{

    return std::vector<T>::empty();//return vectors empty status
}
//get the size of the stack
template<typename T>
size_t Stack<T>::size() const{

    return std::vector<T>::size();//Return vector size
}
//Push item onto stack
template<typename T>
void Stack<T>::push(const T& item){

    std::vector<T>::push_back(item);//add item to vector end
}
//Pop top item from stack
template<typename T>
void Stack<T>::pop(){
    if(empty()){
        throw std::underflow_error("Stack pop on empty stack");//throw if empty

    }
    std::vector<T>::pop_back();//remove last vector element

    
}

//Get top item
template<typename T>
const T& Stack<T>::top() const{
    if(empty()){
        throw std::underflow_error("Stack top on empty stack");//Throw if empty
    }
    return std::vector<T>::back();//Return last vector element

    
}







#endif