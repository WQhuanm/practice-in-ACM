#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 210;
                      //爸爸只有一个，而学生可能有好多个，所以应该逆向，爸爸去找人（因为bfs适合一到多）
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
		q.pop();//取完立刻删，再干别的
		if (head.step < minn) {
		for (int i = 0; i < 4; ++i) {//我们给的走法是从下标0开始，不是1
			temp = head;
			temp.x += way[i][0];
			temp.y += way[i][1];
			if (at[temp.x][temp.y] != '#' && !book[temp.x][temp.y] && temp.x >= 1 && temp.x <= n && temp.y >= 0 && temp.y < m) {
				book[temp.x] [temp.y] = 1;
				if (at[temp.x][temp.y] == '.')temp.step++;
				else if (at[temp.x][temp.y] == 'r') {
					temp.step++;   //终点也是有距离的，为1
					minn = min(minn, temp.step);          //因为不同位置加的step不一样，所以必须存储minn了
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
//丁爸被火星人抓走了，关在一个N* M（N，M <= 200）矩形的监狱（监狱里有墙壁、道路和警卫队）。
//
//丁爸的学生想拯救他（到达丁爸停留的位置即视为成功）。拯救过程中若遇到警卫，则必须干掉（丁爸的学生足够强大，能够战胜所有的警卫）。假设每次向上，向下，向右，向左移动需要1个单位时间，杀死一个守卫额外需要1个单位时间。
//
//请计算：拯救丁爸需要的最短时间（每次只能上，下，左，右移动到边界内的邻居网格）。
//Input
//题目包含多组测试数据。
//
//每组数据第一行包含两个整数N和M。
//然后是N行，每行包含M个字符。
//其中：
//“.” 代表道路，
//“a”代表丁爸的位置，
//每个“r”代表丁爸的一个学生，
//"x"代表警卫，
//“#”代表墙壁。
//
//处理到文件的末尾。
//Output
//对于每组数据，请输出拯救丁爸需要的最短时间。
//如果实在无法救出丁爸，请输出一句： "Poor Dingba has to stay in the prison all his life."
//每组数据输出一行。
//Sample Input