#ifndef myStrings
#define myStrings
#include <stdlib.h>
//#include <array>



using namespace std;
const short MAXLENGTH = 4;


class dogfoodlid
{
public:
  dogfoodlid(); //constructor
  dogfoodlid(char[]);

  //functions
  void print();
  short getLength();
  void getCopyOf(dogfoodlid x) const;
  bool isEqual(dogfoodlid x);
  void concat(char s[]);
  char* reverse() const;

private:
  char text[MAXLENGTH+1];
  short length;

};

#endif
