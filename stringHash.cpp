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
#define all(v) v.begin(),v.end()
#define allD(v) v.begin(),v.end(),greater<int>()
#define endl '\n'

ll getHash(string s)
{
    ll val=0;
    ll pow=1;
    ll p=11;
    for(char ch: s)
    {
        val = (val+(ch-'a'+1)*pow)%mod;
        pow=(pow*p)%mod;
    }
    return val;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<getHash(s);
    }
}