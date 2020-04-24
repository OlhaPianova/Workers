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
		cout << "3. Search by surname" << endl;
		cout << "4. Search by age" << endl;
		cout << "5. Edit" << endl;
		cout << "6. Delete worker" << endl;
		cout << "7. Exit" << endl;
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
			search_by_surname();
		}break;
		case 4: {
			CLEAR;
			search_by_age();
		}break;
		case 5: {
			CLEAR;
			edit();
		}break;
		case 6: {
			CLEAR;
			delete_worker();
		}break;
		case 7: {
			CLEAR;
			cout << "\n\t\t\tBye!" << endl;
			break;
		}
		default: {
			cout << "Please select action (1 - 7)" << endl;
		}
		}

	} while (action != 7);



	system("pause");
	return 0;
}