
//=========================================================
//HW#: HW1P2 stack
//Your name: Heriberto Bernal
//Complier:  g compiler
//File type: stack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include <vector>
#include "vstack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack() {} // indicate an empty stack 
  
//PURPOSE:  Destructor will remove all elements on the stack.
stack::~stack()
{ int i = el.size()-1;
  while(el[i] != -1)
    { el.pop_back(); i--;}
} 
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
// In the comment, make sure you define "empty" in terms of top.
//If the top is equal to -1 then the stack is empty
bool stack::isEmpty()
{ if ((el.size()-1) == -1) return true; else return false; }
    
//PURPOSE: checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
//If the top is equal to MAX(max. capacity of the stack) then the stack is full
bool stack::isFull()
{ return false; }
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
 void stack::push(el_t elem)
{ if (isFull()) throw Overflow{}; 
  else { el.push_back(elem);}
}
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(el_t& elem)
{ if (isEmpty()) throw Underflow{}; 
  else { elem = el[el.size()-1]; 
      el.pop_back();}
}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
{ if (isEmpty()) {throw Underflow{}; }
   else { elem = el[0]; } 
}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
 void stack::displayAll()
 {  if (isEmpty()) cout << "[ empty ]" << endl;
   else for (int i=0; i<=(el.size()-1); i++)
     { cout << el[i] << endl; }
   cout << "--------------" << endl;
 }
 
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
 void stack::clearIt()
{ if(isEmpty()) {throw Underflow{}; }
  else{
    el_t eleme; //pop element will go in this variable
    for(int i=el.size()-1; i>=0; i--) //this for loop will pop all elements in the stack
      {pop(eleme);} 
      }
 }
 

