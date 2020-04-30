#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define pb push_back
#define F first
#define S second
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vl vector<ll>
#define all(v) v.begin(),v.end()
#define mst(a,b) memset(a,b,sizeof(a));
#define pii pair<ll,ll>
using namespace std;
const int mod=998244353;
const int N=1e5+5,lg=20;
vi v[N];
int depth[N],n,parent[N][lg];
void dfs(int s, int p){
    if(s!=0)depth[s]=depth[p]+1;
    parent[s][0]=p;
    for(int i=0;i<v[s].size();i++){
        if(v[s][i]==p) continue;
        dfs(v[s][i],s);
    }
}
int lca(int u, int v){
    if(depth[u]<depth[v]) {int t=u;u=v;v=t;}
    int d=depth[u]-depth[v];
    for(int i=19;i>=0;i--){
        if(d>=(1<<i)){
            d=d-(1<<i);
            u=parent[u][i];
        }
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(depth[u]>=(1<<i)){
            int w=parent[u][i];
            int x=parent[v][i];
            if(w==x) continue;
            u=w;
            v=x;
        }
    }
    return parent[u][0];
}
void solve(){
    mst(parent,-1);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int j;
        cin>>j;
        v[j].pb(i);
        v[i].pb(j);
    }
    depth[0]=0;
    dfs(0,-1);
    for(int i=0;i<n;i++){
        for(int j=1;j<20;j++){
            if(parent[i][j-1]==-1) break;
            parent[i][j]=parent[parent[i][j-1]][j-1];
        }
    }
    int m,j,k;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>j;
        if(m==1){cout<<j<<endl;return;}
        if(i==0) {k=j;continue;}
        k=lca(k,j);
    }
    cout<<k<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,p;
    //cin>>t;
    t=1;
    for(p=0;p<t;p++){
        solve();
    }
}
