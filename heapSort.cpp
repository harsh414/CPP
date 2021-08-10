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

void heapify(int *arr,int n,int i)
{
    int largest=i;
    int l= 2*i+1;
    int r= 2*i+2;

    // check index i left and right childs
    if(l<n && arr[l]> arr[largest])
    largest=l;

    if(r<n && arr[r]>arr[largest])
    largest=r;

    if(largest!=i){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
    }
}

void heapSort(int *arr,int n)
{
    // heapify the child elements.,.LEAVES have no child ..so we start from n/2-1 /...leaves already form maxheap
    for(int i=(n/2)-1; i>=0;i--)
    {
        heapify(arr,n,i);
    }

    // deletion of all elements
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    fr(i,0,n-1) cin>>arr[i];
    heapSort(arr,n);

    fr(i,0,n-1) cout<<arr[i]<<" ";
}