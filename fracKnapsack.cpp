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


bool comp(const pair<double,int> p1,const pair<double,int> p2)
{
    // if(p1.first<p2.first)
    return p1.first>p2.first;
}

int main()
{
    int n,w;
    cin>>n>>w;
    // p/w,w
    vector<pair<double,int>> v;
    fr(i,1,n)
    {
        int val,wght;
        cin>>val>>wght;
        double profit= val/(double)wght;
        v.pb({profit,wght});
    }
    
    sort(v.begin(),v.end(),comp);
    // cout<<v[0].first<<" "<<v[1].first<<" "<<v[2].first<<endl;
    double ans=0;
    int wg=w;
    for(auto p: v)
    {
        if(wg==0)
        break;
        double pro= p.first;
        int wght=p.second;
        if(wght<=wg)
        {
            ans+=(wght*pro);
            wg=wg-wght;
        }else{
            ans+=(wg*pro);
            break;
        }
    }
    printf("%0.4f",ans);
}