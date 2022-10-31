#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll         long long
#define endl       "\n"
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
ll a[N];
void fastsort( int begin, int end)
{
	ll tmp = a[(begin + end) / 2];//先分为俩半
	int l = begin, r = end;//储存头尾
	do
		{
			while (a[l] < tmp )//比中间小就往后
				{
					l++;
				}
			while (a[r] > tmp )//同理
				{
					r--;
				}
			if (l <= r)  //等于也交换，关键是为了l与r的靠近
				{
					swap(a[l],a[r]);
					l++;
					r--;
				}
		}
	while (l <= r);//一直进行直到l比r大
	if (begin < r)	fastsort( begin, r );//遍历左
	if (l < end)fastsort( l, end);//遍历右
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	fastsort(1, n);
	for (int i = 1; i <= n; ++i)
		{
			cout << a[i];
			if (i == n)cout << endl;
			else cout << " ";
		}
	return 0;
}
