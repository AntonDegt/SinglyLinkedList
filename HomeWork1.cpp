#include <iostream>
#include "header.h"
using namespace std;

struct SinglyLinkedList::Node
{
	int data = 0;
	Node* next = nullptr;
};

SinglyLinkedList::~SinglyLinkedList(void)
{
	Clear();
}

void SinglyLinkedList::AddToHead(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	newElem->next = head;
	if (head == nullptr)
	{
		tail = newElem;
	}
	head = newElem;
	count++;
}
void SinglyLinkedList::AddToTail(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	if (tail == nullptr)
	{
		head = newElem;
	}
	else
	{
		tail->next = newElem;
	}
	tail = newElem;
	count++;
}
void SinglyLinkedList::InsertInto(int data, int position)
{
	if (position >= count)
	{
		AddToTail(data);
		return;
	}
	else if (position <= 0)
	{
		AddToHead(data);
		return;
	}

	Node* newElem = new Node();
	newElem->data = data;
	int i = 1;
	Node* beforeNew = head;
	while (i++ != position)
	{
		beforeNew = beforeNew->next;
	}
	newElem->next = beforeNew->next;
	beforeNew->next = newElem;

	count++;
}
void SinglyLinkedList::DeleteFromHead()
{
	if (count == 0)
	{
		// cout << "Empty list!\n";
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	count--;
	if (head == nullptr)
	{
		tail = nullptr;
	}
}
void SinglyLinkedList::DeleteFromTail()
{
	if (count == 0) {
		// cout << "Empty list!\n";
		return;
	}
}
void SinglyLinkedList::DeleteByIndex(int position)
{
	if (position <= 0)
	{
		DeleteFromHead();
		return;
	}

	if (position >= count)
	{
		position = count - 1;
	}

	int i = 1;
	Node* beforeDel = head;
	while (i++ != position)
	{
		beforeDel = beforeDel->next;
	}
	Node* sacrifice = beforeDel->next;
	beforeDel->next = sacrifice->next;
	delete sacrifice;
	count--;
	if (beforeDel->next == nullptr)
	{
		tail = beforeDel;
	}
}

void SinglyLinkedList::Clear()
{
	while (head != nullptr)
	{
		DeleteFromHead();
	}
}
void SinglyLinkedList::Print() const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
int SinglyLinkedList::GetCount() const
{
	return count;
}
int SinglyLinkedList::IndexOf(int data) const
{
	if (count == 0)
	{
		// cout << "Empty list!\n";
		return -1;
	}
	Node* temp = head;
	int i = 0;
	while (i < count)
	{
		if (data == temp->data)
		{
			return i;
		}
		i++;
		temp = temp->next;
	}

	return -1;
}


int main()
{
	SinglyLinkedList sll;
	sll.AddToTail(10);
	sll.AddToTail(20);
	sll.AddToTail(30);
	sll.AddToTail(40);

	sll.DeleteByIndex(1);
	sll.Print();
	
	return 0;
}
