#include "Node.h"
#include <iostream>

int main() {
	Node<char>* node;
	char x[] = "Yolo McSwag";
	node = new Node<char>(x);
	std::cout << node << (char)0x0A;
	return 0;
}