#include <iostream>
#include <stdexcept>
using namespace std;

/*
* ������ģ�����
*  ���ں���ģ�����ģ�壬ģ������������������ͣ���ֵͨҲ������Ϊģ�����
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
	//�º���
	//std::transform(src.begin(), src.end(), des.begin(), std::bind2nd(std::plus<int>(),5));
	std::transform(src.begin(), src.end(), des.begin(), std::bind1st(std::plus<int>(), 3));//bind1st param
	std::transform(src.begin(), src.end(), des.begin(), std::plus<int>());
	// Ҳ������lambda���ʽ ������
	//std::transform(src.begin(), src.end(), des.begin(), [](int const& x) {return x + 5; });

	for (const auto& iter : des)
		cout << iter << "\t";
	cout << "\n";
}

/*
* ������ģ�����������
* 1 �������������(class-type)�ǲ�������Ϊ������ģ�������
* 2 �����ַ����������ڲ����Ӷ���(��Ϊ����������ͬ���Ƶ����ڲ�ͬģ����ַ���,��������ȫ��ͬ�Ķ���)�������㲻������������Ϊģ��ʵ��
*/

//template<double VAT> //����ģ������ǷǱ�׼��
//double process(double v)
//{
//	return v * VAT;
//}
//
//template<string name> //�����Ͳ�������Ϊ������
//class MyClass
//{
//
//};

template<char const* name>
class MyClass
{

};

/*
*  2 �����ַ����������ڲ����Ӷ���(��Ϊ����������ͬ���Ƶ����ڲ�ͬģ����ַ���,��������ȫ��ͬ�Ķ���)�������㲻������������Ϊģ��ʵ��
*/

extern char const s[] = "hello";
void char_const_template_param_test()
{
	//MyClass<"hello"> x;//
	char const* sp = "helo";
	//MyClass<*sp> x1; //

	MyClass<s> x3; //ȫ���ַ�������s��"hello"��ʼ������һ���ⲿ���Ӷ���
}

int main()
{

	cout << "Non TypeTemplate Param\n";

	addvalue_test();


	stack_test();

	return 0;
}

/*
* 1 ģ����Ծ���ֵ���Ͳ�������������������ģ�����
* 2 ���ڷ�����ģ��������㲻��ʹ�ø�����,class���͵Ķ�����ڲ����Ӷ���(��string)��Ϊʵ��
*    ʵ����Ӧ��ֻ�л������������е�(int short long char bool ֮���)
*/