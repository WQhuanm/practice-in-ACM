#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
              //NΪ��λ����ʹ��Floyd�ᳬʱ
const int INF = 0x3f3f3f3f;
const int N = 1010;

int arr[N][N];
int book[N];
int dis[N];
int ss[N];
int dd[N];
int maxn;

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));  //ÿ�ν���dijkstra��Ӧ�����³�ʼ������������һ���Ӱ�죬����book��dis�ĳ�ʼ��Ӧ��д����������������������Ƿ��ͷ��ѭ�����棩
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
        maxn = -INF;  //maxn���ڼ�¼�����е����꣬�������õĶ�������ѭ��
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
            //�������ʵ��������һ��������㣬��Щ��㵽������Ϊ0��ͬ������յ��������յ㣬�����Ͳ���n*m�ĵϽ�˹������ֻ��Ҫһ��
    }

    return 0;
}