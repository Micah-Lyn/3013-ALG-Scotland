#pragma once
#include <iostream>
#include <string>
using namespace std;


struct node {
		std::string word;
		std::string definition;
		node* next;
	};


class MyList {
	node* head;
	node* current;
	node* end;
public:
	MyList() {
		head = NULL;
		current = head;
		end = head;
	}

	void insert(std::string w, std::string d) {
		resetcursor();
		if (head == NULL) {
			head = new node;
			head->word = w;
			head->definition = d;
			end = head;
			end->next = head->next;
		}
		else {
			node* temp = new node;
			end->next = temp;
			temp->next = NULL;
			end = temp;
			end->word = w;
			end->definition = d;
		}
	}
	void resetcursor() {
		current = head;
	}
	void print() {
		resetcursor();
		while (current != NULL) {
			cout << current->word;
			if (current->next == NULL) {
				return;
			}
			cout << "->";
			current = current->next;
		}
	}
	/*
	bool search(std::string term) {
		resetcursor();
		bool found = false;
		while (current != NULL) {
			if (current->word[0] != term[0]) {
				current = current->next;
			}
			else {
				current = NULL;
			}
			while (found == true) {
				if (current->word.find(term)) {
					cout << current->word;
					current = current->next;
					found = true;
				}
				else {
					found = false;
				}
			}
			return found;
		}
	*/
};