#include <iostream>
#include <vector>
#include "stack.h"
#include "tmpl_stack.h"
using namespace std;

/*
* 1 �ؼ���typename
*/
template<typename T>
class MyClass
{
	typename T::SubType* ptr; //ptr��һ��ָ��T::SubType��ָ��
};


// ��ӡSTL������Ԫ��
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
*  2.template ����
*/

#include <bitset>
template<int N>
void printBitset(std::bitset<N> const& bs)
{
	// template �����to_stringģ��, ʵ�λ�
	std::cout << bs.template to_string<char, char_traits<char>, allocator<char> >();
}

/*
* ʹ��this->
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
		//��������� ������Ҫʹ��ʱ����Ҫ��this���߻���������ָ��
		//this->b_exit();
		Base<T>::b_exit(); 
	}
};

/*
*  ���ʼ������
*/
template<typename T>
void foo()
{
	//T x; //x δ��ʼ��
	T x = T{}; // T x = T();
	cout << x << "\n";
}

template<typename T>
class MyClass2
{
private:
	T x_;
public:
	MyClass2() :x_{} {}//��ʼ���б���г�ʼ��������ͨclass����
	void SetX(T const& x) { x_ = x; }
	T GetX()const { return x_; }
};

/*
* ʹ���ַ�����Ϊ����ģ���ʵ��
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

		
	//�ַ�����Ϊģ��ʵ������
	string s;
	::max1("apple", "peach");
	//::max1("apple", "tomato"); //�����б�ƥ��
	//::max1("apple", s);        //�����б�ƥ��

	::max2("apple", "peach");//�˻�Ϊ char const* ���鵽ָ��ת�� ��Ϊdecay
	::max2("apple", "tomato");//�˻�Ϊ char const*
	::max2("apple", s.c_str()); //
	//::max2("apple", s); //error �����б�ƥ��
	

	ref("hello");     // x in ref(T): char const [6]
	nonref("hello");  // x in nonref(T): char const *


	//���ʼ������
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
* 1 ���Ҫ����������ģ��������������ƣ���Ӧ������������ǰ��ӹؼ���typename
* 2 Ƕ����ͳ�Ա����Ҳ������ģ�塣 �ڱ��µ������У����Ԫ�����Ϳ��Խ�����ʽ���͵�ת����2��ջ������ʵ����ͨ�õĸ�ֵ������Ȼ������������£����ͼ����Ȼ����
* 3 ��ֵ�������ģ��汾û��ȡ��ȱʡ��ֵ�����
* 4 ����ģ�������Ϊģ����������ǳ�֮Ϊ��ģ���ģ�������
* 5 ģ���ģ��ʵ�α��뾫ȷƥ�䣬ƥ��ʱ�����ῼ��"ģ���ģ��ʵ��"��ȱʡʵ��(��std::deque��allocator)
* 6 ͨ����ʽ����ȱʡ���캯��������ȷ��ģ��ı����ͳ�Ա���Ѿ���һ��ȱʡֵ��ɳ�ʼ�������ַ������ڼ����͵ı����ͳ�ԱҲ����(ȱʡ���캯�� ��Ա��ʼ���б�)
* 7 �����ַ�������ʵ����������У����ҽ���������������ʱ���Ż�������鵽ָ��(array-to-pointer)������ת��(��Ϊdecay �˻�)
*/