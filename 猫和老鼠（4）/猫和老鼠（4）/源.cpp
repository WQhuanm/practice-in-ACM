#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 110;
int n, k;
int a[N][N];
int maxn[N][N];
struct set {
	int x, y, lk, sum;
};
set temp, head;

int way[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };//作为基向量，要多少步乘法就好

void bfs() {
	for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)cin >> a[i][j];
	head.x = head.y = 0; head.sum = head.lk = a[0][0];
	queue<set>q;
	q.push(head);
	int ans = -INF;
	memset(maxn, 0, sizeof(maxn));
	while (!q.empty()) {  //bfs注意边界判定
		head = q.front();
		q.pop();

		for (int i = 0; i <= 3; ++i)for (int j = 1; j <= k; ++j) {
			temp = head;
			temp.x += way[i][0]*j; 
			temp.y += way[i][1]*j;
			if (temp.lk >= a[temp.x][temp.y] || temp.x<0 || temp.x>n || temp.y<0 || temp.y>n)continue;
			if (temp.sum + a[temp.x][temp.y] <= maxn[temp.x][temp.y])continue;
				
				temp.sum += a[temp.x][temp.y];
				maxn[temp.x][temp.y] = temp.sum;
				temp.lk = a[temp.x][temp.y];
				q.push(temp);
				ans = max(ans, temp.sum);
			
		}
	}
	cout << ans << endl;
}

int main() {
	
	while (cin >> n >> k && (n != -1 || k != -1))
	{
		/*memset(maxn, 0, sizeof(maxn));
		for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)cin >> a[i][j];
		
		cout <<dfs(0,0)<< endl;*/
		bfs();
	}

	return 0;
}

//int dfs(int x,int y) {
//	if (maxn[x][y])return maxn[x][y]; //不为0，证明已经求过从他出发获得的最大值
//	maxn[x][y] = a[x][y];//先加上自己位置的值
//	
//	for (int i = 0; i <= 3; ++i)for (int j = 1; j <= k; ++j) {
//		int tx = x + way[i][0]*j; int ty = y + way[i][1]*j;
//		if (a[x][y] < a[tx][ty] && tx >= 0 && tx < n && ty >= 0 && ty < n)maxn[x][y] = max(maxn[x][y], a[x][y] + dfs(tx, ty));  //这里a[x][y]+dfs(tx,ty)还是要加a[x][y]，不可以加maxn[x][y]
//	}                                                                                        //加的应该是该点的值，而不是到达该点的最大值
//	return maxn[x][y];
//
//}


