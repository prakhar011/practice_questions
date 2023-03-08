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
#include <climits>
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

bool checkBounds(int x, int y)
{
    if (x < 0 || y < 0 || x > 7 || y > 7)
        return false;
    return true;
}

void init_directions(vp32 &directions)
{
    directions.pb({-1, 2});
    directions.pb({-2, 1});
    directions.pb({2, 1});
    directions.pb({1, 2});
    directions.pb({2, -1});
    directions.pb({1, -2});
    directions.pb({-1, -2});
    directions.pb({-2, -1});
}

void bfs(vv32 &visited, int x, int y, int destination_x, int destination_y, int &min_moves)
{
    vp32 directions;
    init_directions(directions);
    queue<pair<int, p32>> q;
    q.push({0, {x, y}});
    while (q.size() > 0)
    {
        auto curr = q.front();
        q.pop();
        int curr_x = curr.se.fi, curr_y = curr.se.se, curr_move = curr.fi;
        visited[curr_x][curr_y]=1;
        if (curr_x == destination_x && curr_y == destination_y)
        {
            min_moves = min(curr_move, min_moves);
            continue;
        }
        for (p32 next_direction : directions)
        {
            int disp_x = next_direction.fi, disp_y = next_direction.se;

            if(checkBounds(curr_x+disp_x,curr_y+disp_y)&& visited[curr_x+disp_x][curr_y+disp_y]==0){
                q.push({curr_move+1,{curr_x+disp_x,curr_y+disp_y}});
            }
        }
    }
}
void solve()
{
    string start, end;
    cin >> start >> end;
    int x1, y1, x2, y2;
    x1 = start[0] - 'a';
    y1 = int(start[1] - '0') - 1;
    x2 = end[0] - 'a';
    y2 = int(end[1] - '0') - 1;
    // cout << x1 << " " << y1 << ln << x2 << " " << y2 << ln;
    int min_moves = INT_MAX;
    vv32 visited(8, v32(8, 0));
    bfs(visited, x1, y1, x2, y2, min_moves);
    cout << min_moves << ln;
    // cout << "--------------" << ln;
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
