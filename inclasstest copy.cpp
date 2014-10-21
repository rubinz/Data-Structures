#include <iostream>
using namespace std;

short a=1, b=1;
short *p, *q;

p=&a;//makes p hold the location(200) of a.
q=&b;
a=a+3;
b=*p+2; //makes b(1) equal to the value of a(1) + 2.

//cout << a << b << p << q << endl;


delete p, q;