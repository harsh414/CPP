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
#define ll long long
#define all(v) sort(v.begin(),v.end())
#define alldes(v) sort(v.begin(),v.end(),greater<int>())
#define endl '\n'
vector<pair<ll,ll>> adj[200001];
#define INF 3e18
 
#define INF 3e18
int main() 
{ 
   ll n,m;
   cin>>n>>m;
   vector<pair<ll,ll>> v;
   fr(i,1,m)
   {
       ll a,b,w;
       cin>>a>>b>>w;
       adj[a].pb({b,w});
    //   adj[b].pb({a,w});
   }
   
   priority_queue<pair<ll ,ll> , vector<pair<ll,ll>>,
   greater<pair<ll int,ll int>>> pq;
   pq.push({0,1});
   vector<ll > dist(n+1,INF);
   dist[1]=0;
   while(!pq.empty())
   {
       ll  node= pq.top().S;
       ll  dis= pq.top().F;
       pq.pop();
       if(dis>dist[node])
       continue;
       for(pair<ll ,ll > edge:  adj[node])
       {
            if(dis+ edge.S < dist[edge.F])
            {
                dist[edge.F]=dis+edge.S;
                pq.push({dist[edge.F],edge.F});
            }
            
       }
       
   }
   fr(i,1,n)
   cout<<dist.at(i)<<" ";
}