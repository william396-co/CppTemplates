#include <cstdio>
#include <string>
using namespace std;

void foo(int const& x)// int ���ɱ�
{
	printf("%s(%d)\n", __FUNCTION__, x);
	//x = 100;
}

void bar(string const& str) //string ���ɱ�
{
	printf("%s(%s)\n", __FUNCTION__, str.c_str());	
	//str = "dsadasd";
}

void bar2(const string& str)//string ���ɱ�
{

}

int main()
{
	printf("Hello Cpp Template\n");


	//ԭ�� const������Ǹ��ؼ��� ���������εĹؼ���
	const int N = 100; //const int
	int const M = 99; // const int
	int* const p = new int{ 98 }; // const *, ptr���ܸı䣬���Ըı�*p
	*p = 100;
	//*p = &N; //error ptr���ܸı�
	delete p;


	int const* const  pc = new int{ 99 }; //pc not change, *pc no changed too
	//pc = &M;
	//*pc = 1; 
	delete pc;


	// ������ʹ��int const, ������const int

	using CHARS = char*;
	using CPTR = CHARS const; //char * const {const *}
	using CPTR = const CHARS; //const char*  {const char}  
	

	return 0;
}