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
#define all(v) sort(v.begin(),v.end())
#define alldes(v) sort(v.begin(),v.end(),greater<int>())
#define endl '\n'


 
int main()
{
    string s,t;
	cin>>s>>t;
	int n1=s.size();
	int n2=t.size();
	int dp[n1+1][n2+1];
	// fr(i,0,n2)
	// dp[0][i]=0;
	// fr(i,0,n1) dp[i][0]=0;

	fr(i,0,n1)
	{
		fr(j,0,n2)
		{
			if(i==0 or j==0)
			dp[i][j]=0;
			else if(s[i-1]==t[j-1])
			dp[i][j]=dp[i-1][j-1]+1;
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	// print lcs
	string ans="";
	int row=n1,col=n2;
	while(row>0 && col>0)
	{
		if(s[row-1]==t[col-1]){
				ans+=s[row-1];row--;col--;
		}else if(dp[row-1][col]>=dp[row][col-1]){
				row--;
		}
		else{
			col--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}