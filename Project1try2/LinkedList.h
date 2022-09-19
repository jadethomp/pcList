/*
Student Name: Jade Thompson
Student NetID: jet475
Compiler Used: Visual Studio
Program Description: This program maintains a list of PCs that stores stat values.
The user is able to set stat values and add/remove PCs in the list, as well as view
the list of PCs and filter the PCs by stat value.*/

#pragma once
#include <string>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

class Node {
public:
	string name;
	string race;
	string job;
	int level;
	int physical;
	int mental;
	int social;

	Node* next;
	Node* prev;

	Node() : name("NULL"), next(nullptr), prev(nullptr), level(1), race("PC"), job("villager"), physical(1), mental(1), social(1) {}
	Node(string name) : name(name), next(nullptr), prev(nullptr), level(1), race("PC"), job("villager"), physical(1), mental(1), social(1) {}
	Node(string name, Node* next, Node* prev) : name(name), next(next), prev(prev), level(1), race("PC"), job("villager"), physical(1), mental(1), social(1) {}
};

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	~LinkedList();

	bool insert(string inputname);
	bool searchByStat(string stat, string value);
	bool removePC(string name);
	void display();
	bool setStatInt(string inputname, string stat, int value);
	bool setStatStr(string name, string stat, string value);

};

#endif
