Zevi Rubin - Program 5
Mark LeBlanc - Comp 116

-Overview-
Summary: 
This program is a 20 questions game. It will operate by letting the user teach the computer how to guess what the user is thinking. At first the program will be limited with its responses, but as the user teaches the program, its efficiency with guessing will get much better (log2(n)). 

-Documents-

main.cpp
This is where I wrote the main, and most of the program. It is where the initial Tree T is constructed, and where the loop that runs through the tree is located.

Node.cpp
This is where the CTOR’s and DTOR’s are. This is also where the setters and getters are for accessing, and changing the nodes, and leaves of the tree. 

Node.h
This is the prototype header file for the Node document. It shows what types of files will be taken and returned from each method of the NODE class. 

Tree.cpp
This file has the initial constructor for the Tree, as well as a function that checks if it is empty, and to get its root pointer. 

Tree.h
This is the prototype for the Tree CTOR and DTOR .cpp file. It just states the file types required for the Tree class to work. 


Program Status: Technically this program runs as many times as you want! I would recommend running between two and five times as the grading sheet recommends. 
Right now the program guesses progressively closer to your object, as long as your object is the same for the whole time you play the game in one session. If you change objects part way though then the questions don’t get the computer any closer to finding the answer. Quite a fun game for when you are bored and want to teach a computer to guess your mind!   