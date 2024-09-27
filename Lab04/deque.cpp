#include "deque.h"
#include <iostream>
// Here we include all of the Definitions for all of the member functions of
// deque. The prototype is included in deque.h

// Syntax explanation: we are defining the constructor of the Node struct which
// is a part of the: deque class
// deque(class)::Node(struct)::Node(Constructor)(int cVal, Node *cNode)


Deque::Node::Node(int cVal, Node *cNextNode, Node *cPrevNode) 
{
  val = cVal;
  nextNode = cNextNode;
  prevNode = cPrevNode;
}

// This defines the constructor for the Deque class.
Deque::Deque()
{
  front = nullptr;
  back = nullptr ; 
  size = 0 ;
}
// ALWAYS INITIALIZE POINTERS WITH SOME VALUE!!!

// deque::Node = (return type)
// deque::Node *deque::getTopOfdeque() { return topOfdeque; }

// void deque::setTopOfdeque(Node *n) { topOfdeque = n; }

// Creates a new Node and puts it on the top of the deque
void Deque::push_front(int i) 
{
  Node *newNode = new Node(i, front, nullptr);
  if (front != nullptr) 
  {
    front->prevNode = newNode;
  }
  front = newNode;
  if (back == nullptr) 
  {
    back = newNode;  
  }
    size++;
}

void Deque::push_back(int i) 
{
  Node* newNode = new Node(i, nullptr, back);    
  if (back != nullptr) 
  {
    back->nextNode = newNode;
  }
  back = newNode;
  if (front == nullptr) 
  {
    front = newNode;  
  }
  size++;
}


int Deque::pop_front() 
{
  // check if the deque is empty
  if (front == nullptr) 
  {
    // Catch the info from the top Node before deleting it
    std::cout << "Error: Tried popping from an empty deque\n";
    return 0;
  } 
  int val = front->val;
  Node *temp = front->nextNode;

    // Delete the old top Node, and set the next Node as the new top
  if (front != nullptr) 
  {
    front->prevNode = nullptr;
  }
  else 
  {
    back = nullptr; // If the deque is now empty
  }
  delete temp;
  size--;
  return val;
  //std::cout << "Error: Tried popping an empty deque\n";
  //return 0; // Is this the best way to handle errors?
}

int Deque::pop_back() 
{
  if (back == nullptr) 
  {
    std::cout << "Error: Tried popping from an empty deque\n";
    return 0;
  }
  int val = back->val;
  Node* temp = back;
  back = back->prevNode;
  if (back != nullptr) 
  {
    back->nextNode = nullptr;
  } 
  else 
  {
    front = nullptr; // If the deque is now empty
  }
  delete temp;
  size--;
  return val;
}

// return the value at the top of the deque
int Deque::peak_front() 
{
    if (front == nullptr) {
        std::cout << "Error: Tried peaking at an empty deque\n";
        return 0;
    }
    return front->val;
}

int Deque::peak_back() 
{
    if (back == nullptr) 
    {
        std::cout << "Error: Tried peaking at an empty deque\n";
        return 0;
    }
    return back->val;
}
// Frees all data we allocated on the heap
// This is super important since we are allocating memory on the heap
void Deque::removeAll() 
{
  // This is a Super cheesy solution, Can you think of a better one?
  while (front != nullptr) 
  {
    pop_front();
  }
}

// Since we already have a function that cleans up memory, we can just call it
// for the deconstructor
Deque::~Deque() { removeAll(); }
