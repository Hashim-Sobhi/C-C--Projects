#include <iostream>
#include <string>

#include "queue.h"
using namespace std;


int main()
{
	queue<string>x;
	x.dequeue();
	x.enqueue("a");
	x.enqueue("b");
	x.enqueue("c");
	x.enqueue("d");
	x.dequeue();
	x.dequeue();
	x.dequeue();
	x.dequeue();
	x.dequeue();
	x.dequeue();
	x.enqueue("d");
	x.enqueue("c");
	x.dequeue();
	x.dequeue();
	x.dequeue();
	x.dequeue();
}