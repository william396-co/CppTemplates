#include <cstdio>
using namespace std;

/*
*  ����ģ�����
*/


/*
* ����������
*/

template<typename T>
class List
{
private:
	T* data_;
};

// Unionģ��
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

//ȱʡ����
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



//��ģ��ĳ�Ա����
//��ģ���Ƕ�׳�Ա����
//��ģ��ľ�̬���ݳ�Ա�Ķ���

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


//���Ա���� ��Ա������ģ�岻�ܱ�����Ϊ�麯��
class Dynamic {
public:
	virtual ~Dynamic() { }

	//template<typename T2>
	//virtual void copy(T2 const&); //error
};



/*
* ģ�������
*  ÿ��ģ�嶼������һ�����֣����������������������£������ֱ�����Ψһ�ġ����Ǻ���ģ����Ա�����
*  ��ģ�岻�ܺ�����һ��ʵ�干��һ�����ƣ���һ���class�����ǲ�ͬ��
*
*/
//class C;
int X;
template<typename T>
class X {};

struct S {};

//template<typename T>
//class S {}; // S������ͻ


extern "C++" template<typename T> //Ĭ�Ͼ���extern "C++"
void normal(){}

//ģ�岻�ܾ���C����
//extern "C" template<typename T>
//void invalid() {}

// ����ģ��
template<typename T>
class Box {};

//template<typename T>
//class Box<T> {}; //���� 

template<typename T>
void translate(T*){}


/*
* ģ�����
* 1 ���Ͳ���
* 2 �����Ͳ���
* 3 ģ���ģ�����
*/
// ���Ͳ���
template<typename T,
		T* Root,
	template<T*> class Buf>
class Structure { };

// �����Ͳ���
template<int len> class Buffer;
template<int buf[5]> class Lexer; //decay int*(������˻�Ϊָ��)
template<int* buf> class buffer;

// ģ���ģ�����(����ʹ��struct/union)
template< template<typename X> class C>
void f(C<int>* p) {}

//template< template<typename X> struct C>
//void f(C<int>* p) {}
//
//template< template<typename X> union C>
//void f(C<int>* p) {}

#include <xmemory>
// ģ���ģ������Ĳ������Ծ���ȱʡֵ(ֻ����ģ�������ȱʡʵ��)
template< template<typename T,typename Alloc = std::allocator<T>> class Container>
class Adaptation {
	Container<int> storage; //�൱�� Container<int,std::allocator<int>>
};

//ȱʡʵ��
template<typename T1, typename T2, typename T3,
	typename T4 = char, typename T5 = char>
	class Quintuple;


/*
* ģ��ʵ��(��ʵ����ģ��ʱ�������滻ģ�������ֵ)
* 1 ��ʽģ��ʵ�Σ�������ģ�����ƺ��棬��һ�Ѽ���������ʽģ��ʵ��ֵ������ɵ�����ʵ���Ϊtemplate-id
* 2 ע��ʽ(injected)�����ƣ� ���ھ���ģ�����P1��P2...����ģ��X���������������У�ģ������(��X)��ͬ��template-id: X<P1,P2...>
* 3 ȱʡģ��ʵ�Σ� ����ṩȱʡģ��ʵ�εĻ�������ģ���ʵ���п���ʡ����ʽģ��ʵ��
* 4 ʵ����� ���ڲ�����ʽָ���ĺ���ģ��ʵ�Σ������ں����ĵ�������У����ݺ�������ʵ�ε����������������ģ��ʵ�� 
*/

template<typename T>
inline T const& max(T const& a, T const& b)
{
	return a < b ? b : a;
}

template<typename DstT,typename SrcT>
inline DstT implicit_cast(SrcT const& x) //SrcT���Ա����DstT������
{
	return x;
}

template<typename SrcT,typename DstT> //������ʽָ����������
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
* SFINAE ԭ�� substitution-failure-is-not-an-error  �滻ʧ�ܲ��Ǵ���ԭ��
* 
*/

//template<typename T> RT1 test(typename T::X const*);
//template<typename T> RT2 test(...);


/*
* ����ʵ��
* 1 �ֲ���;ֲ�ö�� ������Ϊģ������ʵ��
* 2 ������class����ö�ٲ�����Ϊģ���ʵ��
*/

struct Point { int x, y, z; };
typedef enum {red,green,blue} *ColorPtr;

template<typename T>
void clear(T p)
{
	*p = 0;
}

/*
* ������ʵ�� ����Щ�滻�����Ͳ�����ֵ�����ֵ������һ�����ͣ�
* 1 ĳһ��������ȷ���͵ķ�����ģ�����
* 2 һ�����������γ�ֵ(��ö��ֵ)
* 3 ǰ���е�Ļ�����&(ȡ��ַ)���ⲿ�������ߺ��������ƣ����ں����������������&���������ʡ�ԣ�����ģ��ʵ�ο���ƥ��ָ�����͵ķ����Ͳ���
* 4 �����������͵ķ�����ģ�������ǰ��û��&��������ⲿ�������ⲿ����Ҳ�ǿ�ȡ��
* 5 һ��ָ���Ա��ָ�볣��(pointer-to-member constant)�����仰˵������&C::m�ı��ʽ��C��class���ͣ�m��һ���Ǿ�̬��Ա(��������)������ʵ��ֻ��ƥ������Ϊ"��Աָ��"�ķ����Ͳ���
* 
* ����һ����,һЩ������Ϊ��Ч�ķ�����ʵ��
* 1 ��ָ�볣��
* 2 ������ֵ
* 3 �ַ��� 
*/



template<typename T,T nontype_param>
class C{};

C<int, 33>* c1;//int
int a;
C<int*, &a> c2;//�ⲿ�����ĵ�ַ
void f() {}
void f(int) {}
C<void(*)(int), f>* c3;//��������

class XTest
{
public:
	int n;
	static bool b;
};

C<bool&, XTest::b>* c4;//��̬��Ա�����ǿ�ȡ��
C<int XTest::*, &XTest::n>* c5;//ָ���Ա��ָ�볣��

template<typename T> 
void tmpl_func() {}

C<void(), &tmpl_func<double> >* c6;//����ģ��ʵ��Ҳ�Ǻ���

//����ʹ�ð���
template<char const* str>
class Message {};

extern char const  hello[] = "Hello world";
Message<hello>* hell_msg;

/*
* ģ���ģ��ʵ�� ������һ����ģ�壬��������в������ò������뾫ȷƥ����"���滻��ģ���ģ�����"����Ĳ���
* 
*/


template<typename T1,typename T2,
		template<typename T,typename = std::allocator<T> > class Container >
class Relation
{

};

/*
* ʵ�εĵȼ���
*/

template<typename T,int I>
class Mix{};

typedef int Int;
Mix<int, 3 * 3>* p1;
Mix<Int, 4 * 4>* p2; //p1��p2����������ͬ��




/*
*  ��Ԫ  ����ĳ������ߺ���������Ԫ�������ڵ���
* 
*  1 ��Ԫ����������ĳ��ʵ����Ψһ����
*  2 ��Ԫ����������������һ������
* 
*/
	

template<typename T>
class Node;

template<typename T>
class Tree {
	friend class Node<T>; //��Ԫ����
};

/*
* ��Ԫ����
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
	//friend void combine<>(long l1, long l2) {} //��������ֶ���
};

void multiply(void* p)  //��ͨ����
{
} 
template<typename T>
void multiply(T t)
{

}

class Comrades
{
	friend void multiply(int) {}
	friend void ::multiply(void*);//��������ĺ���
	friend void ::multiply(int); //����һ��ģ��ʵ��
	friend void ::multiply<double*>(double*);//ģ��ʵ��

	//friend void ::error() {}//���޵���Ԫ������һ������
};

//��ģ����������Ԫ
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

//ODRԭ�� One-Definition-Rule
template<typename T>
class Creator {
	//friend void appear()//Υ����ODRԭ��
	//{
	//}
	friend void feed(Creator<T>*)
	{
	}
};

//Creator<void> miracle; //appear()������2��
//Creator<double> oops;
Creator<void> one;//feed(Create<void>)
Creator<double> two;//feed(Create<double>)

//��Ԫģ�� ��ģ�������ʵ������Ϊ��Ԫ
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

	::max<double>(1.0, -3.0); //��ʽ
	::max(1.0, 3.0); //����

	auto val = implicit_cast<double>(-1);
		
	auto val2 = implicit_cast2<double,double>(-1);

	apply(&single<int>, 4);
	//apply(&multi<int>, 5);//multi ��Ψһ

	//�ֲ�����
	struct Association { int* p, * q; };


	list<Association*> error1;//�ֲ�����
	list<ColorPtr> error2;  //δ������ö��
	list<Point> point_list;

	int a = 200;
	clear(&a);
	printf("after clear, a=%d\n", a);

	Relation<int, double, std::list> rel;



	return 0;
}