//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Jacob Edsell
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Checks if the llist is empty
  bool isEmpty();
    
  //displays the entire llist
  void displayAll();

  //adds an element to the front of the linked list
  void addFront(el_t);
    
  //adds and element to the rear of the linked list
  void addRear(el_t);

  //deletes the front element in the linked list
  void deleteFront(el_t&);
  
  //---------------------------------------
    
  //deletes the rear element in the linked list
  void deleteRear(el_t&);
    
  //deletes the Ith element in the linked list
  void deleteIth(int, el_t&);  // calls moveTo

  //inserts an element to the Ith position in the linked list
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
