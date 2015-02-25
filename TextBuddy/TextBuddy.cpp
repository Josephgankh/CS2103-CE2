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

const string ERROR_INVALID_COMMAND = "ERROR: Unrecognised command\n";

// This Function saves the current data into outputFile.txt either by creating a new file or overwriting the previous file
void TextBuddy::saveFile () {
	ofstream myFile;
	int i=0;

	myFile.open((outputFile).c_str());
	
	while (i < textList.size()) {
		myFile<<i+1<<". "<< textList[i] <<endl;
		++i;
	}

	myFile.close();
}

// This function takes in a string and prints it out
void TextBuddy::showToUser(string text) {
	cout<<endl<< text <<endl;
}

string TextBuddy::executeCommand(string command) {
	string str;
	int index;
	
	if (command == "add") {
		getline(cin, str);

		//To remove the blank space before the sentence
		str = str.substr(1);
		
		return addText(str);
	}

	else if (command == "delete") {
		cin >> index;

		return deleteText(index);
	}

	else if (command == "display") {
		return displayText();
	}

	else if (command == "clear") {
		return clearText();
	}

	else if (command == "sort") {
		return sort();
	}

	else if (command == "search") {
		cin >> str;

		return search(str);
	}

	else return ERROR_INVALID_COMMAND;
}

// Reads in a line of words and push them into the back of the vector
string TextBuddy::addText(string str) {
	
	textList.push_back(str);

	ostringstream out;
	out << "added to "<< outputFile.c_str()<<": \"" << str <<"\""<<endl;
	return out.str();
}

//Reads in a positive integer and deletes the line of words corresponding to that index
string TextBuddy::deleteText(int index) {
	ostringstream out;

	//A user input of 1 would refer to the 0th index of the array
	--index; 

	string words = textList[index];

	textList.erase(textList.begin()+index);

	out << "deleted from "<< outputFile.c_str()<<": \"" << words <<"\""<<endl;

	return out.str();
}

string TextBuddy::displayText() {
	ostringstream out;
	int i=0;

	if (textList.size()==0) {
		out << outputFile.c_str()<<" is Empty" << endl;
	}

	else while (i<textList.size()) {
		if (i!=0){
		out <<endl;
		}

		out << i+1<<". " << textList[i] <<endl;
		++i;
	}

	return out.str();
}

//empty the entire file
string TextBuddy::clearText() {
	ostringstream out;
	
	textList.clear();

	out << "all contents deleted from "<<outputFile.c_str()<<endl;

	return out.str();
}

string TextBuddy::sort () {
	ostringstream out;
	
	std::sort(textList.begin(), textList.end());

	out << "sorted!"<<endl;

	return out.str();
}

string TextBuddy::search(string str) {
	ostringstream out;
	int i=0, j=0;

	out << "searching for \""<<str<<"\"..."<<endl;

	while (i<textList.size()) {
		if (textList[i].find(str)!=-1) {
			if (j!=0)
				out <<endl;
			out << j+1 <<". " << textList[i] <<endl;
			++j;
		}
		++i;
	}

	if (j==0) {
		out <<"not found" << endl;
	}

	return out.str();
}

void TextBuddy::executeProgram () {
	string command;
	
	cin >> command;	

	while (command!="exit") {
		showToUser(executeCommand(command));
		saveFile();
		cout << "command: ";
		cin >> command;	
	}
}

int main(int argc, char* argv[]) {
	TextBuddy program;
	
	program.outputFile = argv[1];

	cout << "Welcome to TextBuddy. "<< argv[1] <<" is ready for use"<<endl<<endl;
	cout << "command: ";

	program.executeProgram();

	return 0;
}