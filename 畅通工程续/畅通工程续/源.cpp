#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;
//                               //froly�㷨�����Ӷ�O��n^3),������������̾���
//const int MAXN = 0x3f3f3f3f;     //��maxn��Ҫ��󣬷�ֹ���������￪2e9���ᱻ��
//const int N = 210;
//
//int arr[N][N];
//
//int main() {
//	int n, m;
//	while (scanf("%d %d", &n, &m) == 2) {
//		int a, b, c;
//		memset(arr, 0, sizeof(arr));  //��Ҫ���˶�������Ҫ����
//		for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j) {
//			if (i == j)arr[i][j] = 0;   //��ʼ��ʱ��i==j��˵��������յ�һ������ô����϶���0�������ʼ��Ϊ�����
//			else arr[i][j] = MAXN;   
//		}
//		for (int i = 1; i <= m; ++i) {
//			scanf("%d %d %d", &a, &b, &c);
//			if(arr[a][b]>c)arr[a][b]=arr[b][a] = c;
//
//		}            
//		for (int k = 0; k < n; ++k)for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);//ע�⣬k����ǰ��ѭ������ʾ��k��Ϊ�м�ʱ������յ����
//		int s, t;
//		cin >> s >> t;
//		if (arr[s][t] >= MAXN)cout << -1 << endl;
//		else cout << arr[s][t] << endl;
//	}
//	return 0;
//}

                        //�Ͻ�˹��������̰�ģ�,ʱ�临�Ӷ�O��n^2)
const int INF = 0x3f3f3f3f;
const int N = 210;

int arr[N][N];  //arr[i][j]��ʾi��j����
int book[N];//����Ƿ񱻷��ʹ�
int dis[N];//dis[i]��ʾi��Ŀ��ľ���

int n, m;

void dijsktra(int x) {
	for (int i = 0; i < n; ++i) {  //��Ҫÿ����Ѱ��һ��
		int tmp = -1;
		dis[x] = 0;//Ŀ�굽Ŀ�����϶�Ϊ0
		for (int j = 0; j < n; ++j) {  //ÿһ�α����ҵ�ǰ��С
			if (!book[j] && (tmp == -1 || dis[j] < dis[tmp]))tmp = j;//tmp = -1�Ǳ�֤��һ����һ���ܽ�����֮�����Ѱ��Ŀǰ��Ŀ������ĵ㣨���Ϊtmp��
			                     //ע��tmp==-1��Ҫд��=-1
		}
		book[tmp] = 1;//�ȱ��Ϊ�Ѿ�����
		for (int k=0; k < n; ++k)dis[k] = min(dis[k], dis[tmp] + arr[tmp][k]);  //��������dis[tmp]���õ���һ�ֵ���Ŀ�������dis[]
		//���ﻹ��iѭ�����棬��Ҫ��С�Ļ���i��ѭ��
	}

}

int main() {
	while (~scanf("%d %d", &n, &m)) {
		memset(arr, 0x3f, sizeof(arr));  //memsetÿ�δ���һ���ֽڣ�int��4���ֽڣ���ô0x3f��Ӧ4���ֽھ���0x3f3f3f3f
		memset(book, 0, sizeof(book));//book==0��ʾ��δ������
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			arr[a][b] =arr[b][a]= min(arr[a][b], c);
		}
		int s, t;
		cin >> s >> t;
		dijsktra(s);
		if (dis[t] < INF)cout << dis[t] << endl;
		else cout << -1 << endl;
	}

	return 0;
}











//
//ĳʡ�Դ�ʵ���˺ܶ���ĳ�ͨ���̼ƻ��������޽��˺ܶ�·������·����Ҳ���ã�ÿ��Ҫ��һ��������һ������ʱ����������ֵ�·��������ѡ�񣬶�ĳЩ����Ҫ����һЩ�������ߵľ���Ҫ�̺ܶࡣ�������˺����š�
//
//���ڣ���֪�����յ㣬��������Ҫ����㵽�յ㣬�����Ҫ���߶��پ��롣
//Input
//����Ŀ�����������ݣ��봦���ļ�������
//ÿ�����ݵ�һ�а�������������N��M(0 < N < 200, 0 < M < 1000)���ֱ�������г������Ŀ�����޽��ĵ�·����Ŀ������ֱ���0��N - 1��š�
//	��������M�е�·��Ϣ��ÿһ������������A, B, X(0 <= A, B < N, A != B, 0 < X < 10000), ��ʾ����A�ͳ���B֮����һ������ΪX��˫���·��
//	�ٽ���һ������������S, T(0 <= S, T < N)���ֱ���������յ㡣
//	Output
//	����ÿ�����ݣ�����һ������������Ҫ���ߵľ��롣��������ڴ�S��T��·�ߣ������ - 1.

