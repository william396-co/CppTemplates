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
	catch (std::exception const& ex) //�����쳣
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
* 1 ��ģ���Ǿ����������ʵ��ࣺ �����ʵ���У�������һ���������ͻ�û��ָ��
* 2 Ϊ��ʹ����ģ�壬����Դ���ĳ������������Ϊģ��ʵ�Σ�Ȼ�������������ڸ�������ʵ����ģ��
* 3 ����ģ�����Ͷ��ѣ�ֻ����Щ�����õĳ�Ա�����Żᱻʵ����
* 4 ��������ض�����������ģ��
* 5 �����Ϊ��Ŀ��Ĳ�������ȱʡֵ����Щֵ����������֮ǰ��ģ�����
*/