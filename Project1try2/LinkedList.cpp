/*
Student Name: Jade Thompson
Student NetID: jet475
Compiler Used: Visual Studio
Program Description: This program maintains a list of PCs that stores stat values.
The user is able to set stat values and add/remove PCs in the list, as well as view
the list of PCs and filter the PCs by stat value.*/

#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

LinkedList::~LinkedList() {
	Node* tmp = head;
	while (tmp != nullptr) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
	tail = nullptr;
}

bool LinkedList::insert(string inputname) {
	Node* newNode = new Node(inputname);
	Node* tmp = head;
	if (tmp == nullptr) { //if list is empty
		head = newNode;
		newNode->next = nullptr;
		return true;
	}
	
	while (tmp != nullptr) { // loops until end is reached
		if (tmp->next == nullptr) { //if only one PC in list
			if (tmp->name < inputname) { //if new belongs after tmp
				tmp->next = newNode;
				newNode->prev = tmp;
				newNode->next = nullptr;
				return true;
			}
			else if (tmp->name == inputname) {
				return false;
			}
			else { //if new goes first
				newNode->next = tmp;
				head = newNode;
				tmp->prev = newNode;
				return true;
			}
		}
		else if (inputname < tmp->name) { //if new goes before temp
			if (tmp->prev == nullptr) {
				head = newNode;
			}
			if (tmp->prev != nullptr) {
				tmp->prev->next = newNode;
			}
			newNode->prev = tmp->prev;
			newNode->next = tmp;
			tmp->prev = newNode;
			return true;
		}
		else if (inputname == tmp->name) {
			return false;
		}
		else { // else, iterates
			tmp = tmp->next;
		}
	}
	//runs when PC belongs at the end
	tail->next = newNode;
	tail = newNode;
	newNode->next = nullptr;
	return true;
}

bool LinkedList::searchByStat(string stat, string value) {
	Node* tmp = head;
	
	// this if else branch searches the PC list for the correct stat value based on user input
	if (stat == "level") {
		while (tmp != nullptr) {
			if (tmp->level == stoi(value)) {
				cout << "   " << tmp->name << " " << tmp->race << " " << tmp->job << " lvl " << tmp->level <<
					" physical " << tmp->physical << " social " << tmp->social << " mental " << tmp->mental << endl;
				tmp = tmp->next;
				continue;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
	else if (stat == "race")
		while (tmp != nullptr) {
			if (tmp->race == value) {
				cout << "   " << tmp->name << " " << tmp->race << " " << tmp->job << " lvl " << tmp->level <<
					" physical " << tmp->physical << " social " << tmp->social << " mental " << tmp->mental << endl;
				tmp = tmp->next;
				continue;
			}
			else {
				tmp = tmp->next;
			}
		}
	else if (stat == "job") {
		while (tmp != nullptr) {
			if (tmp->job == value) {
				cout << "   " << tmp->name << " " << tmp->race << " " << tmp->job << " lvl " << tmp->level <<
					" physical " << tmp->physical << " social " << tmp->social << " mental " << tmp->mental << endl;
				tmp = tmp->next;
				continue;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
	else if (stat == "physical") {
		while (tmp != nullptr) {
			if (tmp->physical == stoi(value)) {
				cout << "   " << tmp->name << " " << tmp->race << " " << tmp->job << " lvl " << tmp->level <<
					" physical " << tmp->physical << " social " << tmp->social << " mental " << tmp->mental << endl;
				tmp = tmp->next;
				continue;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
	else if (stat == "mental") {
		while (tmp != nullptr) {
			if (tmp->mental == stoi(value)) {
				cout << "   " << tmp->name << " " << tmp->race << " " << tmp->job << " lvl " << tmp->level <<
					" physical " << tmp->physical << " social " << tmp->social << " mental " << tmp->mental << endl;
				tmp = tmp->next;
				continue;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
	else if (stat == "social") {
		while (tmp != nullptr) {
			if (tmp->social == stoi(value)) {
				cout << "   " << tmp->name << " " << tmp->race << " " << tmp->job << " lvl " << tmp->level <<
					" physical " << tmp->physical << " social " << tmp->social << " mental " << tmp->mental << endl;
				tmp = tmp->next;
				continue;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
	else {
		return false;
	}
	cout << endl;
	return true;
}

bool LinkedList::removePC(string name) {
	Node* tmp = head;
	while (tmp != nullptr) {
		if (tmp->name != name) { //gets temp to proper node
			tmp = tmp->next;
		}
		else if (tmp->name == name) {
			if (tmp->prev == nullptr) { // if PC is head
				if (tmp->next == nullptr) { // if PC is only one in list
					delete tmp;
					return true;
				}
				head = tmp->next;
				head->prev = nullptr;
				delete tmp;
				return true;
			}
			else if (tmp->next == nullptr) { // if PC is tail
				tmp->prev->next = nullptr;
				delete tmp;
				return true;
			}
			else { // if PC is in middle
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				return true;
			}
		}
	}
	return false;
}

void LinkedList::display() {
	Node* tmp = head;
	if (tmp == nullptr) { // if linked list is empty
		cout << "Nothing to display" << endl << endl;
		return;
	}
	cout << "Displaying the PC List:" << endl;
	while (tmp != nullptr) {
		cout << "   " << tmp->name << " " << tmp->race << " " << tmp->job << " lvl " << tmp->level <<
			" physical " << tmp->physical << " social " << tmp->social << " mental " << tmp->mental;
		// outputs honors stats if they have a value, as they aren't defauled to 1
		tmp = tmp->next;
		cout << endl;
	}
	cout << endl;
	return;
}

bool LinkedList::setStatInt(string inputname, string stat, int value) {
	Node* tmp = head;
	while (tmp != nullptr) { // until end is reached
		if (inputname == tmp->name) { // if correct node is found
			// finds stat to set
			if (stat == "level") {
				tmp->level = value;
				cout << "Stat set." << endl << endl;
				return true;
			}
			else if (stat == "physical") {
				tmp->physical = value;
				cout << "Stat set." << endl << endl;
				return true;
			}
			else if (stat == "mental") {
				tmp->mental = value;
				cout << "Stat set." << endl << endl;
				return true;
			}
			else if (stat == "social") {
				tmp->social = value;
				cout << "Stat set." << endl << endl;
				return true;
			}
			else {
				cout << "Invalid stat type!" << endl << endl;
				return false;
			}
		}
		else { // if name doesn't match, go to next
			tmp = tmp->next;
		}
	}
	cout << "PC not found" << endl << endl;
	return false;
}

bool LinkedList::setStatStr(string name, string stat, string value) {
	Node* tmp = head;
	while (tmp != nullptr) { // until end is reached
		if (name == tmp->name) { // if correct node is found
			// finds correct stat to set
			if (stat == "race") {
				tmp->race = value;
				cout << "Stat set." << endl << endl;
				return true;
			}
			else if (stat == "job") {
				tmp->job = value;
				cout << "Stat set." << endl << endl;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			tmp = tmp->next;
		}
	}
	cout << "PC not found" << endl << endl;
	return false;
}

