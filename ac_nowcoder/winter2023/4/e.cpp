#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <string>
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
int h[N], v[N];
void solve()
{
    int n, t, a;
    cin >> n >> t >> a;
    rep(i, 1, n) cin >> h[i] >> v[i];
    int ans = 1 - t;
    rep(i, 1, n)
    {
        if(h[i] <= a) ans += t;
        else
        {
            if(v[i] * t >= a)
            {
                ans = -1;
                break;
            }
            int times = (h[i] - a) / (a - v[i] * t) + 1;
            if((h[i] - a) % (a - v[i] * t)) times ++;
            ans += times * t;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}