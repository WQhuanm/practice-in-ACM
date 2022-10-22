#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;

const int N = 520;
                                       

//                                ///��������
//int book[N][N]; //�����ж�����ֱ����û������
//int indegree[N];//indegree[x]��¼xǰ����ȵĵ��м���
//int mqueue[N];//�����������
//int n, m;
//void tuopu() {
//    int k = 0;
//    for (int i = 1; i <= n; ++i)  //��Ҫ����n���㣬���n�β���
//    {
//        int temp = 0;
//        for (int j = 1; j <= n; ++j) {//��1��ʼ����ȻҲ�ͱ�֤�������С�ԣ���Ϊ���������һ���࣬�Ǵ�����С��j��ʼ�����
//            if (!indegree[j]) {
//                temp = j;  //�ҵ����Ϊ0�ĵ�
//                indegree[j] = -1;//������������ظ�¼����
//                mqueue[++k] = j;
//                break;
//            }
//        }
//
//        for (int j = 1; j <= n; ++j) {
//            if (book[temp][j])indegree[j]--;//Ҫ��ȥtemp������Ϊ0�ĵ㣬���������ӵı߶�Ҫɾ����������ȼ�1
//        }
//
//    }
//    for (int i = 1; i <= k; ++i) {
//        if (i == k)cout << mqueue[i] << endl;
//        else cout << mqueue[i] << " ";
//
//
//}
//}
//
//int main() {
//   
//    while (cin >> n >> m) {
//        memset(book, 0, sizeof(book));
//        memset(indegree, 0, sizeof(indegree));
//        int x, y;
//        for (int i = 1; i <= m; ++i) {
//            cin >> x >> y;
//            if(!book[x][y]){  //û˵���������ݲ����ظ�������ظ������ǲ��ܻ�����ȼ�1�����Ա����ǵ�һ�������Ӳſ����������
//            book[x][y] = 1;
//            indegree[y]++;//����ĵ���ȼ�һ����Ϊǰ�������ӵ�x
//            }
//        }
//        tuopu();
//
//    }
//
//
//    return 0;
//}



//                       //stl����ʵ��
//int book[N][N];
//int indegree[N];
//int n, m;
//void tuopu() {
//    queue<int>q;
//    for (int i = 1; i <= n; ++i)if (!indegree[i]) {
//        q.push(i);
//        indegree[i] = -1;
//        break;
//    }
//    int flag = 1;//����ǲ��ǵ�һ����ӡ
//    while (!q.empty()) {
//        int temp = q.front();
//        q.pop();
//        if (flag) {
//            flag = 0;
//            cout << temp;
//        }
//        else cout << " " << temp;
//
//
//        for (int i = 1; i <= n; ++i) {
//            if (book[temp][i])indegree[i]--;
//
//        }
//        for (int i = 1; i <= n; ++i)if (!indegree[i]) {
//            q.push(i);
//            indegree[i] = -1;
//            break;
//        }
//    }
//    cout << endl;
//
//
//}
//
//int main() {
//    while (cin >> n >> m) {
//        memset(book, 0, sizeof(book));
//        memset(indegree, 0, sizeof(indegree));
//        int x, y;
//        for (int i = 1; i <= m; ++i) {
//            cin >> x >> y;
//            if (!book[x][y]) {
//                book[x][y] = 1;
//                indegree[y]++;
//            }
//        }
//        tuopu();
//    }
//
//
//    return 0;
//}



                                  //�ڽӱ����ٿռ�ռ��
vector<int>v[N];
int indegree[N];
int mqueue[N];
int n, m;
void tuopu() {
    int x, y;
    int k = 0;//��¼�Ѿ�¼�뼸���ź�˳���
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        indegree[y]++;
    }
    for (int i = 1; i <= n; ++i) {
        
        int t=0;
        for (int j = 1; i <= n; ++j) {
            if (!indegree[j]) {
                t = j;
                indegree[j] = -1;
                mqueue[++k] = j;
                break;
            }

        }
        for (int j = 0; j < v[t].size(); ++j) {
            indegree[v[t].at(j)]--;///Ҫ��ȥt������Ϊ0�ĵ㣬���������ӵı߶�Ҫɾ����������ȼ�1
        }

    }
    for (int i = 1; i <= k; ++i) {
        if (i == k)cout << mqueue[i] << endl;
        else cout << mqueue[i] << " ";
    }
}

int main() {
    while (cin >> n >> m) {
        memset(indegree, 0, sizeof(indegree));
        for (int i = 1; i <= n; ++i)v[i].clear();
        tuopu();
    }


}




//
//��N�������ӣ�1 <= N <= 500�����������Ϊ1��2��3������������N���б��������������󣬲���ίԱ��Ҫ�����в��������ǰ�������������������ڲ���ίԱ�᲻��ֱ�ӻ��ÿ���ӵı����ɼ���ֻ֪��ÿ�������Ľ������P1ӮP2����P1��P2��ʾ������ʱP1��P2֮ǰ��������������ȷ��������
//Input
//�����������飬ÿ���еĵ�һ��Ϊ������N��1 <= N <= 500����M������N��ʾ����ĸ�����M��ʾ������M�е��������ݡ���������M�������У�ÿ��Ҳ����������P1��P2��ʾ��P1��Ӯ��P2�ӡ�
//Output
//����һ������Ҫ������������ʱ�����֮���пո����һ������û�пո�
//
//����˵���������������������ܲ���Ψһ�ģ���ʱҪ�����ʱ���С�Ķ�����ǰ���������ݱ�֤����ȷ�ģ�����������ȷ��һ������һ������Ҫ���������