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
// size[i]=rank[i]= number of elemets in a particular disjoint set
// uses NlogN//

vector<pair<int,pair<int,int>> > v;
vector<pair<int,int>> ans;

int par[100001],size[100001];

int find(int a)
{
    if(par[a]<0)
    return a;

    int x= find(par[a]);
    par[a]=x;
    return x;
}

void merge(int a, int b)
{
    if(size[a]<size[b])
    {
        par[a]=b;
        size[b]+=size[a];
    }
    else
    {
        par[b]=par[a];
        size[a]+=size[b];
    } 
}

int main()
{
    int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		par[i]=-1;
        size[i]=i;
	}

    fr(i,1,m)
    {
        int src,des,wght;
        cin>>src>>des>>wght;
        if(src>des)
        swap(src,des);
        v.pb({wght,{src,des}});
    }

    sort(v.begin(),v.end());
    int count=0,weight=0;
    fr(i,0,m-1)
    {
        int x= v[i].second.first;
        int y=v[i].second.second;
        int w= v[i].first;
        int u= find(x);
        int v= find(y);
        if(u==v)
        continue;
        else
        {
            merge(u,v);
            ans.push_back({x,y});
            weight=weight+w;
            count++;
        }
        if(count==n-1)
        break;
    }

    cout<<"Weight is "<<weight<<endl;
    for(auto p: ans)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }




}