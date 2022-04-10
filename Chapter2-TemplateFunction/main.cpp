#include <cstdio>
#include <iostream>
#include <typeinfo>
using namespace std;

/*
* 参数:  T const& (效率优势,不需要拷贝参数)
* 返回值 T const& (效率优势,不需要临时变量,也不需要move返回)
*/
template<typename T>
T const& max(T const& x, T const& y)
{
	//printf("%s<%s>()\n", __FUNCTION__, typeid(T const&).name());
	cout << __FUNCTION__ << "<" << typeid(T).name() << "(" << typeid(T const&).name() << "," << typeid(T const&).name() << ")\n";
	return x < y ? y : x;
}

//重载函数模板
inline int const& max(int const& a, int const& b)
{
	//printf("%s(%s,%s)\n", __FUNCTION__, typeid(int const&).name(), typeid(int const&).name());
	cout << __FUNCTION__ << "(" << typeid(int const&).name() << "," << typeid(int const&).name() <<  ")\n";
	return a < b ? b : a;
}

template<typename T>
inline T const& max(T const& a, T const& b, T const& c)
{
	//printf("%s<%s>()\n", __FUNCTION__, typeid(T const&).name());
	cout << __FUNCTION__ << "<" << typeid(T).name() << "(" << typeid(T const&).name() << "," << typeid(T const&).name() << ")\n";
	return ::max(::max(a, b), c); //调用其他的模板函数
}

template<typename T>
inline T* const& max(T* const& a, T* const& b)
{
	//printf("%s<%s>()\n", __FUNCTION__, typeid(T* const&).name());
	cout << __FUNCTION__ <<"<"<<typeid(T).name()<< "(" << typeid(T* const&).name() << "," << typeid(T* const&).name() << ")\n";
	return *a < *b ? b : a;
}

inline char const* const& max(char const* const& a, char const* const& b)
{
	//cout<<("%s(%s,%s,%s)\n", __FUNCTION__, typeid(char const* const&).name(), typeid(char const* const&).name(), typeid(char const* const&).name());
	cout << __FUNCTION__ << "(" << typeid(char const* const&).name() << "," << typeid(char const* const&).name() << "," << typeid(char const* const&).name() << ")\n";
	return strcmp(a, b) < 0 ? b : a;
}


int main()
{
	printf("Template Function\n");

	int i = 9;
	cout << "max(200,i)=" << ::max(200, i) << "\n";

	double f1 = 3.4, f2 = -6.7;
	cout << "max(f1,f2)=" << ::max(f1, f2) << "\n";

	string s1 = "mathematics";
	string s2 = "math";
	cout << "max(s1,s2)=" << ::max(s1, s2) << "\n";

	cout << ::max<double>(4, 43.2) << "\n";
	cout << ::max(static_cast<double>(4), 43.2) << "\n";



	printf("---------------------------------------\n");

	::max(7, 42, 68);
	::max(7.0, 42.0);		
	::max('a', 'b');
	::max(7, 42);
	::max<>(7, 42);
	::max<double>(7, 42);
	::max('a', 42.7);
		

	printf("---------------------------------------\n");


	int a = 7;
	int b = 42;
	::max(a, b);

	string s = "hey";
	string t = "you";
	::max(s, t);

	int* p1 = &b;
	int* p2 = &a;
	::max(p1, p2);

	char const* s3 = "David";
	char const* s4 = "Nico";
	::max(s3, s4);


	return 0;
}

/*
* 1 模板函数为不同的模板实参定义了一个函数家族
* 2 当你传递模板实参的时候，可以根据实参的类型来对函数模板进行实例化
* 3 你可以显式指定模板参数
* 4 你可以重载函数模板
* 5 当重载函数模板的时候，把你的改变限制在：显示地指定模板参数
* 6 一定要让函数模板的所有重载版本的声明在位于他们被调用的位置之前
*/