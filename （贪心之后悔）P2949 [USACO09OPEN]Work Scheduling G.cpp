#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;


struct worke
{
	ll m,d;

} a[N];
bool cmp(worke x,worke y)
{
	return x.d<y.d;
}

int main()
{
	ll n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i].d>>a[i].m;
	sort(a+1,a+1+n,cmp);
	priority_queue<ll,vector<ll>,greater<ll>>q;
	ll ans=0;
	for(int i=1; i<=n; ++i)
		{
			if(a[i].d>(int)q.size())
				{
					q.push(a[i].m);
					ans+=a[i].m;
				}
			else
				{
					if(q.top()<a[i].m)
						{
							ans+=a[i].m-q.top();
							q.pop();
							q.push(a[i].m);
						}


				}

		}
	cout<<ans<<endl;


	return 0;
}

//先假设每一项工作都做，将各项工作按截止时间排序后入队；
//在判断第 i 项工作做与不做时，若其截至时间符合条件，则将其与队中报酬最小的元素比较，若第 i 项工作报酬较高（后悔），则 ans += a[i].p - q.top()。
//用优先队列（小根堆）来维护队首元素最小。
//当 a[i].d<=q.size() 可以这么理解从 0 开始到 a[i].d 这个时间段只能做 a[i].d 个任务，而若
//q.size()>=a[i].d 说明完成 q.size() 个任务时间大于等于 a[i].d 的时间，所以当第 i 个任务获利比较大的时候应该把最小的任务从优先级队列中换出。






