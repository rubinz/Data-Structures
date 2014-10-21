#include <iostream>
using namespace std;

MyCharStack::MyCharStack()
{
	//no need to declare an array, it exists in the private of the mychar stack
	top = -1; //start stack at empty

}


//what if he asks us to write push or pop in the similar fassion.
//learn how to write push and pop
//1: incrament top, then put whatever they push in the stack.