#ifndef myJOB
#define myJOB
//----------------------------------------------------------------------
//  SPECIFICATION FILE (JOB.h)
//  This module declares a new type for ONE JOB
//----------------------------------------------------------------------
#include <string>//used when strings will be used

using namespace std;//saves us having to do std:: before every line

class JOB//deff of the class JOB
{
    public://putlic data types that are accessible to the user
        JOB();   // CTOR
     	string getName() ;
     	short getId() ;
     	double getTotal() ;
     	double getremaining() ;
        string getType() ;
        void setRemaining(double newT) ;
     	

    private://private data types that programmer cannot change
    	string name;
    	short id;
    	double total;
    	double remaining;
        string jobType;
		
	
};  // end class JOB

#endif

