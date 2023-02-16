#include "Table.h"
#include <algorithm>

// Конструктор таблицы
Table::Table(int s) {
	current = m = new T[size = s];
}

// Деструктор таблицы
Table::~Table() {
	Clear();
	delete[] m;
}

// Возвращает указатель на первый элемент таблицы
T* Table::Begin() {
	return m;
}

// Возвращает указатель на первый свободный элемент таблицы
T* Table::End() {
	return current;
}

// Возвращает размер заполненной части таблицы
int Table::Length() {
	return current - m;
}

// Возвращает общий размер таблицы
int Table::GetSize() {
	return size;
}

// Удаление одного элемента в таблице (по индексу)
T* Table::Erase(T* pos) {
	(*pos)->dispose();
	for (T* i = pos; i < End(); i++)
		*i = *(i + 1);
	current--;
	return pos;
}

// Удаление всех элементов в таблице
void Table::Clear() {
	for (T* i = m; i < current; i++) {
		delete (*i);
	}
	current = m;
}

// Увеличение размера таблицы на plusSize элементов
void Table::Resize(int plusSize) {
	if (plusSize <= 0) {
		std::cout << "Wrong size!" << std::endl;
		return;
	}
	T* newM = new T[size + plusSize];
	for (int i = 0; i < size; i++)
		newM[i] = m[i];
	current = &newM[size];
	size = size + plusSize;
	delete[] m;
	m = newM;
}

// Вставка нового клиента в таблицу
T* Table::Insert(const T& newClient) {
	if (Length() < size)
		*current++ = newClient->copy();
	return current;
}

// Ввод таблицы
int Table::Input(T item) {
	int count;
	if (Length() == GetSize()) {
		std::cout << "Size over, enter new size: ";
		int newSize;
		std::cin >> newSize;
		Resize(newSize * 2);
	}
	for (count = 0; Length() != GetSize(); count++) {
		if (!item->input())
			break;
		Insert(item);
	}
	return count;
}

// Вывод таблицы
void Table::Output() {
	bool flag = false;
	int counter = 1;
	for (T* i = Begin(); i != End(); i++) {
		std::cout << "Client #" << counter++ << std::endl;
		(*i)->output();
		flag = true;
		std::cout << std::endl;
	}
	if (!flag)
		std::cout << "There is no to output!" << std::endl;
}

// Сортировка таблицы
void Table::Sort() {
	for (int i = 0; i < GetSize(); i++) {
		for (int j = i + 1; j < GetSize(); j++) {
			if (m[i]->cmp(*m[j]) > 0)
				std::swap(m[i], m[j]);
		}
	}
}

// Поиск клиента в таблице, возвращает индекс найденного клиента или -1 если клиент не найден
int Table::Search(const T& tempClient) {
	for (T* i = Begin(); i < End(); i++) {
		if ((*i)->equal(*tempClient))
			return i - Begin();
	}
	return -1;
}

// Удаление массива элементов в таблице
T* Table::Erase(T* first, T* last) {
	for (T* i = first; i < last; i++) {
		(*first)->dispose();
		for (T* j = first; j < End(); j++)
			*j = *(j + 1);
		current--;
	}
	return last;
}

// Замена клиента в таблице
int Table::Replace(const T& oldClient, const T& newClient) {
	int counter = 0;
	for (T* i = Begin(); i < End(); i++) {
		if ((*i)->equal(*oldClient)) {
			(*i)->dispose();
			(*i) = (newClient)->copy();
			counter++;
		}
	}
	return counter;
}

// Удаление всех вхождений
int Table::Remove(const T& badClient) {
	T* i = Begin();
	int n = 0;
	for (T* j = Begin(); j < End(); j++) {
		if (!(*j)->equal(*badClient)) {
			*i++ = *j;
		}
		else {
			(*j)->dispose();
			n++;
		}
	}
	current = i;
	return n;
}

// Вставка массива клиентов в таблицу
T* Table::Insert(T* pos, T* first_item, T* last_item) {
	for (T* i = m; i < current; i++) {
		if (i == pos) {
			for (T* j = first_item; j <= last_item; j++) {
				*current++ = (*(current - 1))->copy();
				for (T* k = current - 2; k > i; k--)
					*k = (*(k - 1))->copy();
				*i++ = (*j)->copy();
			}
		}
	}
	return current;
}

// Удаление всех клиентов содержащихся в массиве из таблицы в интервале first - last
int Table::Remove(T* first, T* last, T* first_item, T* last_item) {
	T* i = first, * badInterval = Search(first, last, first_item, last_item);

	if (badInterval == NULL)
		return 0;

	int n = last_item - first_item + 1, shift = 0;

	for (T* j = first; j < last; j++) {
		if (!(*j)->equal(**badInterval)) {
			*i++ = *j;
		}
		else {
			while (shift != n) {
				(*j)->dispose();
				*j = *(j + shift + 1);
				shift++;
			}
			current = j + 1;
			return n;
		}
	}
	return n;
}

// Поиск в таблице массива first_item - last_item
T* Table::Search(T* first, T* last, T* first_item, T* last_item) {
	for (T* i = first; i < last; i++) {
		if ((*i)->equal(**first_item)) {
			int shift = 0;
			bool flag = false;
			for (T* j = first_item; j <= last_item; j++) {
				if ((*j)->equal(**(i + shift))) {
					if (j == last_item && !flag)
						return i;
					shift++;
				}
				else {
					shift++;
					flag = true;
				}
			}
		}
	}
	return NULL;
}

// Возвращает указатель на i-тую ячейку таблицы
T* Table::GetPntr(int i) {
	return &m[i];
}

// Возвращает индекс элемента в таблице по указатею на этот элемент
int Table::Describe(T* pntr) {
	return pntr - Begin();
}

// Замена всех вхождений клиента в таблице с индекса first по индекс last(не включительно)
int Table::Replace(T* first, T* last, const T& oldClient, const T& newClient) {
	int counter = 0;
	for (T* i = first; i < last; i++) {
		if ((*i)->equal(*oldClient)) {
			(*i)->dispose();
			(*i) = (newClient)->copy();
			counter++;
		}
	}
	return counter;
}

// Сортировка таблицы с индекса first, по индекс last(не включительно)
void Table::Sort(int first, int last) {
	if (first < 0 || last > GetSize() - 1) {
		std::cout << "Error!" << std::endl;
		return;
	}
	for (int i = first; i < last; i++) {
		for (int j = i + 1; j < last; j++) {
			if (m[i]->cmp(*m[j]) > 0)
				std::swap(m[i], m[j]);
		}
	}
}
