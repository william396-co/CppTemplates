#pragma once

/*
* ǳʽʵ����
*/

template<typename T>
void clear(T const& p)
{
	*p = nullptr; //����p��һ��ָ������
}



template<typename T>
void core(T const& p)
{
	clear(p);
}

template<typename T>
void middle(typename T::Index p)
{
	core(p);
}

template<typename T>
inline void ignore(T const&) 
{
}

template<typename T>
void shell(T const& env)
{	
	//class ShallowChecks {
	//	void deref(T::Index ptr)
	//	{
	//		ignore(*ptr);
	//	};
	//};
	typename T::Index i;
	middle<T>(i);
}

class Client
{
public:
	//using Index = int;
	typedef int Index;
};

Client main_client;

void shallow_test()
{
	//shell(main_client);
}