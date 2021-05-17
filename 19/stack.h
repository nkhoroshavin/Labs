#include <iostream>
using namespace std;

class Stack
{
public:
	struct stack_
	{
		int data;
		stack_* pred;
	};
	stack_* top;
public:
	Stack();
	~Stack();
	void make(int n);
	void print();
	void add();
};