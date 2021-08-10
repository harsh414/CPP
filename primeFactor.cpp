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
#define maxN 100001
int spf[maxN];
// spf is smallest prime factor
void sieve()
{
    spf[1]=1;

    fr(i,1,maxN-1)
    spf[i]=i;
    for(int i=4;i<maxN;i+=2)
    {
        spf[i]=2;
    }

    for(int i=3;i*i<maxN;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<maxN;j+=i)
            {
                if(spf[i]==i)
                spf[j]=i;
            }
        }
    }
}

vector<int> getfactorisation(int x)
{
    vector<int> res;
    while(x!=1)
    {
        res.pb(spf[x]);
        x=x/spf[x];
    }
    return res;

}

int main()
{
    sieve();
    int n;
    cin>>n;
    vector<int> v= getfactorisation(n);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;

    
}