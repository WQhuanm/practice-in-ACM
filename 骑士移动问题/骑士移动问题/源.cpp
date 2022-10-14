#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

//队列queue的使用
//1，申请一个队列（初始化）：queue<int>q1;//中间是类型，注意：不能用vector容器初始化queue
//push() 在队尾插入一个元素
//pop() 删除队列第一个元素
//size() 返回队列中元素个数
//empty() 如果队列空则返回true
//front() 返回队列中的第一个元素
//back() 返回队列中最后一个元素
//





//int mnext[8][2] = { {2,1},{1,2},{2,-1},{1,-2},{-2,1},{-1,2},{-1,-2},{-2,-1} };//骑士与马一样，8种走法
//int a1, a2, b1, b2; //a为起点，b为终点,a1为列，a2为行
//char a[10]; char b[10];//表示a点与b点,数组不能开刚刚好，必须留一个位给结束符，不然出bug
//struct set {
//	int x; int y; int step;
//};
//set head, temp;
//
//void dfs() {
//	queue<set>q;
//	head.y = a1; head.x = a2; head.step = 0;
//	q.push(head);
//	while (!q.empty()) {
//		head = q.front();
//		q.pop();
//		if (head.x == b2 && head.y == b1) {//储存在队列中的值步骤一定由小到大，所以第一个找出的一定是最优解，赶紧跳出
//			cout << "To get from " << a << " to " << b << " takes " << head.step << " knight moves." << endl;
//			break;
//		}
//		for (int i = 0; i <= 7; ++i){
//			temp.x = head.x + mnext[i][0];
//			temp.y = head.y + mnext[i][1];
//			if (temp.x >= 1 && temp.x <= 8 && temp.y >= 1 && temp.y <= 8) {
//				temp.step = head.step + 1;
//				q.push(temp);
//			}
//
//		}
//	}
//}
//int main() {
//
//	while (~scanf("%s %s", a,b)) {
//		a1 = a[0] - 'a' + 1; a2 = a[1] - '0';
//		b1 = b[0] - 'a' + 1; b2 = b[1] - '0';
//		dfs();
//		
//	}
//
//	return 0;
//}

//
//const int INF = 0x3f3f3f3f;
//const int N = 10;
//int mnext[8][2] = { {2,1},{1,2},{2,-1},{1,-2},{-2,1},{-1,2},{-1,-2},{-2,-1} };//骑士与马一样，8种走法
//int a1, a2, b1, b2; //a为起点，b为终点,a1为列，a2为行
//char a[10]; char b[10];//表示a点与b点
//int minn;
//int book[N][N];
//
//struct set {
//	int x; int y; int step;
//};
//set head, temp;
//
//void bfs() {
//	queue<set>q;
//	head.x = a2; head.y = a1; head.step = 0;
//	q.push(head);
//	while (!q.empty()) {
//		memset(book, 0, sizeof(book));
//		book[a2][a1] = 1;//bfs每一次来都要清空标记，并让起始点为1
//		head = q.front();
//		q.pop();
//		if (head.x == b2 && head.y == b1) {
//			cout << "To get from " << a << " to " << b << " takes " << head.step << " knight moves." << endl;
//			return;//是就返回，肯定是最优解
//		}
//		
//		for (int i = 0; i <= 7; ++i) {
//			temp.x = head.x + mnext[i][0];
//			temp.y = head.y + mnext[i][1];
//			if (temp.x >= 1 && temp.x <= 8 && temp.y >= 1 && temp.y <= 8 && !book[temp.x][temp.y]) {
//				book[temp.x][temp.y] = 1;
//				temp.step = head.step + 1;
//				q.push(temp);
//
//			}
//		}
//
//		
//
//	}
//
//
//
//
//}
//
//int main() {
//
//	while (~scanf("%s %s", a,b)) {
//		a1 = a[0] - 'a' + 1; a2 = a[1] - '0';
//		b1 = b[0] - 'a' + 1; b2 = b[1] - '0';
//		
//		minn = INF;
//		bfs();
//
//		
//	}
//
//	return 0;
//}