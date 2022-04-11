#pragma once
/*
* 声明和定义(declaration/definition)
*/

// 声明是一种C++构造(construct)，它引入(或重新引入)一个名称到某个C++作用域(scope)中。
// 而且，这种引入通常都包含对所引入名称的一个局部分离(partial classification)，
// 但是有效的声明并不要求包含被引入对象的细节

class C; //声明
void f(int p); //声明
extern int v; //v的声明



// 定义  如果确定了这种C++构造(即声明)的细节，或者对于变量而言，已经为他分配了内存空间，那么声明就变成了定义(definition)
// 对于"类类型(type class) 或函数的"定义，这意味着必须提供包含一堆花括号内部的实体。
// 对于变量而言,进行初始化啊和不具有extern关键字的声明都是定义。


class D {}; //声明和定义
void f(int p) //f的定义(和声明)
{

}

extern int v = 1; //一个初始化器使之称为v的定义

int w; //声明和定义 

template<typename T>  //声明
void func(T);


template<typename T>
class S {}; //声明和定义



/*
* 一处定义原则(one-definition rule)
* 1 和全局变量和静态数据成员一样，在整个程序中，非内联函数和成员函数只能被定义一次
* 2 类类型(class type.struct union)和内联函数在每个翻译单元中最多只能被定义一次，如果存在多个翻译单元，则其所有的定义都必须是等同的 
*/