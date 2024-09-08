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


int main() {
    ll H, W, Q, R, C;
    cin >>H >> W >> Q;
    map<ll, set<ll>> r_map;
    map<ll, set<ll>> c_map;
    set<pair<ll,ll>> map;
    ll A,B;
    rep(i,Q){
        cin >> R >> C;
        pair<ll,ll>p={R,C};
        if (map.find(p)==map.end()){
            r_map[R].insert(C);
            c_map[C].insert(R);
            map.insert(p);
        }
        else{
            auto &cols = r_map[R];
            auto it_c = cols.lower_bound(C);
            ll min_diff = INT_MAX;
            ll diff[4][2]={{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
            if (it_c != cols.end()&&*it_c!=C+1) {
                diff[0][0]=*it_c;
                diff[0][1]=*it_c - C;
                min_diff = min(min_diff, *it_c - C);
            }
            if (it_c != cols.begin()&&*it_c!=0) {
                --it_c;
                diff[1][0]=*it_c;
                diff[1][1]=C-*it_c;
                min_diff = min(min_diff, C-*it_c);
            }
            auto &rows = c_map[C];
            auto it_r = rows.lower_bound(R);
            if (it_r != rows.end()&&*it_r!=R+1) {
                diff[2][0]=*it_r;
                diff[2][1]=*it_r - R;
                min_diff = min(min_diff, *it_r - R);
            }
            if (it_r != rows.begin()&&*it_r!=0) {
                --it_r;
                diff[3][0]=*it_r;
                diff[3][1]=R-*it_r;
                min_diff = min(min_diff, R-*it_r);
            }
            rep(j,4){
                if(diff[j][1]==min_diff){
                    if(j>2){
                        c_map[C].insert(diff[j][0]);
                        map.insert({diff[j][0],C});
                    }
                    else{
                        r_map[R].insert(diff[j][0]);
                        map.insert({R,diff[j][0]});
                    }
                }
            }
            rep(i,4){
                cout << diff[i][0] << " " << diff[i][1] << endl;
            }
        }
        for(auto i : map){
            cout << i.first << " " << i.second << endl;
            for(auto j : r_map[i.first]){
                cout << j << " ";
            }
            cout << endl;
            for(auto j : c_map[i.second]){
                cout << j << " ";
            }
        }
        cout <<endl<<endl;
    }
    for(auto i : map){
        cout << i.first << " " << i.second << endl;
    }
    cout << H*W-map.size();
}