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

pair<int, bool> findtree(map<int, vi>& map_v, vi& V, int now, set<int>& visited) {
    if (V.empty()) return {1, false};
    visited.insert(now);
    int ans = 1;
    bool flag=false;
    for (int next : map_v[now]) {
        if (visited.count(next) == 0) {
            auto it = find(V.begin(), V.end(), next);
            if (it != V.end()) {
                V.erase(it);
                flag=true;
            }
            cout << now<<"前 "<<next<<" "<<ans << endl;
            auto result = findtree(map_v, V, next, visited);
            if(result.second)flag=true;
            if(flag)ans+=result.first;
            cout << now<<"後 "<<next<<" "<<ans << endl<<endl;
        }
    }
    return {ans,flag};
}




int main() {
    int N, K;
    cin >>N >> K;
    vi V(K);
    map<int, vi> map_v;
    int A,B;
    rep(i,N-1){
        cin >> A >> B;
        map_v[A].push_back(B);
        map_v[B].push_back(A);
    }
    for (int i = 0; i < K; i++) {
        cin >> V[i];
    }
    int now=V[0];
    V.erase(V.begin());
    set<int> visited;
    auto ans = findtree(map_v, V,now,visited);
    if(ans.first==0)ans.first++;
    
    cout << ans.first;
}