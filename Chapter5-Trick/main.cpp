#include <iostream>
#include <vector>
#include "stack.h"
#include "tmpl_stack.h"
using namespace std;

/*
* 1 关键字typename
*/
template<typename T>
class MyClass
{
	typename T::SubType* ptr; //ptr是一个指向T::SubType的指针
};


// 打印STL容器的元素
template<typename T>
void printcoll(T const& coll)
{
	typename T::const_iterator pos;
	typename T::const_iterator end(coll.end());

	for (pos = coll.begin(); pos != end; ++pos)
		cout << *pos << ' ';
	cout << "\n";
}

/*
*  2.template 构造
*/

#include <bitset>
template<int N>
void printBitset(std::bitset<N> const& bs)
{
	// template 后面的to_string模板, 实参化
	std::cout << bs.template to_string<char, char_traits<char>, allocator<char> >();
}

/*
* 使用this->
*/

template<typename T>
class Base
{
public:
	void b_exit() {}
};

template<typename T>
class Derived : Base<T>
{
public:
	void foo()
	{
		//基类的声明 子类需要使用时，需要用this或者基类作用域指明
		//this->b_exit();
		Base<T>::b_exit(); 
	}
};

/*
*  零初始化问题
*/
template<typename T>
void foo()
{
	//T x; //x 未初始化
	T x = T{}; // T x = T();
	cout << x << "\n";
}

template<typename T>
class MyClass2
{
private:
	T x_;
public:
	MyClass2() :x_{} {}//初始化列表进行初始化，跟普通class类似
	void SetX(T const& x) { x_ = x; }
	T GetX()const { return x_; }
};

/*
* 使用字符串作为函数模板的实参
* 
*/

template<typename T>
inline T const& max1(T const& a, T const& b)
{
	return a < b ?  b : a;
}

template<typename T>
inline T max2(T a, T b)
{
	return a < b ?  b : a;
}

template<typename T>
void ref(T const& x)
{
	cout << "x in ref(T): " << typeid(x).name() << "\n";
}

template<typename T>
void nonref(T x)
{
	cout << "x in nonref(T): " << typeid(x).name() << "\n";
}


int main()
{
	cout << "Trick basic about template\n";

	stack_test2();

		
	//字符串作为模板实参问题
	string s;
	::max1("apple", "peach");
	//::max1("apple", "tomato"); //参数列表不匹配
	//::max1("apple", s);        //参数列表不匹配

	::max2("apple", "peach");//退化为 char const* 数组到指针转换 称为decay
	::max2("apple", "tomato");//退化为 char const*
	::max2("apple", s.c_str()); //
	//::max2("apple", s); //error 参数列表不匹配
	

	ref("hello");     // x in ref(T): char const [6]
	nonref("hello");  // x in nonref(T): char const *


	//零初始化问题
	MyClass2<string> my2{};
	my2.SetX("hello");
	cout << my2.GetX() << "\n";
	

	foo<int>();
	
	stack_test1();
	vector<int> vi = { 1,3,434,6,7,6 };
	printcoll(vi);

	bitset<16> bs;
	printBitset(bs);

	return 0;
}

/*
* 1 如果要访问依赖与模板参数的类型名称，你应该在类型名称前添加关键字typename
* 2 嵌套类和成员函数也可以是模板。 在本章的例子中，针对元素类型可以进行隐式类型的转换的2个栈，他们实现了通用的赋值操作，然后在这种情况下，类型检查依然存在
* 3 赋值运算符的模板版本没有取代缺省赋值运算符
* 4 类型模板可以作为模板参数，我们称之为【模板的模板参数】
* 5 模板的模板实参必须精确匹配，匹配时并不会考虑"模板的模板实参"的缺省实参(如std::deque的allocator)
* 6 通过显式调用缺省构造函数，可以确保模板的变量和成员都已经用一个缺省值完成初始化，这种方法对内奸类型的变量和成员也适用(缺省构造函数 成员初始化列表)
* 7 对于字符串，在实参演绎过程中，当且仅当参数不是引用时，才会出现数组到指针(array-to-pointer)的类型转换(称为decay 退化)
*/