#include<bits/stdc++.h>
using namespace std;

// detect ccyle using dsu (with path compression)
int par[100001];

int find(int a)
{
    if(par[a]<0)
    return a;
    int x=find(par[a]);
    par[a]=x;
    return x;
}

void unionn(int u,int v)
{
    par[v]=u;
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
		{cout<<"cycle found";break;}
		else
		unionn(u,v);
	}
}