#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
#define F first
#define S second
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define INF 1000000000
#define ll long long
#define endl '\n'
vec adj[1001];
int in[1001],low[1001],vis[1001];
int timer=1;

vector<pair<int,int>> bridges;

void dfs(int node,int par)
{
    vis[node]=true;
    in[node]=timer;
    low[node]=timer;
    timer++;

    for(int child: adj[node])
    {
        if(child==par)
        continue;

        
        if(vis[child])
        {
            // back edge presence
            low[node]=min(low[node],in[child]);
        }
        else
        {
            // forward edge/
            dfs(child,node);

            if(low[child]>in[node])
            bridges.pb({node,child});

            low[node]=min(low[node],low[child]);
        }
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    fr(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1);
    cout<<"total"<<" "<<bridges.size()<<" "<<"bridges"<<endl;
    for(auto p: bridges)
    {
        cout<<p.first<<"-"<<p.second<<" is a bridge"<<endl;
    }
}