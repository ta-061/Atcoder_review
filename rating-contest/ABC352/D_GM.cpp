#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)

#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

template<>
struct std::vector<bool>: std::basic_string<bool> {
    using std::basic_string<bool>::basic_string, std::basic_string<bool>::operator =;
    explicit vector(size_t n): vector(n, false) {}
};

//ラムダ記法
/*auto func = lambda($(0) * 3 + 1);*/
// 引数を取得するマクロ
#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))
// ラムダ式を短く書くマクロ
#define lambda(...) ([&](auto&&... _args) { return (__VA_ARGS__); })

//多次元vector生成関数
/*2×2×2で全要素が1のvectorを作成
  auto a = make_vec<int>({2, 2, 2}, 1);
  2×2×2で全要素が0のvectorを作成
  auto b = make_vec<int>({2, 2, 2});*/
template<class T, size_t n, size_t idx = 0>
auto make_vec(const size_t (&d)[n], const T& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vec<T, n, idx + 1>(d, init));
    else return init;
}
template<class T, size_t n>
auto make_vec(const size_t (&d)[n]) noexcept {
    return make_vec(d, T{});
}

//if (i == 3) break_with(cout << i << '\n');など
#define exit_with(...) ({ __VA_ARGS__; exit(0); })
#define break_with(...) ({ __VA_ARGS__; break; })
#define continue_with(...) ({ __VA_ARGS__; continue; })
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool chek(const vector<string>& grid, int H, int W, int r, int c){
    bool ans=false;
    for (const auto& [dr, dc] : directions) {
        int nr = r + dr;
        int nc = c + dc;
        if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] == '#') {
            ans=true;
        }
    }
    return ans;
}

int calculateFreedom(const vector<string>& grid, int H, int W, int sr, int sc, vector<vector<int>>& memo) {
    if (memo[sr][sc] != -1)return memo[sr][sc];

    if (chek(grid, H, W, sr, sc))return memo[sr][sc]=1;

    int freedom = 1;
    memo[sr][sc]=0;

    for (const auto& [dr, dc] : directions) {
        int nr = sr + dr;
        int nc = sc + dc;
        if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] == '.') {
            freedom += calculateFreedom(grid, H, W, nr, nc, memo);
        }
    }

    memo[sr][sc] = freedom;
    return freedom;
}

int main() { 
    int H, W;
    cin >> H >> W;
    vs S(H);
    rep (i,H) {
        cin >> S[i];
    }

    vector<vector<int>> memo(H, vector<int>(W, -1));

    int ans = 0;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='.'){
                int fre = calculateFreedom(S, H, W, i, j, memo);
                ans = max(ans, fre);
            }
        }
    }
    cout << ans;

    return 0;
}