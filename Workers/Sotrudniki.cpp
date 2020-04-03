#include "Sotrudniki.h"
#include <iostream>
#include <string>
#include<Windows.h>
#include <fstream>
using namespace std;

#define SLEEP Sleep(1000);

Info* arrWorkers;
int countWorkers = 0;

void insertWorker(Info W){
Info* temp = new Info[countWorkers + 1];
	for (int i = 0; i < countWorkers; i++)
		 {
		temp[i] = arrWorkers[i];
		}
	temp[countWorkers] = W;
		countWorkers++;
	arrWorkers = new Info[countWorkers];
for (int i = 0; i < countWorkers; i++)
		 {
		arrWorkers[i] = temp[i];
		}
	delete[]temp;
	}
void addWorkers() {

	ofstream fout;
	fout.open("our_workers.txt", fstream::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;

	}
	else {
		Info* temp = new Info[countWorkers + 1];
		for (int i = 0; i < countWorkers; i++) {
			temp[i] = arrWorkers[i];
		}
		int count = 0;
		cout << "How many workers do you want to add? " << endl;
		cin >> count;
		temp[countWorkers].Count = count;
		temp[countWorkers].OfficeWorker = new Worker[count];
		for (int i = 0; i < count; i++) {
			cout << endl;
			cout << "Enter workers name: " << endl;
			cin >> temp[countWorkers].OfficeWorker[i].name;
			cout << "Enter workers surname: " << endl;
			cin >> temp[countWorkers].OfficeWorker[i].surname;
			cout << "Enter workers age : " << endl;
			cin >> temp[countWorkers].OfficeWorker[i].age;
			cout << "Enter workers job position: " << endl;
			cin >> temp[countWorkers].OfficeWorker[i].job_position;
			cout << "Enter workers experience: " << endl;
			cin >> temp[countWorkers].OfficeWorker[i].experience;
			cout << "Enter workers phone number: " << endl;
			cin >> temp[countWorkers].OfficeWorker[i].phone_numb;
			cout << "Enter workers email: " << endl;
			cin >> temp[countWorkers].OfficeWorker[i].email;

		}
		fout << temp[countWorkers].Count << endl;
		for (int i = 0; i < temp[countWorkers].Count; i++) {
			fout << temp[countWorkers].OfficeWorker[i].name << endl;
			fout << temp[countWorkers].OfficeWorker[i].surname << endl;
			fout << temp[countWorkers].OfficeWorker[i].age<< endl;
			fout << temp[countWorkers].OfficeWorker[i].job_position<< endl;
			fout << temp[countWorkers].OfficeWorker[i].experience<< endl;
			fout << temp[countWorkers].OfficeWorker[i].phone_numb << endl << endl;
			fout << temp[countWorkers].OfficeWorker[i].email<< endl;
		}
		countWorkers++;
		arrWorkers = new Info[countWorkers];
		for (int i = 0; i < countWorkers; i++) {
			arrWorkers[i] = temp[i];
		}
		delete[] temp;
	}
	fout.close();
}
void init(){
	ifstream fin;
	fin.open("our_workers.txt");
	bool isOpen = fin.is_open();
	if (isOpen == true) {
		while (!fin.eof()) {
			Info getInfo;
			fin >> getInfo.Count;
			string t = "";
			fin >> t;
			int n = atoi(t.c_str());
			getInfo.OfficeWorker = new Worker[n];
			if (getInfo.Count != 0) {
				for (int i = 0; i < n; i++) {
					fin >> getInfo.OfficeWorker[i].name;
					fin >> getInfo.OfficeWorker[i].surname;
					fin >> getInfo.OfficeWorker[i].age;
					fin >> getInfo.OfficeWorker[i].job_position;
					fin >> getInfo.OfficeWorker[i].experience;
					fin >> getInfo.OfficeWorker[i].phone_numb;
					fin >> getInfo.OfficeWorker[i].email;
				}
			}
			insertWorker(getInfo);
		}
	}
	else {
		cout << "Error: applciation can't open file!" << endl;
		
	}
}


void listWorkers()
{
	cout << "\n\t\t\tWORKERS LIST: " << endl;
	cout << endl;
	for (int i = 0; i < countWorkers; i++) {
		for (int j = 0; j < arrWorkers[i].Count; j++) {
			SLEEP;
			cout << endl;
			cout << j + 1 << ". " << arrWorkers[i].OfficeWorker[j].name << endl;
			cout << arrWorkers[i].OfficeWorker[j].surname << endl;
			cout << "job position: " << " " << arrWorkers[i].OfficeWorker[j].job_position << endl;

		}
	}
	cout << endl;
}
void search_edit(){
	cout << "Enteer workers surname for search: " << endl;
	string surname = "";
	cin >> surname;

}

