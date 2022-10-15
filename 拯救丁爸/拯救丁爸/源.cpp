#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 210;
                      //�ְ�ֻ��һ������ѧ�������кö��������Ӧ�����򣬰ְ�ȥ���ˣ���Ϊbfs�ʺ�һ���ࣩ
struct room {
	int x, y;
	int step;
};

room head, temp;

int n, m;
int way[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int book[N][N];
char at[N][N];


void bfs() {
	queue<room>q;
	int minn = INF;
	memset(book, 0, sizeof(book));
	for (int i = 1; i <= n; ++i)for (int j = 0; j < m; ++j) {
		cin >> at[i][j]; 
		if (at[i][j] == 'a') {
			head.x = i; head.y = j; head.step = 0; q.push(head);
			book[i][j] = 1;
		}
	}
	while (!q.empty()) {
		head = q.front();
		q.pop();//ȡ������ɾ���ٸɱ��
		if (head.step < minn) {
		for (int i = 0; i < 4; ++i) {//���Ǹ����߷��Ǵ��±�0��ʼ������1
			temp = head;
			temp.x += way[i][0];
			temp.y += way[i][1];
			if (at[temp.x][temp.y] != '#' && !book[temp.x][temp.y] && temp.x >= 1 && temp.x <= n && temp.y >= 0 && temp.y < m) {
				book[temp.x] [temp.y] = 1;
				if (at[temp.x][temp.y] == '.')temp.step++;
				else if (at[temp.x][temp.y] == 'r') {
					temp.step++;   //�յ�Ҳ���о���ģ�Ϊ1
					minn = min(minn, temp.step);          //��Ϊ��ͬλ�üӵ�step��һ�������Ա���洢minn��
				}
				else if (at[temp.x][temp.y] == 'x')temp.step += 2;
				q.push(temp);
			}

		}
	}

	}
	if (minn < INF)cout << minn << endl;
	else cout << "Poor Dingba has to stay in the prison all his life." << endl;
}

		
int main() {
	while (~scanf("%d %d", &n, &m)) {

		bfs();
	}

	return 0;
}

//
//���ֱ�������ץ���ˣ�����һ��N* M��N��M <= 200�����εļ�������������ǽ�ڡ���·�;����ӣ���
//
//���ֵ�ѧ���������������ﶡ��ͣ����λ�ü���Ϊ�ɹ��������ȹ����������������������ɵ������ֵ�ѧ���㹻ǿ���ܹ�սʤ���еľ�����������ÿ�����ϣ����£����ң������ƶ���Ҫ1����λʱ�䣬ɱ��һ������������Ҫ1����λʱ�䡣
//
//����㣺���ȶ�����Ҫ�����ʱ�䣨ÿ��ֻ���ϣ��£������ƶ����߽��ڵ��ھ����񣩡�
//Input
//��Ŀ��������������ݡ�
//
//ÿ�����ݵ�һ�а�����������N��M��
//Ȼ����N�У�ÿ�а���M���ַ���
//���У�
//��.�� �����·��
//��a�������ֵ�λ�ã�
//ÿ����r�������ֵ�һ��ѧ����
//"x"��������
//��#������ǽ�ڡ�
//
//�����ļ���ĩβ��
//Output
//����ÿ�����ݣ���������ȶ�����Ҫ�����ʱ�䡣
//���ʵ���޷��ȳ����֣������һ�䣺 "Poor Dingba has to stay in the prison all his life."
//ÿ���������һ�С�
//Sample Input