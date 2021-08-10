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
    int n;
    cin>>n;
    vector<int> v;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a; sum+=a; v.pb(a);
    }
    bool dp[n][sum+1];
    sort(v.begin(),v.end());
    
    for(int i=0;i<=sum;i++)
        dp[0][i]= false;
    dp[0][v[0]]=true;
    
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<v[i])
                dp[i][j]=dp[i-1][j];
            else if(dp[i-1][j]==true)
                dp[i][j]=true;
            else
            {
                if(dp[i-1][j-v[i]]==true)
                    dp[i][j]=true;
                else
                    dp[i][j]=false;
            }
        }
    }

    fr(i,0,n-1)
    {
        fr(j,0,sum)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    int half=sum/2;
    if(dp[n-1][half]==true)
    cout<<"Can be partitioned into two equal halves";
    else
    {
        cout<<"Cannot be partitioned into two equal halves";
    }
    
    
    
}