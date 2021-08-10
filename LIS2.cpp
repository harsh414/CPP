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
 
// STRICTLY INCREASING LIS
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    fr(i,0,n-1)
    cin>>arr[i];
    vector<ll> v;
    v.pb(arr[0]);
    fr(i,1,n-1)
    {
        if(arr[i]>v[v.size()-1])
        v.pb(arr[i]);
        else
        {
            auto it = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
            v[it]=arr[i];
        }
    }
    cout<< v.size();
}