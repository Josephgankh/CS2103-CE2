/**
* This class is used to write a CLI (Command Line Interface) program called 
* TextBuddy C++ to manipulate text in a file.
* Here is a sample interaction with the program:

c:> TextBuddy.exe mytextfile.txt  (OR c:>java  TextBuddy mytextfile.txt)

Welcome to TextBuddy. mytextfile.txt is ready for use
command: add little brown fox
added to mytextfile.txt: �little brown fox�
command: display
1. little brown fox
command: add jumped over the moon
added to mytextfile.txt: �jumped over the moon�
command: display
1. little brown fox
2. jumped over the moon
command: delete 2
deleted from mytextfile.txt: �jumped over the moon�
command: display
1. little brown fox
command: clear
all content deleted from mytextfile.txt
command: display
mytextfile.txt is empty
command: exit

c:>

*****Assumptions*****
1. The user does not wish to edit text from an existing file
2. User commands are all in small case

In this program, the file is saved to the disk after each user operation

* @author Gan Ke Hao, Joseph
*/

// This is to safeguard the class to prevent redefined

#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H

#include <sstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>

const int MAX_SIZE = 100;

using namespace std;

class TextBuddy{
public:
	vector<string> textList;
	string outputFile;
	string executeCommand(string command);
	string deleteText(int index);
	string addText(string str);
	string displayText();
	string clearText();
	string sort ();
	string search(string str);
	void showToUser(string text);
	void saveFile ();
	void executeProgram ();
};

#endif