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

pair<int,int> p;
int d[100001];

int getMinMoves(int moves[],int n)
{
      queue<pair<int,int> > q;
      bool vis[n+1];
      memset(vis,false,sizeof(vis));
      pair<int,int> strt= {0,0};
      vis[0]=true;
      d[0]=0;
      q.push(strt);

      while(!q.empty())
      {
         int vertex= q.front().first;
         int dist= q.front().second;
         q.pop();


         if(vertex==n)
         break;

         for(int j=vertex+1;j<=n && j<=vertex+6 ; j++)
         {
            if(!vis[j])
            {
                  vis[j]=true;
                  pair<int,int> vir;
                  vir.second=dist+1;
                  d[j]=vir.second;

                  if(moves[j]!=-1)
                  {
                     vir.first=moves[j];
                  }
                  else
                  {
                     vir.first=j;
                  }

                  q.push(vir);
            }
         }
      }

      return d[n];


}

int main()
{
   int n;
   cin>>n;
   int moves[n+1];
   fr(i,1,n)
   moves[i]=-1;

   // moves[3] = 22; 
   //  moves[5] = 8; 
   //  moves[11] = 26; 
   //  moves[20] = 29; 
  
   //  // Snakes 
   //  moves[27] = 1; 
   //  moves[21] = 9; 
   //  moves[17] = 4; 
   //  moves[19] = 7; 

   // moves denote goig from one position to other if a ladder is found or a snake head is found
    moves[1] = 38;
    moves[4] = 14;
    moves[9] = 31;
    moves[21] = 42;
    moves[28] = 84;
    moves[51] = 67;
    moves[72] = 91;
    moves[80] = 99;
 
    // insert snakes into the map
    moves[17] = 7;
    moves[54] = 34;
    moves[62] = 19;
    moves[64] = 60;
    moves[87] = 36;
    moves[93] = 73;
    moves[95] = 75;
    moves[98] = 79;

    cout<<getMinMoves(moves,n);
}