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
vector<pair<int,int>> adj[100001];

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	map<int,int> mp;
	int mx=0;
	fr(i,1,n){
		cin>>arr[i];
		mp[arr[i]]++;
	}
	for(auto it = mp.begin();it!=mp.end();it++){
		if(it->second > mx){
			mx= it->second;
		}
	}

	int i=1,j=1;
	int min_len= INT_MAX;
	map<int,int> cnt;
	while(i<=j && j<=n){
		cnt[arr[j]]++;
		if(cnt[arr[j]]==mx){
			while(i<=j && cnt[arr[j]]==mx){
				if(j-i+1 < min_len){
				min_len= min(min_len, (j-i+1));
				// cout<<min_len<<endl;
				}
				cnt[arr[i]]--;
				i++;
			}
		}
		j++;
	}
	cout<<min_len;
	
}