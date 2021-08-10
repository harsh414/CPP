#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
#define F first
#define S second
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define INF 1000000000
#define ll long long
#define endl '\n'
// subset hash value computation optimized  way O(1)

ll int dp[1000001],modInv[1000001];

// for substring :  (dp[R]-dp[L-1])/p^L;   so compute p^L multiplicative inverse/

ll int power(ll int a, ll int b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        // res=(res*a)%mod;
        res= (res%mod * a%mod )%mod;
        // a=(a*a)%mod;
        a= (a%mod * a%mod)%mod;
        b>>=1;
    }
    return res;
}

void init(string s)
{
    ll int pow=1;
    ll int p=31;
    dp[0]=(s[0]-'a'+1);
    modInv[0]=1;
    for(int i=1;i<s.size();i++)
    {
        pow=(pow*p)%mod;
        modInv[i]= power(pow,mod-2);
        dp[i]= (dp[i-1]+ (s[i]-'a'+1)*pow)%mod;
    }
}

ll substr(int l,int r)
{
    ll int res= dp[r];
    if(l>0) res = res-dp[l-1];
    res=(res*modInv[l])%mod;
    return res;
}

int main()
{
    string s;
    cin>>s;
    init(s);
    int t=10;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<substr(l,r)<<endl;
        // cout<<modInv[0]<<" "<<modInv[1]<<" "<<modInv[2]<<" "<<modInv[3];

    }
}

// below is the IMPROVED technique of string matching
// hash("coding")= c.p^0 + o.p^1 +......+ g.p^5
// hash("din") is =( d.p^2 +i.p^3+n.p^4)/p^2;

// this could be written as hash("din")*p^2=(d.p^2 +i.p^3+n.p^4)
// This is Rabin karp string matching algorithm

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef vector<int> vec;
// #define F first
// #define S second
// #define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// #define pb push_back
// #define fr(i,a,b) for(int i=a;i<=b;i++)
// #define mod 1000000007
// #define INF 1000000000
// #define ll long long
// #define endl '\n'
// // subset hash value computation optimized  way O(1)

// ll int dp[1000001],modInv[1000001];

// // for substring :  (dp[R]-dp[L-1])/p^L;   so compute p^L multiplicative inverse/

// ll int power(ll int a, ll int b)
// {
//     ll res=1;
//     while(b)
//     {
//         if(b&1)
//         // res=(res*a)%mod;
//         res= (res%mod * a%mod )%mod;
//         // a=(a*a)%mod;
//         a= (a%mod * a%mod)%mod;
//         b>>=1;
//     }
//     return res;
// }

// void init(string s)
// {
//     ll int pow=1;
//     ll int p=31;
//     dp[0]=(s[0]-'a'+1);
//     // modInv[0]=1;
//     for(int i=1;i<s.size();i++)
//     {
//         pow=(pow*p)%mod;
//         // modInv[i]= power(pow,mod-2);
//         dp[i]= (dp[i-1]+ (s[i]-'a'+1)*pow)%mod;
//     }
// }

// ll substr(int l,int r)
// {
//     ll int res= dp[r];
//     if(l>0) res = (res-dp[l-1]+mod)%mod;
//     // res=(res*modInv[l])%mod;
//     return res;
// }
// ll getHash2(string s)
// {
//     ll val=0;
//     ll pow=1;
//     ll p=31;
//     for(char ch: s)
//     {
//         val = (val+(ch-'a'+1)*pow)%mod;
//         pow=(pow*p)%mod;
//     }
//     return val;
// }



// int main()
// {
//     string needle,haystack;
//     int n,L,R;
//     while(cin>>n)
//     {
//         cin>>needle;
//         cin>>haystack;
//         ll int hashVal = getHash2(needle);
//         init(haystack);
//         for(L=0,R=needle.size()-1;R<haystack.size() ; L++,R++)
//         {
//             if((hashVal * power(31,L))%mod == substr(L,R))
//             cout<<L<<endl;
//         }
//         cout<<endl;
//     }

// }