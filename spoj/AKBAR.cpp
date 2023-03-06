#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
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

bool BFS(int s, vv32 &graph, v32 &Protected, int S, vector<bool> &visited)
{
    Protected[s]++;
    if (Protected[s] > 1)
    {
        return false;
    }
    queue<pair<int, int>> q;
    visited[s] = true;
    q.push({s, S});
    while (!q.empty())
    {
        int node = q.front().first;
        int strength_left = q.front().second;
        q.pop();
        if (strength_left <= 0)
        {
            continue;
        }
        for (auto ad : graph[node])
        {
            if (visited[ad] == false)
            {
                Protected[ad]++;
                q.push({ad, strength_left - 1});
                visited[ad] = true;
            }
        }
    }
    return true;
}

void solve()
{
    int n, r, m;
    cin >> n >> r >> m;
    vv32 graph(n + 1);
    v32 Protected(n + 1, 0);
    vector<bool> visited(n + 1, false);
    forn(i, r)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    v32 strength(n + 1, -1);
    forn(i, m)
    {
        int id, s;
        cin >> id >> s;
        strength[id] = s;
    }
    bool flag = true;
    forsn(i, 1, n + 1)
    {
        if (strength[i] >= 0)
        {
            flag = BFS(i, graph, Protected, strength[i], visited);
            if (!flag)
            {
                break;
            }
        }
    }

    if (!flag)
    {
        cout << "No\n";
        return;
    }
    else
    {
        forsn(i, 1, n + 1)
        {
            if (visited[i] == false)
            {
                cout << "No\n";
                break;
            }
        }
    }

    cout << "Yes\n";

    return;
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
