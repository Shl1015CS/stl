#include<iostream>
#include<iterator>
#include<vector>
#include<deque>
#include<list>
#include<algorithm>
#include<functional>
#include<numeric>
//functional是官方提供的函数对象库
//泛型编程，泛型程序设计概念体系
//1.概念：可比较的，可=的
//2.模型：符合概念的数据类型
//3.用概念做模板参数名
//4.容器，迭代器，“算法（核心）”，函数对象
//算法要泛化，处理多种数据，通用
//5.迭代器是算法和容器的桥梁，迭代器是算法的参数，通过迭代器访问容器而不是直接访问
//封装容器，自己可能看不到地址，但是有迭代器，泛型指针，每一种容器都能产生迭代器
//6.可以传递函数对象

using namespace std;
//初始化
vector<int> numbers1(10, 2);
deque<int> numbers2(10, 0);
list<int> numbers3 {8, 5, 2, 4, 1, 3, 6, 5, 2, 1, 4, 7};
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
vector<int> numbers4(arr, arr + 10);//使用迭代器
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
//vector常用操作
void test1()//遍历访问
{
	//遍历1.下标访问
	for (size_t idx = 0; idx != numbers1.size(); ++idx)
	{
		cout << numbers1[idx] << " ";
	}
	cout << endl;
	//遍历2：迭代器访问
	cout << " ********************** " << endl;
	vector<int>::const_iterator it;//只访问不修改
	for (it = numbers1.begin(); it != numbers1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//auto迭代器
	cout << " ********************** " << endl;
	auto it1 = numbers1.begin();
	for (; it1 != numbers1.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	//auto遍历
	cout << " ********************** " << endl;
	for (auto& elem : numbers1)//elem为数组引用
	{
		cout << elem << " ";
	}
	cout << endl;
}
//push_back,pop_back 尾部插入和删除；
//push_front,pop_front 头部插入删除
void test2()
{
	//&numbers1;
	//&numbers1[0];
	//&*numbers1.begin();
	int* pdata = numbers4.data();
	cout << "pdata = " << *pdata << endl;
}
//中间插入
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

//list成员操作
void testlist_1()
{
	numbers3.sort();
	numbers3.unique();
	list<int> num{11, 21, 31};
	numbers3.merge(num);
	numbers3.reverse();
	display(numbers3);
}

//查找：1.有count返回查找元素数目。2.find返回的迭代器位置

//bind函数绑定普通函数
//mem_fn()作为成员函数绑定器，功能更具有广泛性，
int add(int x, int y)
{
	cout << "int add" << endl;
	return x + y;
}
//函数指针
typedef int(*pFunc)();
int func() {
	return 912;
}
void test4() {
	auto f = bind(add, 3, 5);//也可以类名：：函数名的形式绑定
	using namespace std::placeholders;//占位符
	auto f1 = bind(add, 3, _1);
	cout << "f() = " << f() << endl;
	cout << "f1() = " << f1(10) << endl;
	pFunc g = func;
	cout << "g() =" << g() << endl;
}
//for_each,remove_if为两个常用算法
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