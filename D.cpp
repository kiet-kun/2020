#include<bits/stdc++.h>
using namespace std;

const int N=3e5+3;
int n;
struct box_edge{
    long long w;
    int vt;
};
vector <box_edge> a[N];
long long deep[N];
int f[N][3];
// f[i][id] means the vertex (i is that vertex's parent)
// makes the the longest (id+1)th path.
long long d[N][3];
// d[i][id] means the longest (id+1)th path from i to leaf node in
// subtree which i is root.
int f_child[N][2];
long long d_child[N][2];
long long res;

void init(){
    res = 1e18;
    for (int i=1;i<=n;i++) {
        a[i].clear();
        deep[i] = 0;
        f[i][0]=f[i][1]=f[i][2]=0;
        d[i][0]=d[i][1]=d[i][2]=0;
        f_child[i][0]=f_child[i][1]=0;
        d_child[i][0]=d_child[i][1]=0;
    }
}

void input(){
    for (int i=1;i<n;i++){
        box_edge x;
        cin>>x.vt;
        cin>>x.w;
        a[i+1].push_back(x);
        int temp = x.vt;
        x.vt = i+1;
        a[temp].push_back(x);
    }
}
// use way like find out 1st,2nd value in array a
// in O(N).
void dfs_build(int u,int p){
    for (box_edge x : a[u]){
        int v = x.vt;
        long long uv = x.w;
        if (v!=p){
            dfs_build(v,u);
            deep[u] = max(deep[u],deep[v]+uv);
        }
    }
    // calculate for 1st path
    for (box_edge x : a[u]){
        int v = x.vt;
        long long uv = x.w;
        if (v!=p){
            if (d[u][0]<deep[v]+uv){
                f[u][0] = v;
                d[u][0] = deep[v] + uv;
            }
        }
    }
     // calculate for 2nd path
    for (box_edge x : a[u]){
        int v = x.vt;
        long long uv = x.w;
        if (v!=p){
            if (v!=f[u][0] && d[u][1]<deep[v]+uv){
                f[u][1] = v;
                d[u][1] = deep[v] + uv;
            }
        }
    }
    // calculate for 3rd path
    for (box_edge x : a[u]){
        int v = x.vt;
        long long uv = x.w;
        if (v!=p){
            if (v!=f[u][0] && v!=f[u][1] && d[u][2]<deep[v]+uv){
                f[u][2] = v;
                d[u][2] = deep[v] + uv;
            }
        }
    }
    for (box_edge x : a[u]){
        int v = x.vt;
        long long uv = x.w;
        if (v!=p){
            long long temp = d_child[v][0];
            temp = max(temp,d[v][0]+d[v][1]);
            if (d_child[u][0]<temp){
                f_child[u][0] = v;
                d_child[u][0] = temp;
            }
        }
    }
    for (box_edge x : a[u]){
        int v = x.vt;
        long long uv = x.w;
        if (v!=p){
            long long temp = d_child[v][0];
            temp = max(temp,d[v][0]+d[v][1]);
            if (v!=f_child[u][0] && d_child[u][1]<temp){
                f_child[u][1] = v;
                d_child[u][1] = temp;
            }
        }
    }
}

// cur_d means current diameter
void dfs_solve(int u,int p,long long half,long long cur_d){

    for (box_edge x : a[u]){
        int v = x.vt;
        int uv = x.w;
        long long cur_d_new = cur_d;
        long long half_new = half;
        if (v!=p){

            if (v==f[u][0]) {
                cur_d_new = max(cur_d_new,d[u][1]+d[u][2]);
                cur_d_new = max(cur_d_new,half + d[u][1]);
                half_new = max(half_new, d[u][1]);
            }
            else  if (v==f[u][1]) {
                cur_d_new = max(cur_d_new,d[u][0]+d[u][2]);
                cur_d_new = max(cur_d_new,half + d[u][0]);
                half_new = max(half_new, d[u][0]);
            }
            else  {
                cur_d_new = max(cur_d_new,d[u][0]+d[u][1]);
                cur_d_new = max(cur_d_new,half + d[u][0]);
                half_new = max(half_new, d[u][0]);
            }

            if (v==f_child[u][0]) cur_d_new = max(cur_d_new,d_child[u][1]);
            else cur_d_new = max(cur_d_new,d_child[u][0]);

            long long temp = d_child[v][0];
            temp = max(temp,d[v][0]+d[v][1]);
            res = min(res,abs(temp - cur_d_new));
           // cout<<u<<" "<<v<<" "<<temp<<" "<<cur_d_new<<endl;
            dfs_solve(v,u,half_new+uv,cur_d_new);
        }
    }
}

void solve(){
    dfs_build(1,0);
    /*for (int i=1;i<=n;i++){
        cout<<i<<endl;
        cout<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<endl;
        cout<<d[i][0]<<" "<<d[i][1]<<" "<<d[i][2]<<endl;
        cout<<f_child[i][0]<<" "<<f_child[i][1]<<endl;
        cout<<d_child[i][0]<<" "<<d_child[i][1]<<endl;
        cout<<"===================\n";
    }*/
    dfs_solve(1,0,0,0);
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("atm.inp","r",stdin);
    while (1){
        cin>>n;
        if (n==0) break;
        init();
        input();
        solve();
    }
    return 0;
}
