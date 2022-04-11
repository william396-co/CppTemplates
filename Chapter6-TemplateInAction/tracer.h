#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class SortTracer
{
private:
	int value;               // Ҫ�����������ֵ
	int generation;          // ���������ķ���
	static long n_created;   // ���ù��캯���Ĵ���
	static long n_destroyed; // ������������
	static long n_assigned;  // ��ֵ����
	static long n_compared;  // �Ƚϴ���
	static long n_max_live;  // �ִ�����������

	static void update_max_live()
	{
		if (n_created - n_destroyed > n_max_live)
			n_max_live = n_created - n_destroyed;
	}
public:
	static long creations() { return n_created; }
	static long destructions() { return n_destroyed; }
	static long assignments() { return n_assigned; }
	static long comparisons() { return n_compared; }
	static long max_live() { return n_max_live; }

public:
	SortTracer(int v = 0) :value{ v }, generation{ 1 }
	{
		++n_created;
		update_max_live();
		printf("%s() # %ld, created generation %ld,(total:%ld)\n", __FUNCTION__, n_created, generation, n_created - n_destroyed);
	}

	SortTracer(SortTracer const& rhs) :value{ rhs.value }, generation{ rhs.generation + 1 }
	{
		++n_created;
		update_max_live();
		printf("%s() # %ld, copied as generation %ld,(total:%ld)\n", __FUNCTION__, n_created, generation, n_created - n_destroyed);
	}

	~SortTracer()
	{
		++n_destroyed;
		update_max_live();
		printf("%s() # %ld, destroyed (total:%ld)\n", __FUNCTION__,  generation, n_created - n_destroyed);
	}

	SortTracer& operator=(SortTracer const& rhs)
	{
		++n_assigned;
		printf("%s() # %ld,(generation:%ld)\n", __FUNCTION__, n_assigned, generation);
		value = rhs.value;
		return *this;
	}

	friend bool operator<(SortTracer const& lhs, SortTracer const& rhs)
	{
		++n_created;
		printf("%s() # %ld, (generation %ld < generation %ld)\n", __FUNCTION__, n_compared, lhs.generation, rhs.generation);
		return lhs.value < rhs.value;
	}

	int val()const { return value; }
};


// ��̬��Ա�����ʼ��
long SortTracer::n_created{ 0 };
long SortTracer::n_destroyed{ 0 };
long SortTracer::n_max_live{ 0 };
long SortTracer::n_assigned{ 0 };
long SortTracer::n_compared{ 0 };

void sort_tracer_test()
{
	SortTracer input[] = { 7,3,5,6,4,2,0,1,9,8 };

	for (int i = 0; i < 10; ++i)
		cout << input[i].val() << ' ';
	cout << "\n";

	//��ȡ��ʼ״̬
	long create_at_start = SortTracer::creations();
	long max_live_at_start = SortTracer::max_live();
	long assigned_at_start = SortTracer::assignments();
	long compared_at_start = SortTracer::comparisons();


	// ִ���㷨
	cout << "---[Start std::sort() ]-------------------------------\n";
	std::sort<>(&input[0], &input[9] + 1);
	cout << "---[End std::sort() ]-------------------------------\n";

	//ȷ�Ͻ��
	for (int i = 0; i < 10; ++i)
		cout << input[i].val() << ' ';
	cout << "\n\n";

	//�������

	cout << "std::sort() of 10 sortTracer's"
		<< " was performed by:\n"
		<< SortTracer::creations() - create_at_start
		<< " temporary tracer\n"
		<< "up to "
		<< SortTracer::max_live()
		<< " tracers at the same time ("
		<< max_live_at_start << " before)\n"
		<< SortTracer::assignments() - assigned_at_start
		<< " assignments\n"
		<< SortTracer::comparisons() - compared_at_start
		<< " comparisons\n\n";
}