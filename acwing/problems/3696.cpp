#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1];
    vector<pii> edges;
    vector<int> deg(n+1, 0);
    rep(i, 1, m)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if(t) g[x].push_back(y), deg[y] ++;
        else edges.push_back({x, y});
    }
    vector<int> ans;
    function<void(void)> topsort = [&](){
        queue<int> q;
        rep(i, 1, n) if(!deg[i]) q.push(i);
        while(q.size())
        {
            int ver = q.front();
            q.pop();
            ans.push_back(ver);
            for(auto v:g[ver])
            {
                deg[v] --;
                if(!deg[v]) q.push(v);
            }
        }
    };
    topsort();
    if(ans.size() != n)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    map<int, int> mp;
    rep(i, 0, SZ(ans)-1) mp[ans[i]] = i;
    for(auto p:edges)
    {
        if(mp[p.first] > mp[p.second]) swap(p.first, p.second);
        cout << p.first << ' ' << p.second << endl;
    }
    rep(i, 1, n)
        for(auto v:g[i]) cout << i << ' ' << v << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}