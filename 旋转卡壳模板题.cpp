/*
Blowing Candles
网址：https://cn.vjudge.net/contest/249102#problem/K
题目大意：圆形蛋糕上有几根蜡烛，问，说灭所有蜡烛的最小宽度为多少？
题解：所有蜡烛看做一个点，然后可以构成一个凸包，求旋转卡壳，最小宽度就是所有最长距离的最小值。
*/
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
struct point
{
    ll x,y;
}po[200015],index;
ll stack[200015],top;
  
ll cross(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
  
double dis(point p1,point p2)
{
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
  
bool cmp(point p1,point p2)
{
    ll tmp=cross(po[0],p1,p2);
    if(tmp>0)
        return true;
    else if(tmp==0&&dis(po[0],p1)<dis(po[0],p2))
        return true;
    else
        return false;
}
  
void init(int n)
{
    int i,k;
    point p0;
    scanf("%lld%lld",&po[0].x,&po[0].y);
    p0.x=po[0].x;
    p0.y=po[0].y;
    k=0;
    for(i=1;i<n;i++)
    {
        scanf("%lld%lld",&po[i].x,&po[i].y);
        if( (p0.y>po[i].y) || ((p0.y==po[i].y)&&(p0.x>po[i].x)) )
        {
            p0.x=po[i].x;
            p0.y=po[i].y;
            k=i;
        }
    }
    po[k]=po[0];
    po[0]=p0;
    sort(po+1,po+n,cmp);
}
  
void graham(int n)
{
    int i;
    if(n==1)
    {
        top=0;
        stack[0]=0;
    }
    if(n==2)
    {
        top=1;
        stack[0]=0;
        stack[1]=1;
    }
    if(n>2)
    {
        for(i=0;i<=1;i++)
            stack[i]=i;
        top=1;
        for(i=2;i<n;i++)
        {
            while(top>0&&cross(po[stack[top-1]],po[stack[top]],po[i])<=0)
                top--;
            top++;
            stack[top]=i;
        }
    }
}
double judge(int i,int k){
    int j=(i+1)%(top+1);
    double a,b,c;
    a=dis(po[stack[i]],po[stack[j]]);
    b=dis(po[stack[i]],po[stack[k]]);
    c=dis(po[stack[k]],po[stack[j]]);
    double q=(a+b+c)/2.0;
  
    return (double)sqrt(q*(q-a)*(q-b)*(q-c))/a*2.0;
}
  
int main()
{
    int n,R;
    scanf("%d",&n);
    scanf("%d",&R);
    init(n);
    graham(n);
    int index=2;
    double minn=INF*1.0;
    if(top<=1){
        printf("0\n");
        return 0;
    }
    for(int i=0;i<=top;i++)
    {
        double a1=judge(i,(index)%(top+1));
        while(1){
            double a2=judge(i,(index+1)%(top+1));
            if(a1>a2||index>2*top){
                if(a1<minn)
                    minn=a1;
                break;
            }
            index++;
            a1=a2;
        }
        if(index>2*top)
            break;
    }
    printf("%lf\n",minn);
    return 0;
}
//
