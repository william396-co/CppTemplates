#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
using namespace std;

/*
* ģ������
*/

/*
*  ��ģ��(class template): ������һ��ģ�壬 ��������ǣ����������Ĳ���������
*  ģ����(template class)
*   1 ��Ϊ��ģ���ͬ���
*   2 ��ģ���������
*   3 ����һ��template-id���Ƶ���
*/


/* ϴ���㷨 */
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

//��ʽ�ػ�(explicit specialization)
template<>
class MyClass<std::string, float> {

};

//�ֲ��ػ�(partial specialization)
template<typename T>
class MyClass<T, T> {

};


#include <list>
#include <deque>
#include <set>


/*
* ģ��ʵ�� ��ģ�����(����ģ��ʵ��ʹ֮��Ϊģ�����)
* 
* ģ������� λ��ģ�����������ڲ����ؼ���template�������оٵ�����(�������������е�T N��)
* ģ��ʵ�Σ� �����滻ģ������ĸ�������(�����������е�double��10)�� ��ģ�������ͬ���ǣ�ģ��ʵ�ο��Բ�������"��ʶ������"(�����ж�������)
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


// T����һ��ģ�����(��һ��T)��Ҳ��һ��ģ��ʵ��(�ڶ���T)
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