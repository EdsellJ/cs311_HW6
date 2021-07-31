// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Jacob Edsell
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ 
  cout << "slist constructor:" << endl;
}


// positions always start at 1

int slist::search(el_t Key){
  Node *p = Front;   // set a pointer to front.
	int position = 1;  // current position.

	// traversed list until p points to null.
	while (p != NULL) {
		// if current nodes element equals key, return the position.
		if (p->Elem == Key) {
			return position;
		}
		p = p->Next;
		position++;
	}

	//  else, key was not found, so return 0.
	return 0;
}

// don't forget to throw OutOfRange for bad pos 
// You should use moveTo to go to the pos
void slist::replace(el_t element, int pos){
  // if I is greater Count OR I is less than 1, thrown out of range
	if (pos > Count || pos < 1) {
		throw OutOfRange();
	}

  Node *p = Front;   // set a pointer to front.
  moveTo(pos, p);  //move p to the element to be replaced

	cout << "Element " << p->Elem << " replaced with " << element << endl;
	p->Elem = element;  // p's element replaced by elem.
}

bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false
  if (OtherOne.Count != this->Count){
    return false;
  }
  // if the same lengths,
  //check each node to see if the elements are the same
  else {
    Node *p = OtherOne.Front;
    Node *q = this->Front;

    while (p != NULL){
      if (p->Elem != q->Elem){
        return false;
      }
      p = p->Next;
      q = q->Next;
    }
    return true;
  }
}
