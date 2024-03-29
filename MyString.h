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
	MyString(const char* t);
	~MyString();
	int length();
	int length() const;
	char& item(int i);
	MyString* copy();
	void assign(const MyString& t);
	int cmp(const MyString& t);
	int equal(const MyString& t);
	int input();
	int output();
	// Начало новых функций
	void resize(int newsize);
	int find(int first, int last, const MyString& item);
	MyString substring(int pos, int count);
	int erase(int pos, int count);
	int insert(int pos, const MyString& item);
	int remove(int first, int last, const MyString& item);
	int replace(int first, int last, const MyString& oldString, const MyString& newString);
	MyString* split(int& count, char c = ' ');
	MyString* split(const MyString& splits, int& count);
	static MyString concate(const MyString& s1, const MyString& s2);
	static MyString concate(MyString* arr, int count);
	static MyString join(MyString* arr, int count, char c = ' ');
};
