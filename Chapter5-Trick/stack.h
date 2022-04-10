#pragma once
#include <stdexcept>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

/*
* ��Աģ��
* ���ԱҲ������ģ�壬Ƕ����ͳ�Ա������������Ϊģ��
*/

template<typename T,typename CONT =std::deque<T> >
class Stack
{
public:
	void push(T const& elem)
	{
		elems_.push_back(elem);
	}
	void pop()
	{
		if (empty())
			throw out_of_range{ "Stack<>::pop() empty stack" };
		elems_.pop_back();
	}
	T top()const
	{
		if (empty())
			throw out_of_range{ "Stack<>::pop() empty stack" };
		return elems_.back();
	}
	bool empty()const {
		return elems_.empty();
	}


	template<typename T2, typename CONT2>
	Stack<T,CONT>& operator=(Stack<T2,CONT2> const&);
private:
	CONT elems_;
};

template<typename T,typename CONT>
template<typename T2,typename CONT2>
Stack<T,CONT>& Stack<T,CONT>::operator=(Stack<T2,CONT2> const& op2)
{
	if ((void*)this == (void*)&op2)
		return *this;

	Stack<T2,CONT2> tmp(op2);

	elems_.clear();
	while (!tmp.empty())
	{
		elems_.push_front(static_cast<T>(tmp.top())); //FILO  ǿ������ת��,
		tmp.pop();
	}
	return *this;
}

void stack_test1()
{
	Stack<int> intStack;
	intStack.push(32);
	intStack.push(35);
	Stack<float,std::deque<float> > floatStack;
	floatStack = intStack; //intתfloat
	
	while (!floatStack.empty())
	{
		cout << floatStack.top() << "\t";
		floatStack.pop();
	}
	cout << "\n";

	//Stack<string> strStack;
	//strStack = intStack; // int�޷�תΪstring
}
