#include "MyString.h"

// ����������� �� ���������
MyString::MyString() {
	s = new char[1];
	*s = '\0';
	len = 0;
}

// ����������� �� ������
MyString::MyString(char* t) {
	s = new char[strlen(t) + 1];
	*s = '\0';
	strcpy_s(s, strlen(t) + 1, t);
	len = strlen(t);
}

// ����������� �����������
MyString::MyString(const MyString& u) {
	s = new char[u.len + 1];
	*s = '\0';
	strcpy_s(s, strlen(u.s) + 1, u.s);
	len = u.len;
}

// ����������
MyString::~MyString() {
	delete[] s;
}

// ��������� i-���� ������� ������
char& MyString::item(int i) {
	char err = 'e';
	if (i < len && i >= 0)
		return s[i];
	else
		std::cout << "Error";
	return err;
}

// �������� ����� ������� � ������������ ������
MyString* MyString::copy() {
	return new MyString(*this);
}

// ������ �������������� ��������� =
void MyString::assign(const MyString& u) {
	s = new char[u.len + 1];
	*s = '\0';
	strcpy_s(s, strlen(u.s) + 1, u.s);
	len = u.len;
}

// ��������� ���� ����� (��������� ������)
int MyString::cmp(const MyString& t) {
	return strcmp(s, t.s);
}

// �������� ����� �� ��������� (��������� ������)
int MyString::equal(const MyString& t) {
	return strcmp(s, t.s) == 0;
}

// ���� ������
int MyString::input() {
	if (std::cin.eof())
		return 0;
	char buf1[256];
	std::cin.getline(buf1, 254, '\n');
	if (strlen(buf1) == 0)
		std::cin.getline(buf1, 254, '\n');
	s = new char[strlen(buf1) + 1];
	len = strlen(buf1);
	*s = '\0';
	strcpy_s(s, strlen(buf1) + 1, buf1);
	return 0;
}

// ����� ������ �� �����
int MyString::output() {
	std::cout << s << std::endl;
	return 0;
}
