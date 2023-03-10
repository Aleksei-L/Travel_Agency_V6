#pragma once
#include <iostream>

class Client {
private:
	char* name; // Имя клиента
	char city[30]; // Адрес клиента
	int phone; // Телефон клиента
	double age; // Возраст клиента
public:
	Client();
	Client(const char* n, const char* c, int p, int a);
	Client(const Client& t);
	void dispose();
	~Client();
	int input();
	void output();
	int cmp(const Client& t);
	int equal(const Client& t);
	Client* copy();
};

typedef Client* T; // Теперь таблица работает с абстрактным типом T
