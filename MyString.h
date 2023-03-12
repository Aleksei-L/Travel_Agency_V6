#pragma once
#include <iostream>
#include <string.h>

class MyString {
private:
	char* s; // Указатель на строку
	char* cur; // Указатель на первый свободный элемент
	int len; // Длина строки
public:
	MyString();
	MyString(const MyString& t);
	MyString(char* t);
	~MyString();
	int length() { return len; }
	int length() const { return len; }
	char& item(int);
	MyString* copy();
	void assign(const MyString&);
	int cmp(const MyString&);
	int equal(const MyString&);
	int input();
	int output();
	// Начало новых функций
	void resize(int newsize);
	int insert(int pos, const MyString& item);
};
