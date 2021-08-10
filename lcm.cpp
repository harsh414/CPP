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

ll int gcd(ll int a,ll int b)
{
    if(b==0)
    return a;
    else 
    return gcd(b,a%b);
}

ll int lcm(ll int a ,ll int b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    ll int a,b;
    cin>>a>>b;
    ll int res = lcm(a,b);
    cout<<res<<endl;
}