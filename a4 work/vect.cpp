// Vect.cpp

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
     this->size = n;
     this->pVect = new double[size];
     
    
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
          this->pVect[i] = vect2.pVect[i];

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
      
      return pVect[i];
}

//-----------------------------------------------------------------------
Vect& Vect::fill(/*in*/const Vect& vect2)
{

  for(int i=0; i<this->size; i++)
  {
    this->pVect[i] = 0;

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
      //this->fill();     
      //XXXXXXXX nneeeeeddd to write the fill method!!!! Look in notes

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

