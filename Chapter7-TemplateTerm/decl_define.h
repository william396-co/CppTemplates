#pragma once
/*
* �����Ͷ���(declaration/definition)
*/

// ������һ��C++����(construct)��������(����������)һ�����Ƶ�ĳ��C++������(scope)�С�
// ���ң���������ͨ�������������������Ƶ�һ���ֲ�����(partial classification)��
// ������Ч����������Ҫ���������������ϸ��

class C; //����
void f(int p); //����
extern int v; //v������



// ����  ���ȷ��������C++����(������)��ϸ�ڣ����߶��ڱ������ԣ��Ѿ�Ϊ���������ڴ�ռ䣬��ô�����ͱ���˶���(definition)
// ����"������(type class) ������"���壬����ζ�ű����ṩ����һ�ѻ������ڲ���ʵ�塣
// ���ڱ�������,���г�ʼ�����Ͳ�����extern�ؼ��ֵ��������Ƕ��塣


class D {}; //�����Ͷ���
void f(int p) //f�Ķ���(������)
{

}

extern int v = 1; //һ����ʼ����ʹ֮��Ϊv�Ķ���

int w; //�����Ͷ��� 

template<typename T>  //����
void func(T);


template<typename T>
class S {}; //�����Ͷ���



/*
* һ������ԭ��(one-definition rule)
* 1 ��ȫ�ֱ����;�̬���ݳ�Աһ���������������У������������ͳ�Ա����ֻ�ܱ�����һ��
* 2 ������(class type.struct union)������������ÿ�����뵥Ԫ�����ֻ�ܱ�����һ�Σ�������ڶ�����뵥Ԫ���������еĶ��嶼�����ǵ�ͬ�� 
*/