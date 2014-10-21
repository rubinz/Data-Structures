#include <iostream>
#include "dogfoodlid.h"
#include <stdlib.h>
//#include <array>


using namespace std;


dogfoodlid::dogfoodlid()
{
  strcpy(this->text, "nothing");
  this->length = strlen(this->text);

}

dogfoodlid::dogfoodlid(char x[])//declares what type is being passed in
{
  strcpy(this->text, x);
  this->length = strlen(this->text);

}

void dogfoodlid::print()
{
  cout << text << endl;
}

short dogfoodlid::getLength()
{
  return length;
}

void dogfoodlid::getCopyOf(dogfoodlid x) const
{

}

bool dogfoodlid::isEqual (dogfoodlid x)
{

  //if (A.length() == B.length())

  return true;
}

void dogfoodlid::concat(char s[])
{

}
char* dogfoodlid::reverse() const
{
  // int count = 0;
  // char temp;
  // for (int i = 0; i < count/2; ++i)
  // {
  //     temp = text[count-i-1];
  //     text[count-i-1] = text[i];
  //     text[i] = temp;
  // }
  // for (i = 0; i < count; ++i) {
  //     cout << text[i] << " ";
  // }

}
