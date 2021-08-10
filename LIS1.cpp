#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<pair<int,int>> adj[100001];

// NOT STRICTLY INCREASING SUBSEQUENCE
int main() {
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }

   vector<int> dp;
   dp.push_back(arr[0]);

   for(int i=1;i<n;i++) {
      auto it = upper_bound(dp.begin(),dp.end(),arr[i]);
      int idx= it-dp.begin();
      if(it==dp.end()){
         dp.push_back(arr[i]);
      }else if(dp[idx-1]>arr[i]){
         dp[idx]=arr[i];
      }
   }
   cout<<dp.size();

}