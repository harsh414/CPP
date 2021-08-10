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


int partition(int *arr,int start,int end)
{
    int pivot= arr[end];
    int pidx=start;
    for(int i=start;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[pidx],arr[i]);
            pidx++;
        }
    }
    swap(arr[pidx],arr[end]);
    return pidx;
}

void quickSort(int *arr,int start,int end)
{
    if(end<start)
    return;

    int pi= partition(arr,start,end);
    quickSort(arr,start,pi-1);
    quickSort(arr,pi+1,end);
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    fr(i,0,n-1) cin>>arr[i];
    quickSort(arr,0,n-1);

    fr(i,0,n-1) cout<<arr[i]<<" ";
}