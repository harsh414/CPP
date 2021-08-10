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
#define all(v) sort(v.begin(),v.end())
#define alldes(v) sort(v.begin(),v.end(),greater<int>())
#define endl '\n'
vector<int> adj[100001];
bool vis[100001];
int minn=INT_MAX;

int dfs(int node,vector<int> &sum,int *val){
	vis[node]=true;
	sum[node]=val[node];
	for(int child : adj[node]){
		if(!vis[child]){
			sum[node]+=dfs(child,sum,val);
		}
	}
	return sum[node];
}

void minimumDiff(int node , vector<int> &sum){
	vis[node]=true;
	for(int child: adj[node]){
		if(!vis[child]){
			if(abs(sum[child]-(sum[1]-sum[child]))< minn){
				minn= abs(sum[child]-(sum[1]-sum[child]));
			}
			minimumDiff(child,sum);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	fr(i,1,m){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int val[n+1];
	vector<int> sum(n+1,0);
	memset(vis,false,sizeof(vis));
	fr(i,1,n) cin>>val[i];
	dfs(1,sum,val);
	memset(vis,false,sizeof(vis));
	minimumDiff(1,sum);
	// fr(i,1,n) cout<<sum[i]<<" ";
	cout<<minn<<endl;
}