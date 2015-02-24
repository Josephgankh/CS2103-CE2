/**
* This class is used to write a CLI (Command Line Interface) program called 
* TextBuddy C++ to manipulate text in a file.
* Here is a sample interaction with the program:

c:> TextBuddy.exe mytextfile.txt  (OR c:>java  TextBuddy mytextfile.txt)

Welcome to TextBuddy. mytextfile.txt is ready for use
command: add little brown fox
added to mytextfile.txt: “little brown fox”
command: display
1. little brown fox
command: add jumped over the moon
added to mytextfile.txt: “jumped over the moon”
command: display
1. little brown fox
2. jumped over the moon
command: delete 2
deleted from mytextfile.txt: “jumped over the moon”
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

#include "TextBuddy.h"

string TextBuddy::textList[MAX_SIZE];
const string TextBuddy::ERROR_INVALID_COMMAND = "ERROR: Unrecognised command\n";

// This Function saves the current data into outputFile.txt either by creating a new file or overwriting the previous file
void TextBuddy::saveFile (string outputFile) {
	ofstream myfile;
	myfile.open(outputFile.c_str());
	int i=0;

	while (textList[i]!="") {
		myfile<<i+1<<". "<< textList[i] <<endl;
		++i;
	}

	myfile.close();
}

void TextBuddy::showToUser(string text) {
	cout<<endl<< text <<endl;
}

string TextBuddy::executeCommand(string command, string outputFile) {
	if (command == "add")
		return addText(outputFile);
	else if (command == "delete")
		return deleteText(outputFile);
	else if (command == "display")
		return displayText(outputFile);
	else if (command == "clear")
		return clearText(outputFile);
	else return ERROR_INVALID_COMMAND;
}

// Reads in a line of words and adds them into the next empty slot
string TextBuddy::addText(string outputFile) {
	string words; 
	int j = findEmpty(textList);

	getline(cin, words);

	//To remove the blank space before the sentence
	words = words.substr(1);
	textList[j] = words;
	
	ostringstream out;
	out << "added to "<< outputFile.c_str()<<": \"" << words <<"\""<<endl;
	return out.str();
}

//Searches through the array and searches for an empty slot and returns the corresponding index
int TextBuddy::findEmpty(string textList[10]) {
	int i = 0;
	
	while (textList[i]!="")
		++i;

	return i;
}

//Reads in a positive integer and deletes the line of words corresponding to that index
string TextBuddy::deleteText(string outputFile) {
	int index;
	cin >> index;

	//A user input of 1 would refer to the 0th index of the array
	--index; 

	string words = textList[index];

	while (textList[index+1]!="") {
		textList[index] = textList[index+1];
		++index;
	}
	textList[index]="";

	ostringstream out;
	out << "deleted from "<< outputFile.c_str()<<": \"" << words <<"\""<<endl;
	return out.str();
}

string TextBuddy::displayText(string outputFile) {
	ostringstream out;
	int i=0;

	if (textList[0]=="")
		out << outputFile.c_str()<<" is Empty" << endl;
	else while (textList[i]!="") {
		if (i!=0)
			out <<endl;
			out << i+1<<". " << textList[i] <<endl;
		++i;
	}

	return out.str();
}

//empty the entire file
string TextBuddy::clearText(string outputFile) {
	int i = 0;

	while (textList[i]!="") { 
		textList[i]="";
		++i;
	}

	ostringstream out;
	out << "all contents deleted from "<<outputFile.c_str()<<endl;
	return out.str();
}

void executeProgram (TextBuddy program) {
	string command;
	
	cin >> command;	

	while (command!="exit") {
		program.showToUser(program.executeCommand(command, program.outputFile));
		program.saveFile(program.outputFile);
		cout << "command: ";
		cin >> command;	
	}
}

int main(int argc, char* argv[]) {
	TextBuddy program;
	
	program.outputFile = argv[1];

	cout << "Welcome to TextBuddy. "<< argv[1] <<" is ready for use"<<endl<<endl;
	cout << "command: ";

	executeProgram(program);

	return 0;
}
