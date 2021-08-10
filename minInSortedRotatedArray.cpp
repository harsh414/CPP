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
#define alldes(v) sort(v.begin(),v.end(),greater<ll int>())
#define endl '\n'
#define pb push_back

// Ex: 12 14 18 21 3 6 8 9
int main() {
    int n;
    cin>>n;
    int arr[n];
    fr(i,0,n-1) cin>>arr[i];
    int low=0, high=n-1;
    while(low<=high){
        int mid= (low+high)/2;
        int nxt= (mid+1)%n;
        int prev= (mid-1+n)%n;
        if(arr[low]<=arr[high]){
            cout<<low<<endl;
            break;
        }
        else if(arr[mid] <= arr[prev] && arr[mid]<=arr[nxt]){
            cout<<mid<<endl;
            break;
        }else if(arr[mid]>=arr[low]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
}