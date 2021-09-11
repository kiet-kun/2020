#include<bits/stdc++.h>
using namespace std;

const int N=55;
int n;
struct point{
    int x,y;
}p[N];

void input(){
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>p[i].x>>p[i].y;
}

long long ccw(point a,point b,point c){
    point ab = {b.x-a.x,b.y-a.y};
    point bc = {c.x-b.x,c.y-b.y};
    return ab.x*bc.y - ab.y*bc.x;
}

// d in triangle(abc) ?
// abs(ccw(a,b,c)) = 2 * area of triangle(abc)
bool check_in(point a,point b,point c,point d){
    long long d0 = abs(ccw(a,b,c));
    long long d1 = abs(ccw(a,b,d));
    long long d2 = abs(ccw(a,c,d));
    long long d3 = abs(ccw(b,c,d));
    return (d0==d1+d2+d3);
}

bool check(point a,point b,point c,point d){
    if (check_in(a,b,c,d)==1) return 0;
    if (check_in(a,b,d,c)==1) return 0;
    if (check_in(a,d,c,b)==1) return 0;
    if (check_in(d,b,c,a)==1) return 0;
    return 1;
}

void solve(){
    long long res = 0;
    for (int i1=1;i1<=n-3;i1++)
    for (int i2=i1+1;i2<=n-2;i2++)
    for (int i3=i2+1;i3<=n-1;i3++)
    for (int i4=i3+1;i4<=n;i4++)
        res = res + check(p[i1],p[i2],p[i3],p[i4]);
    cout<<res<<'\n';
}

int main(){
    //freopen("atm.inp","r",stdin);
    while (1){
        input();
        if (n==0) break;
        solve();
    }
    return 0;
}
