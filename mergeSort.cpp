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


void merge(int *arr, int l,int mid, int r){
    int n1= mid-l+1;
    int n2= r-mid;
    int L[n1]; int R[n2];
    for(int i=0;i<n1;i++){
      L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
      R[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
      if(L[i]<=R[j]){
        arr[k]=L[i];
        i++;
      }else{
        arr[k]=R[j];
        j++;
      }
      k++;
    }
  
    while(i<n1){
      arr[k]=L[i];
      i++;k++;
    }
    
    while(j<n2){
      arr[k]=R[j];
      j++;k++;
    }
}

void mergeSort(int *arr,int l,int r){
  if(l<r){
    int mid= (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
  }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    mergeSort(arr,0,n-1);
    fr(i,0,n-1){
      cout<<arr[i]<<" ";
    }
}