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
//  TOPOLOGICAL SORT using DFS

// we have to print the vertices in such a way that if there is a edge from u->v then u comes first before v
// IDEA: make a dfs call and push the node at the end in the stack;
// and repeat the same
vec adj[1001];
vec ans;
int var[1001];
bool vis[1001];
int c=1;
int n,m;
 stack<int> s;
void dfs(int node)
{
   
    vis[node]=true;
    for(int child: adj[node])
    {
        if(!vis[child])
        dfs(child);
    }

    s.push(node);
}
int main()
{
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    fr(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    dfs(1);
    while(!s.empty())
    {
        int tp=s.top();
        cout<<tp<<" ";
        s.pop();
    }
}