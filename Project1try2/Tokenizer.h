/*
Student Name: Jade Thompson
Student NetID: jet475
Compiler Used: Visual Studio
Program Description: This program maintains a list of PCs that stores stat values.
The user is able to set stat values and add/remove PCs in the list, as well as view
the list of PCs and filter the PCs by stat value.*/

#pragma once
#include <string>
#include <sstream>
using namespace std;
class Tokenizer
{
private:
	string str;
	stringstream ss;
public:
	Tokenizer();
	Tokenizer(string userStr);

	bool readWord(string& val);
	bool readInteger(int& val);
	bool readDouble(double& val);
	bool readLine(string& val);

	void setString(string& userStr);
	void clear();
	void rewind();
	bool isEmpty();
};

