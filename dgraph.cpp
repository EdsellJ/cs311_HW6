//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: **
// File Type: **
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // initialize countUsed to be 0
{
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help


}
void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top 
}

int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop - go to a slot using V
}

slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop - go to a slot using V
}
