#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>    //使用队列queue（可变长度）的头文件
using namespace std;

const int N = 110;

int v[4];  //表示第几个杯子
struct bei {
	int v[4];//表示当前第几个杯子的状态
	int step;//表示走了多少步
};

bei head, temp;  //建立俩个互相提取与储存

int book[N][N][N];//标记某种状态是否已经尝试过



void pour(int a,int b) {//a给b倒水
	int sum = temp.v[a] + temp.v[b];//表示当前a与b杯子水的总和，如果sum大于v[b]即b杯子的容量，证明a中的水足以倒满b杯子
	if (sum >= v[b]) {
		temp.v[b] = v[b];//a杯子剩余sum减去给b杯子的，剩下就是a的
	}//b杯子倒满情况
	else {
		temp.v[b] = sum;//没有能倒多少倒多少
	}
	temp.v[a] = sum - temp.v[b];  //因为水总量一定，所以俩情况最终都满足a杯子的量的总减去最终b杯子的量
}

void bfs() {
	queue<bei>q;
	head.v[1] = v[1]; head.v[2] = head.v[3] = head.step = 0;
	memset(book, 0, sizeof(book));
	book[v[1]][0][0] = 1;//最开始这个直接标记
	q.push(head);
	while (!q.empty()) {  //当队列没有内容时，返回1，否则为0，我们只要队列有数据，就一直搜索，直到目标
		head = q.front();//取队列第一个数，然后判断
		q.pop();//取完就删，已经存到head里了
		if (head.v[1] == head.v[2] && head.v[3] == 0) { cout << head.step << endl; return; }//已经保证杯子容量v[1]>v[2]>=v[3],那么结果只需看这个if就好，成功剪枝
		for (int i = 1; i <= 3; ++i)for (int j = 1; j <= 3; ++j) {
			if (i != j) {  //不能给自己倒水
				temp = head;//注意，每一次i*j的循环，都是取自前面储存的同一个head，即对head进行各种可能步骤并合法就储存
				pour(i, j);
				if (!book[temp.v[1]][temp.v[2]][temp.v[3]]) {
					book[temp.v[1]][temp.v[2]][temp.v[3]] = 1;
					temp.step++;
					q.push(temp);
				}
			}

	}

	}
	cout << "NO" << endl;//只有队列空了还没有访问结果，说明不符合，才会跳出while来到这里

}

int main() {
	
	while (~scanf("%d%d%d", &v[1], &v[2], &v[3]) && (v[1] || v[2] || v[3])) {
		if (v[1] % 2 != 0)cout << "NO" << endl;
		else {
			if (v[2] < v[3])swap(v[2], v[3]);
			bfs();
		}
	}


	return 0;
}