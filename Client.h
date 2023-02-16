#pragma once
#include <iostream>

class Client {
private:
	char* name; // ��� �������
	char city[30]; // ����� �������
	int phone; // ������� �������
	double age; // ������� �������
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

typedef Client* T; // ������ ������� �������� � ����������� ����� T
