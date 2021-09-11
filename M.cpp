#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("atm.inp","r",stdin);
    int t;
    cin>>t;
    while (t--){
        long long x11,x22,y11,y22;
        cin>>x11>>y11>>x22>>y22;
        if (x11>x22){
            swap(x11,x22);
            swap(y11,y22);
        }
        if (x11==x22){
            long long dis = abs(y11-y22);
            cout<<dis + (dis/2) * 2 <<'\n';
        }
        else if (y11==y22){
            long long dis = abs(x11-x22);
            cout<<dis + (dis/2) * 2 <<'\n';
        }
        else {
            long long temp = min(abs(x11-x22),abs(y11-y22));
            x11 = x11 + temp;
            if (y22>y11)
                y11 = y11 + temp;
            else y11 = y11 - temp;
            if (x11==x22){
                long long dis = abs(y11-y22);
                cout<<temp*2 + dis + (dis/2) * 2 <<'\n';
            }
            else if (y11==y22){
                long long dis = abs(x11-x22);
                cout<<temp*2 + dis + (dis/2) * 2 <<'\n';
            }
        }
    }
    return 0;
}
