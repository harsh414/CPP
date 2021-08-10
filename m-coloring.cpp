#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
#define F first
#define S second
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fr(i,a,b) for(ll int i=a;i<=b;i++)
#define mod 1000000007
#define INF 1000000000
#define ll long long
#define endl '\n'

 int main()
 {
    int n,m;
    cin>>n>>m;
    vector<int> adj[1000];
    fr(i,1,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);adj[b].pb(a);
    }
    int maxColor=1;
    int color[n+1];
    fr(i,0,n) color[i]=1;
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    vis[1]=1;
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty())
    {
        int tp=q.front();
        q.pop();
        for(auto child : adj[tp])
        {
            if(color[child]==color[tp])
            color[child]++;

            maxColor=max(maxColor,max(color[child],color[tp]));
           

            if(!vis[child])
            {vis[child]=true; q.push(child);}
        }
    }

    cout<<maxColor;


 }
