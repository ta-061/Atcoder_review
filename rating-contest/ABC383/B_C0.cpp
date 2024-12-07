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
int  H, W, D;
set<pii> bfs(int sx, int sy, const vs &S) {
    queue<pair<pii, int>> q;
    set<pii> hum;
    q.push({{sx, sy}, 0});
    while (!q.empty()) {
        auto [cell, dist]=q.front();
        q.pop();
        int x=cell.first, y=cell.second;
        if (x<0||x>=H||y<0||y>=W||S[x][y]== '#'||dist>D) continue;
        hum.insert(cell);
        q.push({{x + 1, y}, dist + 1});
        q.push({{x - 1, y}, dist + 1});
        q.push({{x, y + 1}, dist + 1});
        q.push({{x, y - 1}, dist + 1});
    }
    return hum;
}

int main() {
    cin >> H >> W >> D;
    vs S(H);
    rep(i, H) cin >> S[i];
    vector<pii> floor;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '.') {
                floor.emplace_back(i, j);
            }
        }
    }
    int ans=0;
    rep(i,floor.size()){
        rep(j,i+1,floor.size()){
            auto [x1,y1]=floor[i];
            auto [x2,y2]=floor[j];
            set<pii> hum1=bfs(x1,y1,S);
            set<pii> hum2=bfs(x2,y2,S);
            set<pii>com=hum1;
            com.insert(all(hum2));
            ans=max(ans,(int)com.size());
        }
    }
    cout << ans << endl;
}
