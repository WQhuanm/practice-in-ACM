#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
              //N为四位数，使用Floyd会超时
const int INF = 0x3f3f3f3f;
const int N = 1010;

int arr[N][N];
int book[N];
int dis[N];
int ss[N];
int dd[N];
int maxn;

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));  //每次进入dijkstra都应该重新初始化，不能受上一组的影响，所以book与dis的初始化应该写这里而不是主函数，而且是放最开头（循环外面）
    memset(book, 0, sizeof(book));
    for (int i = 0; i <= maxn+1; ++i) {
        int tmp = -1;
        dis[0] = 0;
        for (int j = 0; j <= maxn+1; ++j)if (!book[j] && (tmp == -1 || dis[j] < dis[tmp]))tmp = j;
        book[tmp] = 1;
        for (int k = 1; k <= maxn+1; ++k)dis[k] = min(dis[k], arr[tmp][k] + dis[tmp]);

    }
   
}


int main() {
    int t, s, d;
    while (~scanf("%d%d%d", &t, &s, &d)) {
        memset(arr, 0x3f, sizeof(arr));
       
        int a, b, time;
        maxn = -INF;  //maxn用于记录最大城市的坐标，减少无用的多余坐标循环
        for (int i = 1; i <= t; ++i) {
            cin >> a >> b >> time;
            arr[a][b] = arr[b][a] = min(arr[a][b], time);
            maxn = max(maxn, max(a, b));
        }
        for (int i = 1; i <= s; ++i) {
            cin >> ss[i];
            arr[0][ss[i]] = 0;
        }
        for (int i = 1; i <= d; ++i) {
            cin >> dd[i]; arr[dd[i]][maxn + 1] = 0;
        }
        dijkstra();
            cout << dis[maxn + 1] << endl;
            //多起点其实可以设置一个超级起点，这些起点到他距离为0，同理，多个终点搞个超级终点，这样就不用n*m的迪杰斯特拉，只需要一次
    }

    return 0;
}