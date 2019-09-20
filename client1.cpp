//=========================================================
//HW#: HW2 stack
//Your name: Heriberto Bernal
//Complier:  gcc compiler
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>
#include "vstack.h"

//Purpose of the program: This program will solve post fix problems by creating a stack
//Algorithm: Ask the user for an expression, then check the items of that expresion. If it is number it will push it to the stack. If it is '+','-' or '*' it will pop two numbers from the stack amd do the calculation then push the result in the stack.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  char resultC; //final result
  int result; //result between box1 and box2
  char box1;  // receive things from pop
  char box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  if((item >= 48) && (item <= 57))
	    {
	      postfixstack.push(item);
	    }
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') result = (int(box2-48)-int(box1-48)); //subtract two numbers
	      else if (item == '+') result = (int(box2-48)+int(box1-48)); //add two numbers 
	      else result = (int(box2-48)*int(box1-48)); //multiply two numbers
	      
	      postfixstack.push(char(result+48));// Finally push the result
	    }
	  else throw "invalid item"; //throw an error if invaild item
	}
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow)  // for too much operands
	{ cout << "Sorry, the stack is full." << endl; exit(1);}
      catch (stack::Underflow) // for too few operands
	{ cout << "Sorry, not enough operands." << endl; exit(1);}
      catch (char const* errorcode) // for invalid item
	{ cout << "Sorry, the item you enter is invalid." << endl;}
      
      i = i++;// go back to the loop after incrementing i
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  postfixstack.pop(resultC);
  cout << "The result is: " << int(resultC-48) << endl;
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  if(postfixstack.isEmpty() != true)
    {
      cout << "An incomplete expression was found" << endl;
      postfixstack.displayAll();
    }

}// end of the program
