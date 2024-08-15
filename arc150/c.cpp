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
int N, M, K, U, V, A[100000], B[100000];
vector<int> g[200000];
int level[100000];
deque<int> q;

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        cin >> U >> V, --U, --V;
        g[U].push_back(V);
        g[V].push_back(U);
    }
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < K; ++i) cin >> B[i];

    fill(level, level + N, -1);

    q.push_back(0);
    level[0] = B[0] == A[0];

    while (q.size()) {
        int x = q.front();
        q.pop_front();
        for (int y : g[x]) {
            if (level[y] >= 0) continue;
            if (level[y] < K && B[level[x]] == A[y]) {
                level[y] = level[x] + 1;
                q.push_back(y);
            } else {
                level[y] = level[x];
                q.push_front(y);
            }
        }
    }
    cout << (level[N - 1] == K ? "Yes\n" : "No\n");
}
