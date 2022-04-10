#include <cstdio>
#include <string>
using namespace std;

void foo(int const& x)// int 不可变
{
	printf("%s(%d)\n", __FUNCTION__, x);
	//x = 100;
}

void bar(string const& str) //string 不可变
{
	printf("%s(%s)\n", __FUNCTION__, str.c_str());	
	//str = "dsadasd";
}

void bar2(const string& str)//string 不可变
{

}

int main()
{
	printf("Hello Cpp Template\n");


	//原则 const最靠近的那个关键字 就是其修饰的关键字
	const int N = 100; //const int
	int const M = 99; // const int
	int* const p = new int{ 98 }; // const *, ptr不能改变，可以改变*p
	*p = 100;
	//*p = &N; //error ptr不能改变
	delete p;


	int const* const  pc = new int{ 99 }; //pc not change, *pc no changed too
	//pc = &M;
	//*pc = 1; 
	delete pc;


	// 趋向于使用int const, 而不是const int

	using CHARS = char*;
	using CPTR = CHARS const; //char * const {const *}
	using CPTR = const CHARS; //const char*  {const char}  
	

	return 0;
}