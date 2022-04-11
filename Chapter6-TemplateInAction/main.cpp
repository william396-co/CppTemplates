#include <iostream>
using namespace std;

/*
* ģ��ʵս
*/

#include "myfirst.h"
#include "std.h"
#include "shallow_instantiate.h"
#include "tracer.h"

int main()
{
	cout << "Template In Action\n";

	sort_tracer_test();

	//shallow_test();

	// ����ģ��������
	list<string> coll;
	list<string>::iterator pos;
	//pos = std::find_if(coll.begin(), coll.end(), std::bind2nd(std::greater<int>(), "A"));//no match for call
	pos = std::find_if(coll.begin(), coll.end(), std::bind2nd(std::greater<string>(), "A"));

	double ice = 2.3;
	print_typeof(ice);

	return 0;
}

/*
* 1 ģ���ԭʼ��"������+������"ģ�ʹ�����ս����ˣ���Ҫʹ�������ķ�������֯ģ����룬��Щ�����ǰ���ģ�ͣ���ʽʵ�����ͷ���ģ��
* 2 �ڴ��������£���Ӧ��ʹ�ð���ģ��(����˵�� ������ģ����붼����ͷ�ļ���)
* 3 ͨ��ģ�����������ģ�嶨�������ڲ�ͬ��ͷ�ļ��У�����Ժ����׵��ڰ���ģ�ͺ���ʽʵ����֮������ѡ��
* 4 C++��׼δģ�嶨����һ������ı���ģ��(ʹ��export�ؼ���)���ùؼ��ֻ�û���ü��ռ����ܶ������Ҳ���ṩ֧��
* 5 ����ģ������Ǿ�����ս�Ե�
* 6 ģ��ʵ�������ܻ���кܳ�������
* 7 Ϊ�˳������Ԥ������룬Ҫȷ��#includeָʾ����˳������ͬ��
*/