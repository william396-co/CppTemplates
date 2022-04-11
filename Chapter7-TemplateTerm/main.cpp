#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
using namespace std;

/*
* 模板术语
*/

/*
*  类模板(class template): 该类是一个模板， 它代码的是，整个类家族的参数化描述
*  模板类(template class)
*   1 作为类模板的同义词
*   2 从模板产生的类
*   3 具有一个template-id名称的类
*/


/* 洗牌算法 */
//template<typename T, 
//	template<typename ELEM,typename ALLOC = std::allocator<ELEM> > class CONT = std::vector>
//void shuffle(CONT<T>& src)
//{
//	for (int i = int(src.size() - 1); i >= 0; --i)
//		std::swap(src[i], src[rand() % (i + 1)]);
//}

template<typename T,
	template<typename ELEM, typename ALLOC = std::allocator<ELEM> > class CONT = std::vector >
CONT<T> RandSelect(CONT<T> const& src, size_t SelNum)
{
	if (src.size() <= SelNum)
		return src;

	CONT<T> result{ src };	
	random_shuffle(result.begin(), result.end());		
	result.resize(SelNum);
	return result;
}

template<typename T1,typename T2>
class MyClass
{

};

//显式特化(explicit specialization)
template<>
class MyClass<std::string, float> {

};

//局部特化(partial specialization)
template<typename T>
class MyClass<T, T> {

};


#include <list>
#include <deque>
#include <set>


/*
* 模板实参 和模板参数(传递模板实参使之称为模板参数)
* 
* 模板参数： 位于模板声明或定义内部，关键字template后面所列举的名称(比如我们例子中的T N等)
* 模板实参： 用来替换模板参数的各个对象(如我们例子中的double和10)， 和模板参数不同的是，模板实参可以不局限于"标识符名称"(就是有多种类型)
*/

template<typename T,int N>
class ArrayInClass {
public:
	T arr[N];
};

class DoubleArrayInClass
{
public:
	double arr[10];
};

template<>
class ArrayInClass<double, 10>
{

};


// T既是一个模板参数(第一个T)，也是一个模板实参(第二个T)
template<typename T>
class Dozen{
public:
	ArrayInClass<T, 12> content;
};



int main()
{
	cout << "Template Term\n";

	ArrayInClass<double, 12> ad;
	ad.arr[0] = 100;


	vector<int> vi{ 3,4,43,5,6,7,13,6,87 };
	for (int i = 0; i < 10; ++i)
	{
		auto result = RandSelect(vi, 5);
		for (auto& i : result)
			cout << i << ' ';
		cout << "\n";
	}


	return 0;
}