#include<bits/stdc++.h>
#include <ctype.h>
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

void swapp(int *px, int *py){
    int temp = *px;
    *px= *py;
    *py=temp;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    // bubble sort
    for(int i=1;i<n;i++){
        int key= arr[i];
        int j=i-1;
        
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
}