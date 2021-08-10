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
// KAHNS TOPOLOGICAL SORT

// we have to print the vertices in such a way that if there is a edge from u->v then u comes first before v
// IDEA: Take node with indegree 0 print it and remove corres. edges
// and repeat the same
vec adj[1001];
vec ans;
int in[1001];

void kahn(int n)
{
    queue<int> q;
    fr(i,1,n)
    if(in[i]==0)
    q.push(i);

    while(!q.empty())
    {
        int tp=q.front();
        ans.pb(tp);
        q.pop();
        for(int child: adj[tp])
        {
            in[child]-=1;
            if(in[child]==0)
            q.push(child);
        }
    }

    for(int val:ans)
    cout<<val<<" ";
}
int main()
{
    int n,m;
    cin>>n>>m;
    fr(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        in[y]++;
    }
    kahn(n);
}