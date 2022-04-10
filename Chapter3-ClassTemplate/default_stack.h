#pragma once
#include <vector>
#include <stdexcept>
using namespace std;


//缺省模板实参
template<typename T,typename CONT=std::vector<T>>
class DefaultStack
{
public:
	void push(T const&);
	void pop();
	T top()const;
	bool empty() { return elems_.empty(); }
private:
	CONT elems_;
};

template<typename T, typename CONT/*=std::vector<T>*/>
T DefaultStack<T, CONT>::top() const
{
	if (elems_.empty())
		throw std::out_of_range{ "Stack2<>::top(): empty stack" };
	return elems_.back();
}

template<typename T, typename CONT/*=std::vector<T>*/>
void DefaultStack<T, CONT>::pop()
{
	if (elems_.empty())
		throw std::out_of_range{ "Stack2<>::pop(): empty stack" };
	elems_.pop_back();
}

template<typename T, typename CONT/*=std::vector<T>*/>
void DefaultStack<T, CONT>::push(T const& elem)
{
	elems_.push_back(elem);
}
