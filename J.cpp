#include<bits/stdc++.h>
using namespace std;

int n,k;
long long a[20],b[20],l[20],r[20],res=0;

void trau(int id,int k){
    if (id==n+1){
        long long cnt = 0;
        for (int i=1;i<=n;i++)
            l[i]=max(l[i-1],a[i]+b[i]);
        for (int i=n;i>=1;i--)
            r[i]=max(r[i+1],a[i]+b[i]);
        for (int i=1;i<=n;i++){
            long long temp = min(l[i-1],r[i+1])-a[i]-b[i];
            if (temp>0)
                cnt = cnt + temp;
        }
        res = max(res,cnt);
        return;
    }
    for (int i=0;i<=k;i++){
        b[id] = i;
        trau(id+1,k-i);
    }
}

int main(){
   // freopen("atm.inp","r",stdin);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    trau(1,k);
    cout<<res;
    return 0;
}
