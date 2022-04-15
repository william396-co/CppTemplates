#include <cstdio>
using namespace std;

/*
*  深入模板基础
*/


/*
* 参数化声明
*/

template<typename T>
class List
{
private:
	T* data_;
};

// Union模板
template<typename T>
union  AllocChunk
{
	T object;
	unsigned char bytes[sizeof(T)];
};

template<typename T>
class Stack{};

template<typename T>
class Array{};

//缺省参数
template<typename T>
void report(Stack<T>const&, int number = 10)
{
	printf("%s\n", __FUNCTION__);
}

template<typename T>
void fill(Array<T>*, T const& = T())
{
	printf("%s\n", __FUNCTION__);
}



//类模板的成员函数
//类模板的嵌套成员函数
//类模板的静态数据成员的定义

template<typename I>
class CupBoard 
{
public:
	void open();
	class Shelf;

	static double total_weight;
};

template<typename I>
void CupBoard<I>::open()
{

}

template<typename I>
class CupBoard<I>::Shelf {

};

template<typename I>
double CupBoard<I>::total_weight{ 0.0 };


//虚成员函数 成员函数的模板不能被声明为虚函数
class Dynamic {
public:
	virtual ~Dynamic() { }

	//template<typename T2>
	//virtual void copy(T2 const&); //error
};



/*
* 模板的链接
*  每个模板都必须有一个名字，而且在它所属的作用域下，该名字必须是唯一的。除非函数模板可以被重载
*  类模板不能和另外一个实体共享一个名称，这一点和class类型是不同的
*
*/
//class C;
int X;
template<typename T>
class X {};

struct S {};

//template<typename T>
//class S {}; // S命名冲突


extern "C++" template<typename T> //默认就是extern "C++"
void normal(){}

//模板不能具有C链接
//extern "C" template<typename T>
//void invalid() {}

// 基本模板
template<typename T>
class Box {};

//template<typename T>
//class Box<T> {}; //错误 

template<typename T>
void translate(T*){}


/*
* 模板参数
* 1 类型参数
* 2 非类型参数
* 3 模板的模板参数
*/
// 类型参数
template<typename T,
		T* Root,
	template<T*> class Buf>
class Structure { };

// 非类型参数
template<int len> class Buffer;
template<int buf[5]> class Lexer; //decay int*(数组会退化为指针)
template<int* buf> class buffer;

// 模板的模板参数(不能使用struct/union)
template< template<typename X> class C>
void f(C<int>* p) {}

//template< template<typename X> struct C>
//void f(C<int>* p) {}
//
//template< template<typename X> union C>
//void f(C<int>* p) {}

#include <xmemory>
// 模板的模板参数的参数可以具有缺省值(只有类模板才能有缺省实参)
template< template<typename T,typename Alloc = std::allocator<T>> class Container>
class Adaptation {
	Container<int> storage; //相当于 Container<int,std::allocator<int>>
};

//缺省实参
template<typename T1, typename T2, typename T3,
	typename T4 = char, typename T5 = char>
	class Quintuple;


/*
* 模板实参(在实例化模板时，用来替换模板参数的值)
* 1 显式模板实参：紧跟在模板名称后面，在一堆尖括号内显式模板实参值，所组成的整个实体称为template-id
* 2 注入式(injected)类名称： 对于具有模板参数P1、P2...的类模板X，在它的作用域中，模板名称(即X)等同于template-id: X<P1,P2...>
* 3 缺省模板实参： 如果提供缺省模板实参的化，在类模板的实例中可以省略显式模板实参
* 4 实参演绎： 对于不是显式指定的函数模板实参，可以在函数的调用语句中，根据函数调用实参的类型来演绎出函数模板实参 
*/

template<typename T>
inline T const& max(T const& a, T const& b)
{
	return a < b ? b : a;
}

template<typename DstT,typename SrcT>
inline DstT implicit_cast(SrcT const& x) //SrcT可以被演绎，DstT不可以
{
	return x;
}

template<typename SrcT,typename DstT> //必须显式指定两个类型
inline DstT implicit_cast2(SrcT const& x)
{
	return x;
}

template<typename Func,typename T>
void apply(Func func, T x)
{
	func(x);
}

#include <string>
template<typename T>
void single(T x)
{
	printf("%s(%s)\n", __FUNCTION__, std::to_string(x).c_str());
}

template<typename T> void multi(T t) {}
template<typename T> void multi(T* tp){}

/*
* SFINAE 原则 substitution-failure-is-not-an-error  替换失败并非错误原则
* 
*/

//template<typename T> RT1 test(typename T::X const*);
//template<typename T> RT2 test(...);


/*
* 类型实参
* 1 局部类和局部枚举 不能作为模板类型实参
* 2 匿名的class或者枚举不能作为模板的实参
*/

struct Point { int x, y, z; };
typedef enum {red,green,blue} *ColorPtr;

template<typename T>
void clear(T p)
{
	*p = 0;
}

/*
* 非类型实参 是那些替换非类型参数的值，这个值必须是一下类型：
* 1 某一个具有正确类型的非类型模板参数
* 2 一个编译器整形常值(或枚举值)
* 3 前面有弹幕运算符&(取地址)的外部变量或者函数的名称，对于函数或者数组变量，&运算符可以省略，这类模板实参可以匹配指针类型的非类型参数
* 4 对于引用类型的非类型模板参数，前面没有&运算符的外部变量和外部函数也是可取的
* 5 一个指向成员的指针常量(pointer-to-member constant)，换句话说，类似&C::m的表达式，C是class类型，m是一个非静态成员(变量或函数)，这类实参只能匹配类型为"成员指针"的非类型参数
* 
* 另外一方面,一些不能作为有效的非类型实参
* 1 空指针常量
* 2 浮点型值
* 3 字符串 
*/



template<typename T,T nontype_param>
class C{};

C<int, 33>* c1;//int
int a;
C<int*, &a> c2;//外部变量的地址
void f() {}
void f(int) {}
C<void(*)(int), f>* c3;//函数名称

class XTest
{
public:
	int n;
	static bool b;
};

C<bool&, XTest::b>* c4;//静态成员变量是可取的
C<int XTest::*, &XTest::n>* c5;//指向成员的指针常量

template<typename T> 
void tmpl_func() {}

C<void(), &tmpl_func<double> >* c6;//函数模板实例也是函数

//反面使用案例
template<char const* str>
class Message {};

extern char const  hello[] = "Hello world";
Message<hello>* hell_msg;

/*
* 模板的模板实参 必须是一个类模板，它本身具有参数，该参数必须精确匹配它"所替换的模板的模板参数"本身的参数
* 
*/


template<typename T1,typename T2,
		template<typename T,typename = std::allocator<T> > class Container >
class Relation
{

};

/*
* 实参的等价性
*/

template<typename T,int I>
class Mix{};

typedef int Int;
Mix<int, 3 * 3>* p1;
Mix<Int, 4 * 4>* p2; //p1和p2的类型是相同的




/*
*  友元  授予某个类或者函数访问友元声明所在的类
* 
*  1 友元声明可能是某个实例的唯一声明
*  2 友元函数的声明可以是一个定义
* 
*/
	

template<typename T>
class Node;

template<typename T>
class Tree {
	friend class Node<T>; //友元声明
};

/*
* 友元函数
*/

template<typename T1,typename T2>
void combine(T1 t1, T2 t2) 
{
	printf("%s(%s,%s)\n", __FUNCTION__, std::to_string(t1), std::to_string(t2));
}

class Mixer
{
	friend void combine<>(int&, int&);
	friend void combine<int, int>(int, int);
	friend void combine<char>(char, int);
	//friend void combine<char>(char&, int);//error
	//friend void combine<>(long l1, long l2) {} //不允许出现定义
};

void multiply(void* p)  //普通函数
{
} 
template<typename T>
void multiply(T t)
{

}

class Comrades
{
	friend void multiply(int) {}
	friend void ::multiply(void*);//引用上面的函数
	friend void ::multiply(int); //引用一个模板实例
	friend void ::multiply<double*>(double*);//模板实例

	//friend void ::error() {}//受限的友元不能是一个定义
};

//类模板内声明友元
template<typename T>
class Node2
{
	Node2<T>* allocate() { return new Node2<T>(); }
};

template<typename T>
class List2
{
	friend Node2<T>* Node2<T>::allocate();//

};

//ODR原则 One-Definition-Rule
template<typename T>
class Creator {
	//friend void appear()//违反了ODR原则
	//{
	//}
	friend void feed(Creator<T>*)
	{
	}
};

//Creator<void> miracle; //appear()被生成2次
//Creator<double> oops;
Creator<void> one;//feed(Create<void>)
Creator<double> two;//feed(Create<double>)

//友元模板 让模板的所有实例都称为友元
template<typename T>
class Task;

template<typename T>
class Schedule
{
	void dispatch(Task<T>*) {}
};
class Manger
{
	template<typename T>
	friend class Task;

	template<typename T>
	friend void Schedule<T>::dispatch(Task<T>*);

	template<typename T>
	friend int ticket()
	{
		return ++Manger::counter;
	}
	static int counter;
};


#include <list>
int main()
{
	printf("Deep in Template\n");

	::max<double>(1.0, -3.0); //显式
	::max(1.0, 3.0); //演绎

	auto val = implicit_cast<double>(-1);
		
	auto val2 = implicit_cast2<double,double>(-1);

	apply(&single<int>, 4);
	//apply(&multi<int>, 5);//multi 不唯一

	//局部类型
	struct Association { int* p, * q; };


	list<Association*> error1;//局部类型
	list<ColorPtr> error2;  //未命名的枚举
	list<Point> point_list;

	int a = 200;
	clear(&a);
	printf("after clear, a=%d\n", a);

	Relation<int, double, std::list> rel;



	return 0;
}