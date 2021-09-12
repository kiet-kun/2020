#include<bits/stdc++.h>
using namespace std;

const int N=1e5+3;
int n,w[N],d;
string s[N];
long long f[27][52];

void init(){
    memset(f,0,sizeof(f));
}

void input(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>w[i];
    cin>>d;
    for (int i=1;i<=d;i++) cin>>s[i];
}

void solve(){
    long long res = 0;
    for (int i=1;i<=d;i++){
        int id = s[i][0] - 'a';
        //cout<<id<<" "<<s[i][]
        f[id][s[i].size()]++;
    }
    for (int i=1;i<=d;i++){
        int id = s[i][0] - 'a';
        f[id][s[i].size()]--;
        if (s[i].size()==n){
            long long temp = 1;
            for (int j=0;j<s[i].size();j++){
                 int id = s[i][j] - 'a';
                 temp = temp * f[id][w[j+1]];
                 f[id][w[j+1]]--;
            }
            for (int j=0;j<s[i].size();j++){
                 int id = s[i][j] - 'a';
                 f[id][w[j+1]]++;
            }
            res = res + temp;
        }
        f[id][s[i].size()]++;
    }
    cout<<res<<'\n';
}

int main(){
    //freopen("atm.inp","r",stdin);
    int t;
    cin>>t;
    while (t--){
        init();
        input();
        solve();
    }
    return 0;
}
