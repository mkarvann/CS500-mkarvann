#ifndef deque_h
#define deque_h
// Here is the PROTOTYPE for the deque class, the definitions live on the
// deque.cpp file

// A heap allocated deque data structure using a linked-list implementation
// If we created this class well, the person using this class



class Deque {
private:
  /*This is a private DEFINITION for a struct meaning that
  this Node struct is only useable in the deque class, and
  no instance of it has been created yet. We will use these
  Nodes like a linked-list to create our deque, Where every
  Node will contain a value (the data we want to store in the
  deque) and a pointer to the next node in the deque.*/
  struct Node {

    // The value that is stored at this Node
    int val;
    // The pointer to the next Node in the deque (this will point to the Node
    // ~below~ this Node)

    //These pointers keep track of where the front and back of the deque are.
    Node *nextNode;
    Node *prevNode;

    // Constructor. putting "c" before the parameters in your constructor is a
    // nice convention

    //the Node constructor initializes a node for our deque
    Node(int cVal, Node *cNextNode, Node *cPrevNode);
  };

  // The only member variable of ~deque~
  // This is necessary because we need to pop, push and peak fromt he top of the
  // deque


  Node* front; // Pointer to the front node
  Node* back; // Pointer to the back node
  int size;

public:
  // Standard OOP stuff
  Deque();
  // Node *getTopOfdeque();
  // void setTopOfdeque(Node *n);
  // The three member functions the user cares about
  // This should create a new Node (that lives on the heap) and push it to the
  // top of the deque


  void push_front(int i); // Add an element to the front
  void push_back(int i); // Add an element to the back

  // This should return the value at the top of the deque, delete all data
  // allocated by the top node, and update topOfdeque

  int pop_front(); // Remove an element from the front
  int pop_back(); // Remove an element from the back  
  
  // This just needs to return the value at the top of the deque
  
  
  int peak_front(); // View the front element without removing it
  int peak_back(); // View the back element without removing it
  
  // This should free all data allocated to the heap
  void removeAll();

  // This is a DECONSTRUCTER, and it will be called when an instance of this
  // object is destroyed (Usually this happens when an instance of this object
  // goes out of scope) Deconstructors are important to use when your object
  // allocates memory on the heap, as we want to clean up after ourselves. This
  // way the Caller of this class does not have to worry about how this class
  // manages memory If this doesn't make any sense, just think about it very
  // very hard!
  ~Deque();
};

#endif
