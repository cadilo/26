#include "List.h"
#include "Error.h"

//конструктор по умолчанию
List::List()
{
	size = 0;
	head = nullptr;
}
//конструктор, создающий n элементов со значением d
List::List(int n, int d)
{
	head = new Node(d);
	Node* temp = new Node(d);
	head->pNext = temp;
	for (int i = 2; i < n; i++)
	{
		temp->pNext = new Node(d);
		temp = temp->pNext;
	}
	size = n;
}

//деструктор
List::~List()
{
	clear();
}

//добавление в конец списка
void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;
}

//очистка списка
void List::clear()
{
	while (size != 0)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

//доступ к элементу списка по индексу
int& List::operator[](const int index)
{
	if (index < 0) throw IndexError1();
	if (index >= this->size) throw IndexError2();
	int count = 0;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}

//переход вправо к элементу с номером n
int& List::operator+(int n)
{
	if (n < 1 ) throw TransitionError2();
	if (n > this->size) throw TransitionError1();
	int i = 1;
	Node* temp = this->head;
	while (i != n)
	{
		temp = temp->pNext;
		i++;
	}
	return temp->data;
}

//операция, которая возвращает размер списка
int List::operator()()
{
	return size;
}

//перегрузка оператора присваивания
List& List::operator=(List& a)
{
	if (this == &a)
		return *this;
	size = a.size;
	if (head != nullptr)
		clear();
	Node* temp = a.head;
	this->push_back(temp->data);
	temp = temp->pNext;
	while (temp != nullptr)
	{
		this->push_back(temp->data);
		temp = temp->pNext;
	}
	return *this;
}

//перегрузки ввода-вывода
ostream& operator<<(ostream& out, const List& a)
{
	if (a.size == 0) cout << "List is empty\n";
	List::Node* p = a.head;
	while (p != nullptr)
	{
		out << p->data << ' ';
		p = p->pNext;
	}
	return out;
}

istream& operator>>(istream& in, List& a)
{
	List::Node* p = a.head;
	while (p != nullptr)
	{
		in >> p->data;
		p = p->pNext;
	}
	return in;
}

