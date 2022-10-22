#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;

const int N = 10010;

int n, m;
int indegree[N];   //��֪�����ֵ�Ƕ��٣�����֪����Сֵ����������ͳ������СΪͷ����ȣ���Сֵ���Ϊ0����indegree[x]Ϊ0��˵��û�б���С��ֵ�����Ϊ0
vector<int>v[N];//����һ��һά�ǳ���ΪN����ά�Ƕ�̬�任�����������ٲ���Ҫ�ռ��˷�
int ans[N];//��¼ÿ����Ӧ����Ǯ
void tuopu() {
	int x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;//x�Ǵ�ֵ��y��Сֵ
		v[y].push_back(x);//�����y���x
		indegree[x]++;//��ʾ��xС��ֵ
	}
	int sum = 0;//����ж��ٸ����Ϊ0��������н������ô���տ϶����ж������Ϊ0������֤��������
	for (int i = 1; i <= n; ++i) {  //������n��
		int t = 0;//��ʱ����Сֵ
		for (int j = 1; j <= n; ++j) {
			if (!indegree[j]) {
				sum++;
				t = j;
				indegree[j] = -1;//��ֹ�ظ�ͳ�Ƶ���
				break;
			}
		}
		for (int j = 0; j < v[t].size(); ++j)//v[t].size()��ʾt��һ���ж���Ԫ�أ������±��0��ʼ������j=0��ʼ��Ȼ����<�ͺ�
		{
			int temp = v[t].at(j);//��temp��ʱ�����������Ѿ���ı�t���ֵ
			indegree[temp]--;//��ȥ��t�����tempС��
			ans[temp] = max(ans[temp], ans[t] + 1);//temp��Ǯ���ٱ�t��Ǯ��һԪ
		}
	}
	if (sum == n) {
		int h = 0;//�Ѹ�������ֵ�ܺ�
		for (int i = 1; i <= n; ++i) {
			h += ans[i];
		}
		cout << h + n * 888 << endl;

	}
	else cout << -1 << endl;
}


int main() {
	while (cin >> n >> m) {
		memset(indegree, 0, sizeof(indegree));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i <= n; ++i)v[i].clear();   //���������ֻ��һ��һ����
		tuopu();
	}

	return 0;
}

//�ʳ�����һ�������˾�Ĵ�ʼ�ˣ��˳ơ����ϰ塱��
//
//���������Ŭ������˾�Ѿ�׼������˹������У����ϰ���ȻҲ�������á���������ڵ��ٽ������ϰ����ΪԱ����ÿ�˷��������
//
//���ڵ������ǣ�ÿ�˷����ٺ���أ�Ҫ֪�����ܶ�Ա��������Լ���Ҫ�󣬱��磬��������������ĺ��Ӧ�ñ�����Զ�Ĵ�
//
//Ϊ��ͼ���������ϰ����Ϊÿ��Ա�����ٷ�888�ĺ����ͬʱ������ϣ��������Ա������������е�Ҫ�󣬵�Ȼ�������ϣ������������ܽ�����١�
//Input
//�����������������ݡ�
//ÿ�����ݵ�һ����������������n��m���ֱ��ʾԱ����������n��Ա����һ�������m��Ҫ��
//���ŵ�m�У�ÿ�а���2������a��b����ʾһ��Ҫ��a�ĺ��Ӧ�ñ�b�Ĵ�
//
//n <= 10000
//m <= 20000
//Ա�����a��b���ȣ��Ҷ�������[1, n]��