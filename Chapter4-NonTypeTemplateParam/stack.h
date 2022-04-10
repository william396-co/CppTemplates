#pragma once
#include <stdexcept>

// 指定栈大小模板
template<typename T,int MAXSIZE>
class Stack
{
public:
	Stack();
	void push(T const& elem);
	void pop();
	T top()const;
	bool empty()const { return curr_num_ == 0; }
	bool full()const { return curr_num_ == MAXSIZE; }
private:
	T elems_[MAXSIZE];
	int curr_num_;
};

template<typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack():curr_num_{0}
{

}

template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T const& elem)
{
	if (curr_num_ == MAXSIZE)
		throw out_of_range{ "Stack<>::push(): stack is full" };

	elems_[curr_num_++] = elem;
}

template<typename T,int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
	if (curr_num_ <= 0)
		throw out_of_range{ "Stack<>::pop(): stack is empty" };

	--curr_num_;
}

template<typename T,int MAXSIZE>
T Stack<T, MAXSIZE>::top()const
{
	if (curr_num_ <= 0)
		throw out_of_range{ "Stack<>::top(): stack is empty" };
	return elems_[curr_num_-1];
}
