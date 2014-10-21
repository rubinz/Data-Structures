#include <iostream>
#include "dogfoodlid.h"
#include <stdlib.h>
//#include <array>


using namespace std;

int main()
{
  cout << "\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
  cout << "Begining dogfoodlid testing" << endl;
  cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n" << endl;


  dogfoodlid A;
  dogfoodlid B("cat");
  B.print();
  cout << B.getLength() << endl;
}
