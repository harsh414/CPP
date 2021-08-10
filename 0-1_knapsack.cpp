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


 
int main()
{
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    fr(i,0,n-1) cin>>wt[i];
    fr(i,0,n-1) cin>>val[i];
    int dp[n][w+1];
    for(int i=0;i<n;i++)
    dp[i][0]=0;
    for(int j=1;j<=w;j++)
    {
        if(j<wt[0])
        dp[0][j]=0;
        else 
        dp[0][j]=wt[0];
    }

    cout<<wt[1]<<endl;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(j<wt[i])
            dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=max(val[i]+ dp[i-1][j-wt[i]] , dp[i-1][j]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    // cout<<dp[n-1][w]<<endl;
}