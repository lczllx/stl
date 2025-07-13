#include "priority_queue.h"
#include "reverse_iterator.h"
#include <iostream>
using namespace lcz;

void test_priority_queue_reverse() {
	priority_queue<int> pq;
	pq.push(5);
	pq.push(1);
	pq.push(10);
	pq.push(3);

	std::cout << "Reverse order: ";
	for (auto it = pq.rbegin(); it != pq.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test_priority_queue() {
	priority_queue<int> pq;
	pq.push(5);
	pq.push(1);
	pq.push(10);
	pq.push(3);

	std::cout << "Top: " << pq.top() << std::endl; // ӦΪ10
	pq.pop();
	std::cout << "Top after pop: " << pq.top() << std::endl; // ӦΪ5

	while (!pq.empty()) {
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
}

int main() {
	test_priority_queue();
	test_priority_queue_reverse();
	return 0;
}