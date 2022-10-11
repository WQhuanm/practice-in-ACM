#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

const int N = 210;
const int INF = 0x3f3f3f3f;

int book[N];  //����Ƿ����;
int dist[N];
int arr[N];
int now[N];      //��¼��Ŀ����ĵ�ǰ��
int n;
void cdis(int x) {
	int count = 0; int t1 = 1, t2 = 0;   //���ڱ�ʾÿ��kѭ��now�е�ͷ��β
	for (int i = 1; i <= n; ++i) {  //������n��book
		count++; int tmp = t2;//�洢��һ�ֵ�t2
		for (int j = 1; j <= n; ++j) {

			if (i == 1) {
				if (!book[j] && (j + arr[j] == x || j - arr[j] == x)) { book[j] = 1; dist[j] = count; now[++t2] = j; }
				
			}
			else {
				for (int k = t1; k <= tmp; ++k) {  //���ﲻ����t2��ʾβ�ͣ���Ϊѭ����t2��ʱ����£����뱣֤����һ�ֵ�t2����tmp
					if (!book[j]&&(j + arr[j] == now[k] || j - arr[j] == now[k])) { book[j] = 1; dist[j] = count; now[++t2] = j; break; }
				}

			}
		
		}
		t1 = tmp+1;  //����t1Ϊ��һ��t2����һ����
	}

}

int main() {
	int a, b;
	while (~scanf("%d", &n)&&n) {
		scanf("%d%d",&a, &b);
		for (int i = 1; i <= n; ++i)cin >> arr[i];
		memset(book, 0, sizeof(book));
		memset(dist, 0x3f, sizeof(dist));
		cdis(b);
		if (a == b) {  //��Ҫ���ˣ�û˵����a==b
			cout << 0 << endl;
		}
		else
		{
			if (dist[a] < INF)cout << dist[a] << endl;
			else cout << -1 << endl;
		}
	}
	

	return 0;
}



//
//��һ����ֵĵ��ݣ�������ͣ���κ�һ�㣬������ÿ��¥����һ��Ki��0 <= Ki <= N��������ֻ��������ť���ϡ��¡������ڵ�i�㣬����㰴�¡�UP����ť���㽫����Ki�㣬Ҳ����˵���㽫�ᵽ���i + Ki�㣬����㰴�¡�DOWN����ť������½� Ki�㣬������ǰ����i - Ki�㡣��Ȼ�����ݲ��ܸ���N��Ҳ���ܵ���1��
//���磬��5��Ľ��������k1 = 3��k2 = 3��k3 = 1��k4 = 2��k5 = 5����1¥��ʼ������԰��¡�UP����ť����ᵽ4¥��������㰴�¡�DOWN����ť�����ݲ���������Ϊ�������µ� - 2¥��
//
//�ʣ�������A¥����ȥB¥ʱ�������밴�¡�UP����DOWN����ť���ٴΣ� ���У�1 <= N, A, B <= 200
//Input
//��������������������
//ÿ�����������������У�
//����һ�а�����������N��A��B��1 <= N��A��B <= 200�����ڶ�����N������k1��k2��... kn��ɡ�
//����0��ʾ���������
//Output
//����ÿ�����ݣ��������A¥��B¥��Ҫ�����ٵİ�ť����������㲻�ܵ���B¥����ֱ����� - 1��


