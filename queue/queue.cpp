#include "queue.h"
#include <iostream>
#include <string>


using namespace std;
template <class QueueElemType>
queue<QueueElemType>::queue()
{
	qfront = qrear = NULL;
}

template <class QueueElemType>
bool queue<QueueElemType>::enqueue(const QueueElemType& e)
{
	node* addednode = new node;
	addednode->elem = e;
	addednode->next = NULL;
	if (qfront == NULL)
	{
		qfront = addednode;
	}
	else
	{
		qrear->next = addednode;
	}
	qrear = addednode;
	return true;
}
template <class QueueElemType>
bool queue<QueueElemType>::dequeue()
{
	if (qfront == NULL)
	{
		cout << "queue is empty" << endl;
	}
	else
	{
		cout << "Q: " << qfront->elem << endl;
		node* temp = qfront;
		qfront = qfront->next;
		delete temp;
	}
	return true;
	
}