#include<bits/stdc++.h>
using namespace std;

int par[100001];

int find(int a)
{
	if(par[a]<0)
    return a;

    // path compression in dsu
     int x= find(par[a]);
     par[a]=x;
     return x;
}

void unionn(int u,int v)
{
    par[u]=par[u]+par[v];
	par[v]=u;
}


int modN(int a,int b)
{
	return ((a%1000000007)*(b%1000000007))%1000000007;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		par[i]=-1;
	}

	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		int u=find(x);
		int v=find(y);
		if(u==v)
		continue;
		else
		unionn(u,v);
	}
    int ans=1;

    for(int i=1;i<=n;i++)
    {
        if(par[i]<0)
        ans=modN(ans,abs(par[i]));
    }

    cout<<ans<<endl;
}