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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n; cin >> n;
    vector<int> s(n+1, 0), vec;
    rep(i, 1, n - 1) cin >> s[i];
    unordered_set<int> st;
    rep(i, 1, n) st.insert(i);
    dec(i, n - 1, 1)
    {
        int val = s[i] - s[i - 1];
        if(st.count(val)) st.erase(val);
        else vec.push_back(val);
    }
    if(vec.size() == 1)
    {
        int sm = 0;
        for(auto x : st) sm += x;
        if(sm == vec.front()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if(vec.empty() and st.size() == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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