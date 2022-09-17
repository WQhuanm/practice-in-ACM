#include<stdio.h>
#include<windows.h>
#include <algorithm>
#include<string.h>
using namespace std;
const int W=1e9;

struct rice
{
double p;//p为这种类型米的单价，h这种类型米的总重量
double h;
}arr[W];
bool cmp(rice x,rice y){
    return (x.p)<(y.p);
}
int main()
{
int C;
scanf("%d",&C);
while(C--)
{
int n,m;//n为总资金，m为大米种类
scanf("%d %d",&n,&m);

for(int i=0;i<m;++i){
scanf("%lf %lf",&arr[i].p,&arr[i].h);
}
sort(arr,arr+m,cmp);//按价格排序，小的在前
double sum=0;
for(int i=0;i<=m;++i){  //购买
if(n>=(arr[i].p)*(arr[i].h))
{
    sum+=arr[i].h;n-=(arr[i].p)*(arr[i].h);
}
else
{
    sum+=(n*1.0/(arr[i].p))*(arr[i].h);
    break;
}
}
printf("%.2lf\n",sum);

}


system("pause");
    return 0;
}




