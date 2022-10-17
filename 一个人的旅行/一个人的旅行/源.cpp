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

虽然草儿是个路痴（就是在杭电待了一年多，居然还会在校园里迷路的人，汗~),但是草儿仍然很喜欢旅行，因为在旅途中 会遇见很多人（白马王子，^0^），很多事，还能丰富自己的阅历，还可以看美丽的风景……草儿想去很多地方，她想要去东京铁塔看夜景，去威尼斯看电影，去阳明山上看海芋，去纽约纯粹看雪景，去巴黎喝咖啡写信，去北京探望孟姜女……眼看寒假就快到了，这么一大段时间，可不能浪费啊，一定要给自己好好的放个假，可是也不能荒废了训练啊，所以草儿决定在要在最短的时间去一个自己想去的地方！因为草儿的家在一个小镇上，没有火车经过，所以她只能去邻近的城市坐火车（好可怜啊~）。
Input
输入数据有多组，每组的第一行是三个整数T，S和D，表示有T条路，和草儿家相邻的城市的有S个，草儿想去的地方有D个；
接着有T行，每行有三个整数a，b，time,表示a,b城市之间的车程是time小时；(1=<(a,b)<=1000;a,b 之间可能有多条路)
接着的第T+1行有S个数，表示和草儿家相连的城市；
接着的第T+2行有D个数，表示草儿想去地方。
Output

