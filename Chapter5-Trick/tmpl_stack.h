#pragma once
#include <deque>
#include <iostream>
#include <stdexcept>
#include <memory>
using namespace std;

/*
* 模板的模板参数
*/

//template<typename T, 
	//template<typename> class CONT= std::deque >//error template CONT 与template<>deque 类型不匹配


	//template<typename _Ty, typename _Alloc = allocator<_Ty> > class CONT = std::deque >//因为 _Ty _Alloc 未使用，可以省略
template<typename T,
	template<typename ELEM, typename Alloc = std::allocator<ELEM>> class CONT = std::deque >
class TmplStack
{
public:
	void push(T const& elem);
	void pop();
	T top()const;
	bool empty() const{ return elems_.empty(); }


	//赋值运算符	
	template<typename T2,
		template<typename ELEM ,typename Alloc=std::allocator<ELEM>> class CONT2>
	TmplStack<T, CONT>& operator=(TmplStack<T2, CONT2>const&);

private:
	CONT<T> elems_;
};

template<typename T, template<typename,typename> class CONT>
template<typename T2,
	template<typename ELEM, typename Alloc/*=std::allocator<ELEM>*/> class CONT2>
TmplStack<T, CONT>&
TmplStack<T,CONT>::operator=(TmplStack<T2 , CONT2>const& op2)
{
	if ((void*)this == (void*)&op2)
		return *this;

	TmplStack<T2, CONT2> tmp(op2);
	elems_.clear();
	while (!tmp.empty())
	{
		elems_.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}

template<typename T,
	template<typename,typename> class CONT/*= std::deque */>
T TmplStack<T, CONT>::top() const
{
	if (empty())
		throw out_of_range{ "Stack<>::top() empty stack" };
	return elems_.back();
}

template<typename T,
	template<typename, typename> class CONT/*= std::deque */>
void TmplStack<T, CONT>::pop()
{
	if (empty())
		throw out_of_range{ "Stack<>::pop() empty stack" };
	elems_.pop_back();
}

template<typename T,
	template<typename, typename> class CONT/*= std::deque */>
void TmplStack<T, CONT>::push(T const& elem)
{
	elems_.push_back(elem);
}


void stack_test2()
{
	try
	{

		TmplStack<int> intStack;
		TmplStack<float> floatStack;

		intStack.push(42);
		intStack.push(7);

		floatStack.push(7.7);

		floatStack = intStack;

		cout << floatStack.top() << "\n";
		floatStack.pop();

		cout << floatStack.top() << "\n";
		floatStack.pop();

		cout << floatStack.top() << "\n";
		floatStack.pop();
	}
	catch (std::exception const& ex)
	{
		cerr << "Exception: " << ex.what() << "\n";
	}

}
