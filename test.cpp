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
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string st;
        cin>>st;
        if(a<=0 && b>=0){
            cout<<(a+b)*n<<endl;
            continue;
        }
        stack<char> s1,s2;
        s1.push(st[0]);
        int ans=0;
        bool secondstack=false;
        for(int i=1;i<n;i++){
            char tp1= s1.top();
            char tp2= s2.top();
            if(secondstack==false){
                if(st[i]==tp1){
                    s1.push(st[i]);
                }else{
                    secondstack=true;
                    s2.push(st[i]);
                }
            }else{
                if(st[i]==tp2){
                    s2.push(st[i]);
                }else{
                    ans+=(a*(s2.size()) + b);
                    s2.empty();
                    secondstack=false;
                    s1.push(st[i]);
                }
            }
        }
        ans+=(s1.size() * a +b);
        cout<<ans<<endl;
    }

}