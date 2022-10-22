#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;

const int N = 520;
                                       

//                                ///朴素拓扑
//int book[N][N]; //用于判定俩者直接有没有连接
//int indegree[N];//indegree[x]记录x前面入度的点有几个
//int mqueue[N];//拓扑完的序列
//int n, m;
//void tuopu() {
//    int k = 0;
//    for (int i = 1; i <= n; ++i)  //需要遍历n个点，最多n次操作
//    {
//        int temp = 0;
//        for (int j = 1; j <= n; ++j) {//从1开始，自然也就保证了序号最小性，因为当我们入度一样多，是从数字小的j开始入队列
//            if (!indegree[j]) {
//                temp = j;  //找到入度为0的点
//                indegree[j] = -1;//避免后续操作重复录入他
//                mqueue[++k] = j;
//                break;
//            }
//        }
//
//        for (int j = 1; j <= n; ++j) {
//            if (book[temp][j])indegree[j]--;//要除去temp这个入度为0的点，与他有连接的边都要删除，让其入度减1
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
//            if(!book[x][y]){  //没说过给的数据不能重复，如果重复，我们不能还是入度加1，所以必须是第一次有连接才可以入度增加
//            book[x][y] = 1;
//            indegree[y]++;//后面的点入度加一，因为前面有连接点x
//            }
//        }
//        tuopu();
//
//    }
//
//
//    return 0;
//}



//                       //stl队列实现
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
//    int flag = 1;//标记是不是第一个打印
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



                                  //邻接表，减少空间占用
vector<int>v[N];
int indegree[N];
int mqueue[N];
int n, m;
void tuopu() {
    int x, y;
    int k = 0;//记录已经录入几个排好顺序的
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
            indegree[v[t].at(j)]--;///要除去t这个入度为0的点，与他有连接的边都要删除，让其入度减1
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
//有N个比赛队（1 <= N <= 500），编号依次为1，2，3，。。。。，N进行比赛，比赛结束后，裁判委员会要将所有参赛队伍从前往后依次排名，但现在裁判委员会不能直接获得每个队的比赛成绩，只知道每场比赛的结果，即P1赢P2，用P1，P2表示，排名时P1在P2之前。现在请你编程序确定排名。
//Input
//输入有若干组，每组中的第一行为二个数N（1 <= N <= 500），M；其中N表示队伍的个数，M表示接着有M行的输入数据。接下来的M行数据中，每行也有两个整数P1，P2表示即P1队赢了P2队。
//Output
//给出一个符合要求的排名。输出时队伍号之间有空格，最后一名后面没有空格。
//
//其他说明：符合条件的排名可能不是唯一的，此时要求输出时编号小的队伍在前；输入数据保证是正确的，即输入数据确保一定能有一个符合要求的排名。