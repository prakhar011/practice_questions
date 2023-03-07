#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define all(x) x.begin(), x.end()
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)



void dfs(vv32 &graph,v32 &visited,v32 &ProtectedBy,int reach,int currCity,int origin){
    if(reach<=0) return;
    --reach;
    for(int nextCity:graph[currCity]){
        if(nextCity==origin) continue;
        if(!visited[nextCity])
            ProtectedBy[nextCity]++;
        visited[nextCity]=1;
        dfs(graph,visited,ProtectedBy,reach,nextCity,currCity);

    }
}

void solve()
{
    int n, r, m;
    cin>>n>>r>>m;
    vv32 graph(n);
    v32 visited(n,0);
    v32 ProtectedBy(n,0);
    forn(i,r){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    forn(i,m){
        int id,reach;
        cin>>id>>reach;
        id--;
        ProtectedBy[id]++;
        if(reach!=0){
            visited.assign(n,0);
            visited[id]=1;
            dfs(graph,visited,ProtectedBy,reach,id,id);
        }
    }
    forn(i,n){
        // cout<<i+1<<" "<<ProtectedBy[i]<<ln;
        if(ProtectedBy[i]>1 || ProtectedBy[i]==0){
            cout<<"No"<<ln;
            return;
        }
    }
    // cout<<"-----------------------------------"<<ln;
    cout<<"Yes"<<ln;
}
int main()
{
 #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
 #endif
 IOS;
 ll t;
 cin >> t;
 while (t--)
 {
   solve();
 }
 cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 return 0;
}
