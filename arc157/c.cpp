#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
int H, W;
string S[2000];

mint dp[2000][2000], d[2000][2000], c[2000][2000] = {1};

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; ++i) cin >> S[i];

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            if (i) {
                c[i][j] += c[i - 1][j];
                dp[i][j] += dp[i - 1][j];
                d[i][j] += d[i - 1][j];
                if (S[i][j] == 'Y' && S[i - 1][j] == 'Y') {
                    dp[i][j] += c[i - 1][j] + d[i - 1][j];
                    d[i][j] += 2 * c[i - 1][j];
                }
            }
            if (j) {
                c[i][j] += c[i][j - 1];
                dp[i][j] += dp[i][j - 1];
                d[i][j] += d[i][j - 1];
                if (S[i][j] == 'Y' && S[i][j - 1] == 'Y') {
                    dp[i][j] += c[i][j - 1] + d[i][j - 1];
                    d[i][j] += 2 * c[i][j - 1];
                }
            }
        }
    cout << dp[H - 1][W - 1] << '\n';
}
