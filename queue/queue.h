#ifndef _QUEUE_H_
#define _QUEUE_H_
template <class QueueElemType>
class queue
{
private:
	struct node
	{
		QueueElemType elem;
		node* next;
	};
	node* qfront;
	node* qrear;
public:
	queue();
	~queue();
	bool enqueue(const QueueElemType& e);
	bool dequeue();
	QueueElemType front();
	bool isEmpty();
};


#endif

