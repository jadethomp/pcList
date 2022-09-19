/*
Student Name: Jade Thompson
Student NetID: jet475
Compiler Used: Visual Studio
Program Description: This program maintains a list of PCs that stores stat values.
The user is able to set stat values and add/remove PCs in the list, as well as view
the list of PCs and filter the PCs by stat value.*/

#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include "Tokenizer.h"
using namespace std;

bool processText(istream& is, LinkedList& pclist, bool interactive = true)
{
	string line;
	string command;
	string arg1, arg2, arg3;
	int altarg3;
	Tokenizer tkn;

	while (true) { //read loop
		if (!interactive) { // (if in file loading mode)
			if (is.eof()) { // (if file is done)
				cout << "File completed!" << endl << endl;
				return false;
			}
		}
		else { cout << ">> "; }
		getline(is, line);
		tkn.setString(line);
		tkn.readWord(command);

		if (command == "exit") {
			pclist.~LinkedList(); //cleans up memory
			cout << "Exiting ...." << endl;
			return false;
		}
		if (command == "load") {
			// load expects a filename .. so read one more word
			if (!tkn.readWord(arg1)) {
				cout << "Missing file name" << endl << endl;
				continue; // skip back to the top of the read loop (same with other continues in this function)
			}
			// attempts to load file
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open()) {
				status = processText(fin, pclist, false);
			}
			else {
				cout << "Failed to open the file" << endl << endl;
			}
			fin.close();
			if (!status) return false;
		}
		if (command == "set") {
			// uses either setStatInt or setStatStr to set a stat
			if (!tkn.readWord(arg1)) { //arg 1 = name
				cout << "Missing name" << endl << endl;
				continue;
			}
			if (!tkn.readWord(arg2)) { //arg2 = stat
				cout << "Missing stat type" << endl << endl;
				continue;
			} 
			if ((arg2 == "level") || (arg2 == "physical") || (arg2 == "mental") || (arg2 == "social")) {
				if (!tkn.readInteger(altarg3)) { //arg3 = stat value (altarg3 created for different data type)
					cout << "Missing stat value" << endl << endl;
					continue;
				}
				pclist.setStatInt(arg1, arg2, altarg3);
				continue;
			}
			else if ((arg2 == "race") || (arg2 == "job")) {
				if (!tkn.readWord(arg3)) {
					cout << "Missing stat value" << endl << endl;
				}
				pclist.setStatStr(arg1, arg2, arg3);
				continue;
			}
			else {
				cout << "Invalid stat!" << endl << endl;
				continue;
			}
		}

		if (command == "add") {
			// uses insert to add a PC (uses user name, default stat values)
			tkn.readWord(arg1);
			if (pclist.insert(arg1)) {
				cout << "Player added." << endl << endl;
				continue;
			}
			cout << "Player already exists!" << endl << endl;
			continue;
		}

		if (command == "search") {
			// uses searchByStat to search
			tkn.readWord(arg1); //arg1 = stat
			tkn.readWord(arg2); //arg2 = value
			cout << "PCs with stat value: " << endl;
			if (pclist.searchByStat(arg1, arg2)) {
				continue;
			}
			cout << "Invalid stat." << endl << endl;
		}

		if (command == "display") {
			// displays all PCs
			pclist.display();
			continue;
		}

		if (command == "remove") {
			// uses removePC to remove a PC
			tkn.readWord(arg1);
			if (pclist.removePC(arg1)) {
				cout << "PC removed." << endl << endl;
				continue;
			}
			cout << "Could not remove PC." << endl << endl;
			continue;
		}
		cout << "Invalid command." << endl << endl;
	}
}

int main() {
	LinkedList masterPClist;
	processText(cin, masterPClist);
	return 0;
}