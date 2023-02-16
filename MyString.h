#pragma once
#include <iostream>
#include <string.h>

class MyString {
	char* s; // ”казатель на строку
	int len; // ƒлина строки
public:
	MyString();
	MyString(const MyString&);
	MyString(char*);
	~MyString();
	char& item(int);
	MyString* copy();
	void assign(const MyString&);
	int cmp(const MyString&);
	int equal(const MyString&);
	int input();
	int output();
};
