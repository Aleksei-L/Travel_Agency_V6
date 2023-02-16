#include "Client.h"
#include <string.h>

// Конструктор клиента по умолчанию
Client::Client() {
	name = new char[1];
	name[0] = '\0';
	city[0] = '\0';
	phone = 0;
	age = 0.0;
}

// Конструктор клиента с заданными параметрами полей
Client::Client(const char* n, const char* c, int p, int a) {
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);

	strcpy_s(city, 30, c);

	phone = p;

	age = a;
}

// Конструктор копирования
Client::Client(const Client& t) {
	name = new char[strlen(t.name) + 1];
	strcpy_s(name, strlen(t.name) + 1, t.name);

	strcpy_s(city, 30, t.city);

	phone = t.phone;

	age = t.age;
}

// Освобождение памяти из-под клиента
void Client::dispose() {
	delete[] name;
}

// Деструктор клиента
Client::~Client() {
	dispose();
}

// Ввод информации про клиента
int Client::input() {
	char buf[256];

	std::cout << "Enter client name: ";
	std::cin.getline(buf, 254, '\n');
	if (strlen(buf) == 0)
		std::cin.getline(buf, 254, '\n');
	delete[] name;
	name = new char[strlen(buf) + 1];
	strcpy_s(name, strlen(buf) + 1, buf);

	std::cout << "Enter city: ";
	std::cin.getline(city, 28, '\n');

	if (strlen(buf) == 0)
		std::cin.getline(city, 28, '\n');

	std::cout << "Enter phone: ";
	std::cin >> phone;

	std::cout << "Enter age: ";
	std::cin >> age;

	return !std::cin.eof();
}

// Вывод информации про клиента
void Client::output() {
	std::cout << "Client name: " << name << std::endl;
	std::cout << "City: " << city << std::endl;
	std::cout << "Phone: " << phone << std::endl;
	std::cout << "Age: " << age << std::endl;
}

// Разница между клиентами
int Client::cmp(const Client& b) {
	int cond;
	if ((cond = strcmp(name, b.name)) != 0)
		return cond;
	else if ((cond = strcmp(city, b.city)) != 0)
		return cond;
	else if ((cond = phone - b.phone) != 0)
		return cond;
	else if ((cond = age - b.age) != 0)
		return cond;
	return 0;
}

// Проверка клиентов на равенство
int Client::equal(const Client& t) {
	return !strcmp(name, t.name) && !strcmp(city, t.city) && (phone == t.phone) && (age == t.age);
}

// Создание копии объекта в динамической памяти
Client* Client::copy() {
	return new Client(*this);
}
