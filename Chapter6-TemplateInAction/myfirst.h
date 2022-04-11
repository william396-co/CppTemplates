#pragma once

#include <typeindex>
#include <iostream>

template<typename T>
void print_typeof(T const& x)
{
	std::cout << typeid(x).name() << "\n";
}


//��ʽʵ����
template void print_typeof<double>(double const&);