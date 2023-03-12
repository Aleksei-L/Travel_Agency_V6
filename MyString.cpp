#include "MyString.h"
#define MAX_SIZE 32 //256

// Конструктор по умолчанию
MyString::MyString() {
	/*
	len - длина массива = фактическое кол-во символов которое туда можно поместить включая \0
	cur - указывает на \0
	*/
	len = MAX_SIZE;
	cur = s = new char[len];
	*s = '\0';
}

// Конструктор от строки
MyString::MyString(char* t) {
	s = new char[MAX_SIZE + strlen(t)];
	*s = '\0';
	strcpy_s(s, strlen(t) + 1, t);
	cur = &s[strlen(t)];
	len = MAX_SIZE + strlen(t);
}

// Конструктор копирования
MyString::MyString(const MyString& t) {
	s = new char[MAX_SIZE + t.len];
	*s = '\0';
	strcpy_s(s, strlen(t.s) + 1, t.s);
	cur = &s[strlen(t.s)];
	len = MAX_SIZE + t.len;
}

// Деструктор
MyString::~MyString() {
	delete[] s;
}

// Получение i-того символа строки
char& MyString::item(int i) {
	char err = 'e';
	if (i < len && i >= 0)
		return s[i];
	else
		std::cout << "Error" << std::endl;
	return err;
}

// Создание копии объекта в динамической памяти
MyString* MyString::copy() {
	return new MyString(*this);
}

// Замена перегруженного оператора =
void MyString::assign(const MyString& t) {
	s = new char[t.len + 1];
	*s = '\0';
	strcpy_s(s, strlen(t.s) + 1, t.s);
	cur = &s[strlen(t.s)];
	len = t.len;
}

// Сравнение двух строк
int MyString::cmp(const MyString& t) {
	return strcmp(s, t.s);
}

// Проверка строк на равенство
int MyString::equal(const MyString& t) {
	return strcmp(s, t.s) == 0;
}

// Ввод строки
int MyString::input() {
	if (std::cin.eof())
		return 0;

	char buf[MAX_SIZE];

	std::cin.getline(buf, MAX_SIZE - 2, '\n');
	if (strlen(buf) == 0)
		std::cin.getline(buf, MAX_SIZE - 2, '\n');

	s = new char[MAX_SIZE + strlen(buf)];

	len = MAX_SIZE + strlen(buf);
	*s = '\0';
	strcpy_s(s, strlen(buf) + 1, buf);
	cur = &s[strlen(buf)];
	return 0;
}

// Вывод строки на экран
int MyString::output() {
	for (char* i = s; i < cur; i++)
		std::cout << *i;
	std::cout << std::endl;
	return 0;
}

// Начало новых функций

// Изменение размера строки
void MyString::resize(int newsize) {
	/*
	В newsize передаётся новый размер, а не то на сколько его надо увеличить
	*/
	char* new_s = new char[newsize];
	strcpy_s(new_s, strlen(s) + 1, s);
	delete[] s;
	s = new_s;
	cur = &s[strlen(s)];
}

//PRB можно ли добавлять свои методы?
// Возвращает истинный размер строки без учёта '\0'
int MyString::realSize() const {
	int count = 0;
	for (char* i = s; i != cur; i++)
		count++;
	return count;
}

// Вставка строки на позицию
int MyString::insert(int pos, const MyString& item) {
	/*
	pos - отражает ЧЕЛОВЕЧЕСКИЙ номер
	pos = 1 -> вставка на первую позицию строки, вся строка сдвигается вправо
	pos = len -> вставка на предпоследнюю позицию строки, только последний символ сдвигается вправо
	pos = len + 1 -> вставка в самый конец строки, ничего не сдвигается
	*/
	// Проверка pos на правильность
	if (pos <= 0 || pos > len + 1) {
		std::cout << "Error in insert function, class MyString" << std::endl;
		return -1;
	}

	char* newString = new char[len + item.len + 1];

	// Копирование элементов до позиции вставки
	for (int i = 0; i < pos - 1; i++)
		newString[i] = s[i];

	// Копирование новой строки
	int count = 0;
	for (int i = pos - 1; item.s[i - pos + 1] != '\0'; i++) {
		newString[i] = item.s[i - pos + 1];
		count++;
	}

	// Копирование элементов после позици вставки
	for (int i = pos - 1 + count; i < realSize() + count; i++)
		newString[i] = s[i - count];

	//TODO переделать на нормальный вид
	int len1 = realSize();
	int len2 = item.realSize();

	len = len + item.len + 1;
	delete[] s;
	s = newString;
	cur = s + len1 + len2;
	*cur = '\0';

	return 0; //PRB что должна возвращать эта функция?
}

// Соединение двух строк
MyString MyString::concate(const MyString& s1, const MyString& s2) {
	MyString my(s1);
	my.insert(s1.realSize() + 1, s2);
	return my;
}
