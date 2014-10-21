Zevi Rubin - Program 4
Mark LeBlanc - Comp 116

-Overview-
Summary: 
This program works with vectors. It uses a test suite to run a number of tests on some predetermined vectors. The vectors are in the form of (x, y, z, …n) where the variables are each a different degree. For example the vector (2, 1), is a 2d vector. The program will test some basic calculations like the ability to copy a vector to another array, the ability to check if a vector is equal to another vector, as well as some simple addition. 

-Documents-

vect.cpp
This is where the majority of my coding took place. It is where the methods of the Vect class are, and where most of the computations took place. 

vect.h
This is the respective header file for vect.cpp. This shows the test main file what functions are available for it to use before it calls them, thus keeping us from having to write the main all the way at the end of a one file function.

testMain.cpp
This is where the main function is that does all the calls, as well as the Vect class, and a lot of the test suite information. It runs tests using the methods in the vect.cpp file using the Vect class. 

testMain.h
This is the respective header file for the test.Main cpp file. It declares the test functions that will be called from the main function. 

Program Status: I have clean output for the average effort grading option. In my code in vect.cpp you will see that I have all the code written, but to keep the output tidy, and the errors to a minimum I could not include a fully functional prototype of the = operator. The code is right, and is there though! 