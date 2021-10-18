#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "StackNode.h"

using namespace std;
//Для выполнения задания использовал структуры которые писал давно в целях обучения
// https://github.com/bzzbzzbee/DataStrustures.git
int SIZE = 20, RANDOM = 1, ASCENDING = 2, DESCENDING = 3;

void fillLists(int mode, StackNode<int>& stack, Queue<int>& queue) {

	switch (mode) {
	case 1:
		for (size_t i = 0; i < SIZE; i++) {
			int num = rand() % 100 + 1;
			stack.push(num);
			queue.enqueue(num);
		}
		break;
	case 2:
		for (size_t i = 0; i < SIZE; i++) {
			stack.push(i);
			queue.enqueue(i);
		}
		break;
	case 3:
		for (size_t i = SIZE; i > 0; i--) {
			stack.push(i);
			queue.enqueue(i);
		}
		break;

	default:
		break;
	}
}

template <typename T>
void printQueue(const Queue<T> & queue) {
	Queue<T> *temp_q = new Queue<T>(queue);

	while (!temp_q->isEmpty()) {
		cout << temp_q->dequeue() << endl;
	}
}

template <typename T>
void printStack(const StackNode<T>& stack) {
	StackNode<T>* temp_s = new StackNode<T>(stack);

	while (!temp_s->isEmpty()) {
		cout << temp_s->pop() << endl;
	}
}

int sumStack(const StackNode<int>& stack) {
	StackNode<int>* temp_s = new StackNode<int>(stack);
	int sum = 0;

	while (!temp_s->isEmpty()) {
		sum += temp_s->pop();
	}
	return sum;
}

int sumQueue(const Queue<int>& queue) {
	Queue<int>* temp_q = new Queue<int>(queue);
	int sum = 0;

	while (!temp_q->isEmpty()) {
		sum += temp_q->dequeue();
	}
	return sum;
}

int seriesQueue(const Queue<int>& queue) {
	Queue<int>* temp_q = new Queue<int>(queue);
	
	int tmp = temp_q->dequeue();
	int num = 0;
	while (!temp_q->isEmpty()) {
		if (tmp != temp_q->dequeue())
			num++;

	}
	return num;
}

int main() {
	srand(time(NULL));

	auto q = new Queue<int>();
	auto s = new StackNode<int>();

	fillLists(1, *s, *q);

	printQueue<int>(*q);
	cout << "------------" << endl;
	printStack<int>(*s);
}