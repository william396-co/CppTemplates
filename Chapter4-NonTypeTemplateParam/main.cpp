#include <iostream>
#include <stdexcept>
using namespace std;

/*
* 非类型模板参数
*  对于函数模板和类模板，模板参数并不局限于类型，普通值也可以作为模板参数
*  
*/

#include "stack.h"

void stack_test()
{
	try
	{

		Stack<int, 20> int20Stack;
		Stack<int, 40> int40Stack;
		Stack<string, 40> str40Stack;

		int20Stack.push(7);
		cout << int20Stack.top() << "\n";
		int20Stack.pop();


		str40Stack.push("hello");
		cout << str40Stack.top() << "\n";
		str40Stack.pop();
		str40Stack.pop();

	}
	catch (std::exception const& ex)
	{
		cerr << "Exception: " << ex.what() << "\n";
	}
}


template<typename T,int VAL>
T addValue(T const& x)
{
	return x + VAL;
}

#include <vector>
#include <algorithm>
#include <functional>
void addvalue_test()
{
	vector<int> src = { 1,2,3,4,5,6 };
	vector<int> des;
	des.resize(src.size());
	//std::transform(src.begin(), src.end(), des.begin(), addValue<int, 5>);	
	//仿函数
	//std::transform(src.begin(), src.end(), des.begin(), std::bind2nd(std::plus<int>(),5));
	std::transform(src.begin(), src.end(), des.begin(), std::bind1st(std::plus<int>(), 3));//bind1st param
	std::transform(src.begin(), src.end(), des.begin(), std::plus<int>());
	// 也可以用lambda表达式 更方便
	//std::transform(src.begin(), src.end(), des.begin(), [](int const& x) {return x + 5; });

	for (const auto& iter : des)
		cout << iter << "\t";
	cout << "\n";
}

/*
* 非类型模板参数的限制
* 1 浮点数和类对象(class-type)是不允许作为非类型模板参数的
* 2 由于字符串文字是内部链接对象(因为两个具有相同名称但处于不同模块的字符串,是两个完全不同的对象)，所以你不能用他们来作为模板实参
*/

//template<double VAT> //浮点模板参数是非标准的
//double process(double v)
//{
//	return v * VAT;
//}
//
//template<string name> //非类型参数不能为类类型
//class MyClass
//{
//
//};

template<char const* name>
class MyClass
{

};

/*
*  2 由于字符串文字是内部链接对象(因为两个具有相同名称但处于不同模块的字符串,是两个完全不同的对象)，所以你不能用他们来作为模板实参
*/

extern char const s[] = "hello";
void char_const_template_param_test()
{
	//MyClass<"hello"> x;//
	char const* sp = "helo";
	//MyClass<*sp> x1; //

	MyClass<s> x3; //全局字符串数组s由"hello"初始化，是一个外部链接对象
}

int main()
{

	cout << "Non TypeTemplate Param\n";

	addvalue_test();


	stack_test();

	return 0;
}

/*
* 1 模板可以具有值类型参数，而不仅仅是类型模板参数
* 2 对于非类型模板参数，你不能使用浮点数,class类型的对象和内部链接对象(如string)作为实参
*    实际上应该只有基本数据类型中的(int short long char bool 之类的)
*/