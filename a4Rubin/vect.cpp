// Vect.cpp

/*▁ ▂ ▄ ▅ ▆ ▇ █ Comp 116 a4 █ ▇ ▆ ▅ ▄ ▂ ▁*\
╓──────────────────────────────────────╖
║  Programmer: Zevi Rubin - Program 4  ║
╟──────────────────────────────────────╙───────────────────────────────────╖
║Summary:This program will simmulate some simple computational processes   ║
║        involving vectors. It generates vecotrs of certain sizes and      ║
║        then tests the programs robustness with a few vector computations ║
║                                                                          ║
║ Date last modified:                                                      ║
║ 04/6/2014 (ZR) - trying to figure out what this assignment will need     ╙─────────────────────────────────────╖
║ 04/7/2014 (ZR) - Working on heap memmory using pointers. I dont know how we use this in a4 yet                 ║ 
║ 04/9/2014 (ZR) - Got the ctor's working I think.. Devin said thats really what this program is going to need   ║
║ 04/10/2014 (ZR) - I dont know how to trouble shoote the errors im getting. Never seen linking errors on a mac  ║
║ 04/11/2014 (ZR) - Cannot give up hope on this program yet. I think I have most of the average effort written :)║
║                                                                          ╓─────────────────────────────────────╜
╟──────────────────────────────────────────────────────────────────────────╢
║INPUT(Keyboard, stdin): For demonstraition purposes this program prints   ║    
║              require any keyboard input. It generates its own vectors    ║
║OUTPUT:This program will  print vector computations to the console screen ║
║       The output user will be notified if the computations cleared all   ║
║        tests or if there was some error in the vector computation.       ║
╙──────────────────────────────────────────────────────────────────────────╜
\*                                                                        */
#include "Vect.h"

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "math.h"

using namespace std;

//-----------------------------------------------------------------------
//----- Constructors (CTOR) ---------------------------------------------

Vect::Vect()
/*
PRE:  None
POST: Will create a new vector object with the default settings
*/
{
      this->size = 3;                          // Default size
      this->pVect = new double[size];          // Creates a new block of doubles
}

//-----------------------------------------------------------------------

Vect::Vect(/*in*/long n)
/*
PRE:  n is assigned
POST: Will create a new vector object of the desired size n
*/
{
     this->size = n; //devault ctor for when the user inputs a desired size (dimensions) for the vector
     this->pVect = new double[size]; //storing the private data type size and pVect
     
    
}

//-----------------------------------------------------------------------
// COPY CTOR
Vect::Vect(/*in*/const Vect& vect2)
/*
PRE:  vect2 is assigned
POST: Will create a new vector object of the same size as vect2 and 
      with the same values
*/
{
       this->size = vect2.size;                // Size set to the size of vect2
       this->pVect = new double[this->size];   // Creates a new block of doubles
       
       // Copy all elements of vect2 into the new vector
       // you do this ...
       for (int i=0; i<size; i++)
       {
          this->pVect[i] = vect2.pVect[i];//copy ctor. This copys the values of pVect to a new vector. 

       }

}

//-----------------------------------------------------------------------
//----- Destructor (DTOR) -----------------------------------------------

Vect::~Vect()
/*
PRE:  None
POST: Will free pVect so that memory can be used again
*/
{
    // you do this ....
    for (int i=0; i<size; i++)
       {
          this->pVect[i] = 0;//just to make sure the memory doesnt have something in it, this will full the array with 0's

       }
    delete[] pVect; // important!!! this deletes pVect from the heap memmory, leaving open room to be used in future.
    
}

//-----------------------------------------------------------------------
//----- Get magnitude of vector -----------------------------------------

double Vect::getMagnitude()
/*
PRE:  None
POST: Returns the magnitude of the vector
*/
{
      double magnitude;        // Holds final magnitude of vector
      double sum = 0;          // Holds sum of all elements squared
      short i = 0;             // Counter Declaration
      
      // Loops through all elements in the vector and adds up the sqaures of each element
 
      // you do this ...
    
    
    
    
    
      
      return magnitude;
}

//-----------------------------------------------------------------------
//----- Set elements of vector ------------------------------------------

double& Vect::operator[] (/*in*/long i) const
/*
PRE:  i is assigned
POST: Returns desired dereferenced vector element 
*/
{
      // Checks that i is a valid index, if not the program exits
      if (i < 0 || i >= this->size)
      {
            cerr << "ERROR:index [" << i << "] is out of bounds." << endl;
            system("PAUSE");
            exit(-1);
      }// end if
      
      return pVect[i];//basically creating the array that will hold the vetor values. 
}

//-----------------------------------------------------------------------
Vect& Vect::fill(/*in*/const Vect& vect2)//declare function.
/*
PRE:  vect2 is an assigned vector
POST: fills Vect& with 0's

*/
{

  for(int i=0; i<this->size; i++)
  {
    this->pVect[i] = 0;//this function will fill a new/incorrectly sized array with 0's.

  }


}

//-----------------------------------------------------------------------

Vect& Vect::operator=(/*in*/const Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Copies all elements of vect2 to vector making the call and
      changes its size if needed to match vect2
      Returns cloned vector
*/
{
      // you do this ...
    if (this->size == vect2.size)
    {
      for(int i = 0; i < this->size; i++)
      {
        this->pVect[i] = vect2.pVect[i];
      }
    }
    else if(this->size > vect2.size)//for copying the bigger one (this) into the smaller one.
    {
      //vect temp[this->size];
      delete []this->pVect;

      pVect = new double[vect2.size];
      this->size = vect2.size;
      this->fill();     
      

      for(int i = 0; i < this->size; i++)
      {
        this->pVect[i] = vect2.pVect[i];
      }
    }
    
    else //(this->size < vect2.size)
    {

      delete []this->pVect;
      pVect = new double[vect2.size];
      this->size = vect2.size;

      for(int i = 0; i < this->size; i++)
      {
        this->pVect[i] = vect2.pVect[i]; 
      }
  
    
    }
      return *this;
}

//-----------------------------------------------------------------------
//----- Vector arithmetic ----------------------------------------------

const Vect Vect::operator+(/*in*/const Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns vector temp which is the sum of the vector making 
      the call and vect2
*/
{

    
    
    
    
}

//-----------------------------------------------------------------------




//-----------------------------------------------------------------------
//----- Compare vectors -------------------------------------------------

bool Vect::operator==(/*inout*/Vect& vect2)
/*
PRE:  vect2 is an assigned vector
POST: Returns true or false
*/
{
      if (this->getMagnitude() == vect2.getMagnitude())
           return true;
      else
          return false;
}

//-----------------------------------------------------------------------





//-----------------------------------------------------------------------
//----- Print vectors ---------------------------------------

ostream& operator<<(/*inout*/ostream& output, /*in*/const Vect& vector)
/*
PRE:  << operators still used with cout and vector is an assigned vector
POST: Returns ostream output for the vector

operator assignment "<<": prints vector in <a,b,c...> format
*/
{ 
      output << '<' << vector.pVect[0]; //front bracket
     
      // Loops through remaing elements and prints them
      for(short i=1; i < vector.size; i++)
            output << ',' << vector.pVect[i]; //dimen. values
     
      output << '>'; //back bracket
     
      return output; 
}

//-----------------------------------------------------------------------

