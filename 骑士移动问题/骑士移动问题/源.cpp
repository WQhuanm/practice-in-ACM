#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

//����queue��ʹ��
//1������һ�����У���ʼ������queue<int>q1;//�м������ͣ�ע�⣺������vector������ʼ��queue
//push() �ڶ�β����һ��Ԫ��
//pop() ɾ�����е�һ��Ԫ��
//size() ���ض�����Ԫ�ظ���
//empty() ������п��򷵻�true
//front() ���ض����еĵ�һ��Ԫ��
//back() ���ض��������һ��Ԫ��
//





//int mnext[8][2] = { {2,1},{1,2},{2,-1},{1,-2},{-2,1},{-1,2},{-1,-2},{-2,-1} };//��ʿ����һ����8���߷�
//int a1, a2, b1, b2; //aΪ��㣬bΪ�յ�,a1Ϊ�У�a2Ϊ��
//char a[10]; char b[10];//��ʾa����b��,���鲻�ܿ��ոպã�������һ��λ������������Ȼ��bug
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
//		if (head.x == b2 && head.y == b1) {//�����ڶ����е�ֵ����һ����С�������Ե�һ���ҳ���һ�������Ž⣬�Ͻ�����
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
//int mnext[8][2] = { {2,1},{1,2},{2,-1},{1,-2},{-2,1},{-1,2},{-1,-2},{-2,-1} };//��ʿ����һ����8���߷�
//int a1, a2, b1, b2; //aΪ��㣬bΪ�յ�,a1Ϊ�У�a2Ϊ��
//char a[10]; char b[10];//��ʾa����b��
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
//		book[a2][a1] = 1;//bfsÿһ������Ҫ��ձ�ǣ�������ʼ��Ϊ1
//		head = q.front();
//		q.pop();
//		if (head.x == b2 && head.y == b1) {
//			cout << "To get from " << a << " to " << b << " takes " << head.step << " knight moves." << endl;
//			return;//�Ǿͷ��أ��϶������Ž�
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