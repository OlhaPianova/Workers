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

struct Info {
	Worker* OfficeWorker;
	int Count;
};
void init();
void addWorkers();
void listWorkers();
void search_edit();
void insertWorker(Info W);
