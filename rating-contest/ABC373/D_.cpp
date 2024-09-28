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
void che(ll s, vector<vector<pair<ll, ll>>>& uv, vll &ans, set<ll> &un){
    queue<ll> q;
    q.push(s);
    un.erase(s);
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        for (auto [v, w]:uv[now]){
            if (ans[v]==LONG_MIN){
                ans[v]=ans[now]+w;
                q.push(v);
                un.erase(v);
            }
        }
    }
}



int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<pair<ll, ll>>> uv(N);
    vll ans(N,LONG_MIN);
    set<ll> un;
    rep(i, M){
        int u, v, w;
        cin >> u >> v >> w;
        uv[u-1].emplace_back(v-1, w);
        uv[v-1].emplace_back(u-1, -w);
    }
    rep(i, N)un.insert(i);
    ll s=0;
    ans[0]=0;
    che(s, uv, ans, un);
    while(!un.empty()){
        ll s=*un.begin();
        if(ans[s]==LONG_MIN)ans[s]=0;
        che(s, uv, ans,un);
    }
    rep(i, N) cout << ans[i] << " ";
}