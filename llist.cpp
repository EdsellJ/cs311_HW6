//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Jacob Edsell
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{
  cout << "... in llist constructor..." << endl; 
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist()
{
  cout << ".... in llist destructor..." << endl; 
  el_t x; //to store deleted elem
  while (!isEmpty()){
    deleteFront(x);
  }
}

//PURPOSE: Checks if the linked list is empty
//PARAMETER: none
bool llist::isEmpty() { 
  if (Front == NULL && Rear == NULL && Count == 0){
    return true;
  } else return false;
} // be sure to check all 3 data members

//PURPOSE: Displays all nodes in the linked list
//PARAMETER: none
void llist::displayAll() { 
  Node *p = Front;

  //if empty
  if (isEmpty()){
    cout << "[ empty ]" << endl;
  }
  else {
    cout << "[ ";
    while (p != NULL) {
      cout<< p->Elem << " ";

      p = p->Next;
    }
    cout << "]";

    cout << endl;
  }
}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE: adds a new node to the end of the list
//PARAMETER: NewNum: the element to be added to the new node
void llist::addRear(el_t NewNum) { 
  //case 1: if first node then create a new node AND set Front to mynode
  if (Count == 0) {
		Node *mynode = new Node; // creates new node.
		mynode->Elem = NewNum;
		Front = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
  }
  //case 2: new node created then only update Rear
  else {
		Node *mynode = new Node; // creates new node.
		mynode->Elem = NewNum;
		Rear->Next = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
  }
} // comment the 2 cases


//PURPOSE: Adds a node to the front of the linked list 
//PARAMETER: NewNum: the element to be added to the new node
void llist::addFront(el_t NewNum) { 
  //case 1: if first node then create a new node AND set Front to mynode
  if (Count == 0) {
		Node *mynode = new Node; // creates new node
		mynode->Elem = NewNum;
		Front = mynode;
		Rear = mynode;
		Rear->Next = NULL;
		Count++;
	}
  //case 2: new node created then only update Rear
  else {
		Node *mynode = new Node; // creates new node
		mynode->Elem = NewNum;
		mynode->Next = Front;
		Front = mynode;
		Count++;
  }
} // comment the 2 cases

//PURPOSE:
//PARAMETER:
void llist::deleteFront(el_t& OldNum) { 
  // Case 1: if empty throw underflow
	if (isEmpty()) {
		throw llist::Underflow();
	}
	
  //Case 2: if there is only one element left set Front and Rear to NULL
	else if (Count == 1) {
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}

	// Case 3: Regular case
	// delete front node and set the second node as the new front
	else {
		OldNum = Front->Elem;
		Node* second = Front->Next; // pointer points to node after front.
		delete Front;
		Front = second;
		Count--;
	}
} // comment the 3 cases

//PURPOSE: Delete the last node of the linked list 
//PARAMETER: OldNum: stores the deleted element by reference
void llist::deleteRear(el_t& OldNum){
  //Case 1: if empty, throw underflow
	if (isEmpty()) {
		throw llist::Underflow();
	}

	//Case 2: if the rear is the only element
  //delete element then set front and rear to NULL
	else if (Count == 1) {
		OldNum = Rear->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}

	// Case 3:
	// OldNum holds rears element. new pointer p points to front.
	// list is traversed to point to node before rear. rear is then deleted.
	// rear is set to bide before rear. rear next is set to point to null.
	else {
		OldNum = Rear->Elem;
		Node *p = Front; // pointer to traverse list.

		// loop to point to node before rear.
		while (p->Next != Rear) {
			p = p->Next;
		}

		delete Rear;
		Rear = p;
		Rear->Next = NULL;
		Count--;
	}
} // comment the 3 cases



/* --- harder ones follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
  for (int i = 0; i < J - 1; i++){
    temp = temp -> Next;
  }
}

//PURPOSE:
//PARAMETER:
void llist::deleteIth(int I, el_t& OldNum) { 
  //Case 1: if out of range, throw OutOfRange
  if (I > Count || I < 1) {
		throw llist::OutOfRange();
	}

//Case 2: If I is 1 call deleteFront
  else if (I == 1){
    deleteFront(OldNum);
}

//Case 3: If I == Count, call delete Rear
  else if (I == Count) {
		deleteRear(OldNum);
	}

  //Case 4: Regular Case

  //Create 2 temp variables to link the previous and next node
  else{
  Node *P = Front;
  Node *Q = Front;
  moveTo(I-1, P);
  moveTo(I + 1, Q);

  //create a temp variable to hold the value of the OldNum
  Node *temp = P->Next;
  OldNum = temp->Elem;

  //Point P to Q then delete temp
  P->Next = Q;
  delete(temp);
  Count--;
  }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE:
//PARAMETER:
void llist::insertIth(int I, el_t newNum) { 
 
 //Case 1: if out of range, throw OutOfRange
  if (I > Count + 1 || I < 1) {
		throw llist::OutOfRange();
	}

//Case 2: If I is 1 call addFront
  else if (I == 1){
    addFront(newNum);
  }

//Case 3: If I == Count + 1, call delete Rear
  else if (I == Count + 1) {
		addRear(newNum);
	}

//Case 4: Regular Case
//Create 2 temp variables to link all of the nodes
  else{
  Node *P = Front;
  Node *Q = Front;
  moveTo(I-1, P);
  moveTo(I, Q);

  //create a temp variable to hold the value of the newNum
  Node *temp = new Node;
  temp -> Elem = newNum;
  

  //Point P to temp then temp to Q
  temp->Next = Q;
  P->Next = temp;
  Count++;
  }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE:
//PARAMETER:
llist::llist(const llist& Original) {
  //this->'s data members need to be initialized here first
    Front = NULL; Rear = NULL; Count = 0;
  //  this-> object has to be built up by allocating new cells
  //  and copying the values from Original into each cell as we did with 
  //  operator= above. To do this,
  Node *P;
  P = Original.Front;
  while (P != NULL) {
    this->addRear(P->Elem);
    P = P->Next;
  }
 } // use my code

//PURPOSE:
//PARAMETER:
llist& llist::operator=(const llist& OtherOne) { 
  el_t x;
     // First make sure this-> and OtherOne are not the same object.
     // To do this, compare the pointers to the objects .
     if (&OtherOne != this)  // if not the same
      {
        // this-> object has to be emptied first.
        while (! this->isEmpty() )
          this->deleteRear(x);  
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
           this->addRear(P->Elem);    //P’s element is added to this->
           P = P->Next;                         // Go to the next node in OtherOne   
         } 
      }// end of if              
     return *this;    // return the result unconditionally.  Note that the result is returned by reference.
} // use my code

