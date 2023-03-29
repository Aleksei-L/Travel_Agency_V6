#pragma once
#include <iostream>
#include <string.h>

class MyString {
private:
	char* s; // Указатель на строку
	char* cur; // Указатель на первый свободный элемент
	int len; // Длина строки
	int realSize() const;
public:
	MyString();
	MyString(const MyString& t);
	MyString(char* t);
	~MyString();
	int length() { return len; }
	int length() const { return len; }
	char& item(int i);
	MyString* copy();
	void assign(const MyString& t);
	int cmp(const MyString& t);
	int equal(const MyString& t);
	int input();
	int output();
	// Начало новых функций
	void resize(int newsize);
	int erase(int pos, int count);
	int insert(int pos, const MyString& item);
	static MyString concate(const MyString& s1, const MyString& s2);
};
