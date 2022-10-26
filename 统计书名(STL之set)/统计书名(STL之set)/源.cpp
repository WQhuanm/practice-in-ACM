#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#define ll long long
using namespace std;
const int N = 100;
string a;

int main() {
	int n;
	while (cin >> n) {
		set<string>s;
		while (n--) {
			cin >> a;
			s.insert(a);
		}

		cout << s.size() << endl;

	}


	return 0;
}


//set就是集合，STL的set用二叉树实现，集合中的每个元素只出现一次(参照数学中集合的互斥性)，并且是排好序的(默认按键值升序排列)
//
//访问元素的时间复杂度是O(log ⁡ 2 n)





//
//
//set<int> q;     //以int型为例 默认按键值升序
//set<int, greater<int>> p;  //降序排列 
//int x;
//q.insert(x);	//将x插入q中
//q.erase(x);		//删除q中的x元素,返回0或1,0表示set中不存在x
//q.clear();		//清空q
//q.empty();		//判断q是否为空，若是返回1，否则返回0
//q.size();		//返回q中元素的个数
//q.find(x);		//在q中查找x，返回x的迭代器，若x不存在，则返回指向q尾部的迭代器即 q.end()
//q.lower_bound(x); //返回一个迭代器，指向第一个键值不小于x的元素
//q.upper_bound(x); //返回一个迭代器，指向第一个键值大于x的元素
//
//q.rend();		  //返回第一个元素的的前一个元素迭代器
//q.begin();		  //返回指向q中第一个元素的迭代器
//
//q.end();		 //返回指向q最后一个元素下一个位置的迭代器
//q.rbegin();		 //返回最后一个元素
