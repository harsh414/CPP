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
#define maxN 500
int res[maxN];


int multiply(int num, int res_size)
{
    int carry=0;
    for(int i=0; i<res_size;i++)
    {
        int pro= res[i]*num + carry;
        res[i]=pro%10;
        carry=pro/10;
    }

    while(carry)
    {
        res[res_size]=carry%10;
        carry/=10;
        res_size++;
    }

    return res_size;
}

void fact(int n)
{
    res[0]=1;
    int res_size=1;
    fr(i,2,n)
    {
        res_size = multiply(i,res_size);
    }

    for(int i=res_size-1;i>=0;i--)
    cout<<res[i];
}

int main()
{
    int n;
    cin>>n;
    fact(n);
}
