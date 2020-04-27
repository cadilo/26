#pragma once
#include <iostream>
using namespace std;

class List
{
public:
	List();
	List(int n, int d);
	~List();
	void push_back(int data);
	void clear();

	int operator()();
	List& operator=(List& a);
	int& operator+(int n);

	friend ostream& operator<<(ostream& out, const List& a);
	friend istream& operator>>(istream& in, List& a);

	int& operator [] (const int index);
private:
	class Node
	{
	public:
		Node* pNext;
		int data;
		Node* operator*(Node* a)
		{
			Node* temp;
			temp->data = this->data * a->data;
			return temp;
		}
		Node(int data, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node* head;
};