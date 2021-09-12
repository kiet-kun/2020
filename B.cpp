#include<bits/stdc++.h>
using namespace std;

const int N=1e6+2;
int n,m,d[N];
string s[N];
struct box{
    int x,y,w;
};
int dx[]={0,0,-1,1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};

int get_id(int i,int j){
    return (i-1)*m+j;
}

void init(){
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) d[get_id(i,j)]=1e9;
}

void input(){
    for (int i=1;i<=n;i++){
        cin>>s[i];
        s[i] = " "+s[i];
    }
}

void bfs_01(){
    deque <box> dq;
    for (int i=2;i<=n;i++){
        if (s[i][1]!='@'){
            d[get_id(i,1)]=bool(s[i][1]=='.');
            dq.push_back({i,1,d[get_id(i,1)]});
        }
    }
    for (int i=2;i<=m;i++){
        if (s[n][i]!='@'){
            d[get_id(n,i)]=bool(s[n][i]=='.');
            dq.push_back({n,i,d[get_id(n,i)]});
        }
    }
    while (dq.size()){
        box u = dq.front();
        dq.pop_front();
        //cout<<u.x<<" "<<u.y<<" "<<u.w<<endl;
        for (int i=0;i<8;i++){
            int vx = u.x + dx[i];
            int vy = u.y + dy[i];
            if (vx>=1 && vx<=n && vy>=1 && vy<=m)
            if (s[vx][vy]!='@'){
                int uv = bool(s[vx][vy]=='.');
                if (d[get_id(vx,vy)]>u.w + uv){
                    d[get_id(vx,vy)] = u.w + uv;
                    if (uv==0) dq.push_front({vx,vy,d[get_id(vx,vy)]});
                    else dq.push_back({vx,vy,d[get_id(vx,vy)]});
                }
            }
        }
    }
}

void solve(){
    if (s[1][1]=='#' || s[n][m]=='#') {
        cout<<0<<'\n';
        return;
    }
    if (s[1][1]=='.' || s[n][m]=='.'){
        cout<<1<<'\n';
        return;
    }
    bfs_01();
    int res = 1e9;
    for (int i=2;i<=m;i++)
        res=min(res,d[get_id(1,i)]);
    for (int i=1;i<n;i++)
        res=min(res,d[get_id(i,m)]);
    if (res==1e9) res = -1;
    cout<<res<<'\n';
}

int main(){
    //freopen("atm.inp","r",stdin);
    while (1){
        cin>>n>>m;
        if (n==0 && m==0) break;
        init();
        input();
        solve();
    }
    return 0;
}
