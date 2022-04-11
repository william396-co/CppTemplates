#include <iostream>
using namespace std;

/*
* 模板实战
*/

#include "myfirst.h"
#include "std.h"
#include "shallow_instantiate.h"
#include "tracer.h"

int main()
{
	cout << "Template In Action\n";

	sort_tracer_test();

	//shallow_test();

	// 测试模板编译错误
	list<string> coll;
	list<string>::iterator pos;
	//pos = std::find_if(coll.begin(), coll.end(), std::bind2nd(std::greater<int>(), "A"));//no match for call
	pos = std::find_if(coll.begin(), coll.end(), std::bind2nd(std::greater<string>(), "A"));

	double ice = 2.3;
	print_typeof(ice);

	return 0;
}

/*
* 1 模板给原始的"编译器+链接器"模型带来挑战，因此，需要使用其他的方法来组织模板代码，这些方法是包含模型，显式实例化和分离模型
* 2 在大多数情况下，你应该使用包含模型(就是说， 把所有模板代码都放在头文件中)
* 3 通过模板声明代码和模板定义代码放在不同的头文件中，你可以很容易地在包含模型和显式实例化之间做出选择
* 4 C++标准未模板定义了一个分离的编译模型(使用export关键字)，该关键字还没来得及普及，很多编译器也不提供支持
* 5 调试模板代码是具有挑战性的
* 6 模板实例化可能会具有很长的名称
* 7 为了充分利用预编译代码，要确认#include指示符的顺序是相同的
*/