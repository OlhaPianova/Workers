#pragma once
#include<string>
using namespace std;
struct Worker {
	string name;
	string surname;
	string age;
	string job_position;
	string experience;
	string phone_numb;
	string email;
};


void init();
void addWorkers();
void listWorkers();
void search_by_surname();
void insertWorker(Worker data);
void search_by_age();
void edit();
void delete_worker();
