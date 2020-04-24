#include "Sotrudniki.h"
#include <iostream>
#include <string>
#include<Windows.h>
#include <fstream>
using namespace std;

#define SLEEP Sleep(1000);
Worker* arrWorkers;
int countWorker = 0;
const string fileName = "our_workers.txt";

void insertWorker(Worker data)
{
	Worker* temp = new Worker[countWorker + 1];
	for (int i = 0; i < countWorker; i++)
	{
		temp[i] = arrWorkers[i];
	}
	temp[countWorker] = data;
	countWorker++;
	arrWorkers = new Worker[countWorker];
	for (int i = 0; i < countWorker; i++)
	{
		arrWorkers[i] = temp[i];
	}
	delete[]temp;
}
void search_by_age()
{
	string search_age;
	cout << "Enter surname of the worker for search: ";
	cin >> search_age;
	for (int i = 0; i < countWorker; i++)
	{
		if (arrWorkers[i].surname.find(search_age) != string::npos) {
			cout << i + 1 << " " << arrWorkers[i].name;
			cout << " " << arrWorkers[i].surname << endl;
			cout << arrWorkers[i].age << endl;
			cout << arrWorkers[i].job_position << endl;
			cout << arrWorkers[i].experience << endl;
			cout << arrWorkers[i].phone_numb << endl;
			cout << arrWorkers[i].email << endl;
		}
	}
}
void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			Worker temp;
			fin.ignore();
			getline(fin, temp.name);
			if (temp.name != "") {
				fin >> temp.surname;
				fin >> temp.age;
				fin >> temp.job_position;
				fin >> temp.experience;
				fin >> temp.phone_numb;
				fin >> temp.email;

				insertWorker(temp);
			}
			else {
				break;
			}

		}
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}

void addWorkers()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {

		Worker newWorker;
		cout << "Enter worker's name: ";
		cin>> newWorker.name;
		cout << "Enter worker's surname: ";
		cin>> newWorker.surname;
		cout << "Enter worker's age: ";
		cin>> newWorker.age;
		cout << "Enter worker's job_position: ";
		cin>> newWorker.job_position;
		cout << "Enter worker's experience: ";
		cin>> newWorker.experience;
		cout << "Enter worker's phone_numb:";
		cin>> newWorker.phone_numb;
		cout << "Enter worker's email:";
		cin>> newWorker.email;

		insertWorker(newWorker);

		fout << newWorker.name << endl;
		fout << newWorker.surname << endl;
		fout << newWorker.age << endl;
		fout << newWorker.job_position << endl;
		fout << newWorker.experience << endl;
		fout << newWorker.phone_numb << endl;
		fout << newWorker.email<< endl;

		fout.close();
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}

void listWorkers()
{
	cout << "\t\t\tAll workers:" << endl;
	for (int i = 0; i < countWorker; i++)
	{
			cout << i + 1 << ". " << arrWorkers[i].name;
			cout << " " << arrWorkers[i].surname << endl;
	}
	cout << endl;
}

void search_by_surname()
{
	string infa;
	cout << "Enter surname of the worker for search: ";
	cin >> infa; 
	for (int i = 0; i < countWorker; i++)
	{
		if (arrWorkers[i].surname.find(infa) != string::npos) {
			cout<<i+1 <<" "<< arrWorkers[i].name ;
			cout <<" "<< arrWorkers[i].surname << endl;
			cout << arrWorkers[i].age << endl;
			cout << arrWorkers[i].job_position << endl;
			cout << arrWorkers[i].experience << endl;
			cout << arrWorkers[i].phone_numb << endl;
			cout << arrWorkers[i].email << endl;
		}
	}
}
void edit()
{
	listWorkers();
	cout << "Select workers number do you want to edit :_ " << endl;
	int workersNumb = 0;
	cin >> workersNumb;

	ofstream fout;
	fout.open(fileName);
	bool isOpen = fout.is_open();
	if (isOpen == true) {

		Worker* temp = new Worker[countWorker];
		for (int i = 0; i < countWorker; i++)
		{
			temp[i] = arrWorkers[i];
		}

		cout << "Enter new details for this worker:" << endl;
		cout << "Name: " << endl;
		temp[workersNumb - 1].name == "";
		cin >> temp[workersNumb - 1].name;
		cout << "Surname: " << endl;
		temp[workersNumb - 1].surname == "";
		cin >> temp[workersNumb - 1].surname;
		cout << "Age: " << endl;
		temp[workersNumb - 1].age == "";
		cin >> temp[workersNumb - 1].age;
		cout << "Job position: " << endl;
		temp[workersNumb - 1].job_position == "";
		cin >> temp[workersNumb - 1].job_position;
		cout << "Experience: " << endl;
		temp[workersNumb - 1].experience == "";
		cin >> temp[workersNumb - 1].experience;
		cout << "Phone number: " << endl;
		temp[workersNumb - 1].phone_numb == "";
		cin >> temp[workersNumb - 1].phone_numb;
		cout << "Email: " << endl;
		temp[workersNumb - 1].email == "";
		cin >> temp[workersNumb - 1].email;
		for (int i = 0; i < countWorker;i++) {
			fout << temp[i].name << endl;
			fout << temp[i].surname << endl;
			fout << temp[i].age << endl;
			fout << temp[i].job_position << endl;
			fout << temp[i].experience << endl;
			fout << temp[i].phone_numb << endl;
			fout << temp[i].email << endl;
		}
		
		for (int i = 0; i < countWorker; i++)
		{
			arrWorkers[i] = temp[i];
		}
		delete[]temp;
		fout.close();
	}
	else {
		cout << "Application can't open data file!" << endl;
	}
}

void delete_worker()
{
	listWorkers();
	cout << "Select workers number do you want to delete :_ " << endl;
	int workersNumb = 0;
	cin >> workersNumb;
	workersNumb--;
	ofstream fout;
	fout.open(fileName);
	bool isOpen = fout.is_open();
	if (isOpen == true) {

		Worker* temp = new Worker[countWorker];
		for (int i = 0; i < countWorker; i++)
		{
			if (i!= workersNumb) {
				temp[i] = arrWorkers[i];
			}
		}
	
		countWorker--;
		arrWorkers = new Worker[countWorker];
		for (int i = 0; i < countWorker; i++)
		{
			if (temp[i].name != "") {
				arrWorkers[i] = temp[i];
			}

		}
		for (int i = 0; i < countWorker; i++) {
			fout << temp[i].name << endl;
			fout << temp[i].surname << endl;
			fout << temp[i].age << endl;
			fout << temp[i].job_position << endl;
			fout << temp[i].experience << endl;
			fout << temp[i].phone_numb << endl;
			fout << temp[i].email << endl;
		}
		delete[]temp;
		fout.close();
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}

