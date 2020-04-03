#include"Sotrudniki.h"
#include<iostream>
#include<string>
using namespace std;

#define CLEAR system("cls");

int main() {
	int count;
	init();
	int action = 0;
	do
	{
		cout << "\tMENU:" << endl;
		cout << "1. Add new worker" << endl;
		cout << "2. Show all workers" << endl;
		cout << "3. Search and edit" << endl;

		cout << "4. Exit" << endl;
		cout << endl;
		cout << "Select action: ";
		cin >> action;

		switch (action) {
		case 1: {
			CLEAR;
			cout << "ADD NEW WORKER :" << endl;
			addWorkers();
		}break;
		case 2: {
			CLEAR;
			listWorkers();
		}break;
		case 3: {
			CLEAR;

		}break;
		case 4: {
			CLEAR;
			cout << "Bye" << endl;
			break;
		}
		default: {
			cout << "Please select action (1 - 4)" << endl;
		}
		}

	} while (action != 4);



	system("pause");
	return 0;
}