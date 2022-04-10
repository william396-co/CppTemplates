#pragma once
#include <vector>
#include <stdexcept>
using namespace std;


// 用vector实现stack
template<typename T>
class Stack
{
public:
	void push(T const& elem);
	void pop();
	T top()const;
	bool empty()const { return elems_.empty(); }
private:
	vector<T> elems_;
};


template<typename T>
T Stack<T>::top() const
{
	if(empty())
		throw std::out_of_range{ "Stack<>::top() empty stack" };
	return elems_.back();
}

template<typename T>
void Stack<T>::pop()
{
	if (empty())
		throw std::out_of_range{ "Stack<>::pop() empty stack" };
		
	elems_.pop_back();		
}

template<typename T>
void Stack<T>::push(T const& elem)
{
	elems_.push_back(elem);
}


/*
* 模板特例化
* 特例化的实现 可以和基本模板不一样
*/

#include <deque>
#include <string>
template<>
class Stack<std::string>
{
public:
	void push(string const& elem);
	void pop();
	string top()const;
	bool empty() { return elems_.empty(); }
private:
	std::deque<string> elems_;//deque实现更好(删除)
};


void Stack<string>::push(string const& elem)
{
	elems_.push_back(elem);
}

void Stack<string>::pop()
{
	if (elems_.empty())
		throw std::out_of_range{ "Stack<string>::pop() empty stack" };

	return elems_.pop_back();
}

string Stack<string>::top()const
{
	if (elems_.empty())
		throw std::out_of_range{"Stack<string>::top() empty stack"};

	return elems_.back();
}

/*
* 局部特例化
* 
*/

template<typename T1,typename T2>
class MyClass
{

};


//两个模板参数具有相同的类型
template<typename T>
class MyClass<T, T>
{

};

// 第二个参数是int
template<typename T>
class MyClass<T, int>
{

};



// 两个参数都是指针
template<typename T1,typename T2>
class MyClass<T1*, T2*>
{

};