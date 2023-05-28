#include<iostream>
#include<iterator>
#include<vector>
#include<deque>
#include<list>
#include<algorithm>
#include<functional>
#include<numeric>
//functional�ǹٷ��ṩ�ĺ��������
//���ͱ�̣����ͳ�����Ƹ�����ϵ
//1.����ɱȽϵģ���=��
//2.ģ�ͣ����ϸ������������
//3.�ø�����ģ�������
//4.�����������������㷨�����ģ�������������
//�㷨Ҫ����������������ݣ�ͨ��
//5.���������㷨�����������������������㷨�Ĳ�����ͨ����������������������ֱ�ӷ���
//��װ�������Լ����ܿ�������ַ�������е�����������ָ�룬ÿһ���������ܲ���������
//6.���Դ��ݺ�������

using namespace std;
//��ʼ��
vector<int> numbers1(10, 2);
deque<int> numbers2(10, 0);
list<int> numbers3 {8, 5, 2, 4, 1, 3, 6, 5, 2, 1, 4, 7};
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
vector<int> numbers4(arr, arr + 10);//ʹ�õ�����
vector<int> numbers5 = { 1,2,3,4,5,6,7,8,9,10 };
template<class T>
class Number
{
public:
	Number(T data = 0)
		:_data(data)
	{}
	void print() const
	{
		cout << _data << " ";
	}
	T _data;
};

template<typename Ta, typename Tb>
struct Compare
{
	bool operator()(const Ta& a, const Tb& b) const
	{
		return a < b;
	}
};
template <typename Container>
void display(const Container& c)
{
	for (auto& elem : c)
	{
		cout << elem << " ";
	}
	cout << endl;
}
//vector���ò���
void test1()//��������
{
	//����1.�±����
	for (size_t idx = 0; idx != numbers1.size(); ++idx)
	{
		cout << numbers1[idx] << " ";
	}
	cout << endl;
	//����2������������
	cout << " ********************** " << endl;
	vector<int>::const_iterator it;//ֻ���ʲ��޸�
	for (it = numbers1.begin(); it != numbers1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//auto������
	cout << " ********************** " << endl;
	auto it1 = numbers1.begin();
	for (; it1 != numbers1.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	//auto����
	cout << " ********************** " << endl;
	for (auto& elem : numbers1)//elemΪ��������
	{
		cout << elem << " ";
	}
	cout << endl;
}
//push_back,pop_back β�������ɾ����
//push_front,pop_front ͷ������ɾ��
void test2()
{
	//&numbers1;
	//&numbers1[0];
	//&*numbers1.begin();
	int* pdata = numbers4.data();
	cout << "pdata = " << *pdata << endl;
}
//�м����
void test3()
{
	vector<int> vec{20, 23, 28};
	vector<int>::const_iterator it = numbers1.begin();
	++it;
	++it;
	numbers1.insert(it, vec.begin(), vec.end());
	for (auto& elem : numbers1)
	{
		cout << elem << " ";
	}
	cout << endl;
}

//list��Ա����
void testlist_1()
{
	numbers3.sort();
	numbers3.unique();
	list<int> num{11, 21, 31};
	numbers3.merge(num);
	numbers3.reverse();
	display(numbers3);
}

//���ң�1.��count���ز���Ԫ����Ŀ��2.find���صĵ�����λ��

//bind��������ͨ����
//mem_fn()��Ϊ��Ա�������������ܸ����й㷺�ԣ�
int add(int x, int y)
{
	cout << "int add" << endl;
	return x + y;
}
//����ָ��
typedef int(*pFunc)();
int func() {
	return 912;
}
void test4() {
	auto f = bind(add, 3, 5);//Ҳ����������������������ʽ��
	using namespace std::placeholders;//ռλ��
	auto f1 = bind(add, 3, _1);
	cout << "f() = " << f() << endl;
	cout << "f1() = " << f1(10) << endl;
	pFunc g = func;
	cout << "g() =" << g() << endl;
}
//for_each,remove_ifΪ���������㷨
void test5()
{
	vector<Number<int>> numbers;
	for (size_t idx = 1; idx != 10; ++idx)
	{
		numbers.push_back(Number<int>(idx));
	}
	std::for_each(numbers.begin(), numbers.end(), mem_fn(&Number<int>::print));
}
int main()
{
	test5();
	return 0;
}