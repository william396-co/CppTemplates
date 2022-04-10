#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

#include "stack.h"
#include "default_stack.h"


void stack_test()
{

	try {
		Stack<int> intStack;
		Stack<string>stringStack;

		intStack.push(7);
		cout << intStack.top() << "\n";
		intStack.pop();


		stringStack.push("hello");
		cout << stringStack.top() << "\n";
		stringStack.pop();
		stringStack.pop();
	}
	catch (std::exception const& ex) //捕获异常
	{
		std::cerr << "Exception: " << ex.what() << "\n";		
	}
}

void default_stack_test()
{
	try
	{
		DefaultStack<int> intStack;

		DefaultStack<double, std::deque<double>> dblStack;


		intStack.push(7);
		cout << intStack.top() << "\n";
		intStack.pop();


		dblStack.push(43.4);
		cout << dblStack.top() << "\n";
		dblStack.pop();
		dblStack.pop();
	}
	catch (std::exception const& ex)
	{
		std::cerr << "Exception:" << ex.what() << "\n";
	}
}


int main()
{
	printf("Class Template\n");

	default_stack_test();
	//stack_test();

	return 0;
}

/*
* 1 类模板是具有如下性质的类： 在类的实现中，可以又一个或多个类型还没有指定
* 2 为了使用类模板，你可以传入某个具体类型作为模板实参，然后编译器将会基于该类型来实例化模板
* 3 对于模板类型而已，只有那些被调用的成员函数才会被实例化
* 4 你可以用特定类型特例化模板
* 5 你可以为了目标的参数定义缺省值，这些值还可以引用之前的模板参数
*/