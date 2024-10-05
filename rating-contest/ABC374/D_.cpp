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
    double N, S, T;
    cin >> N >> S >> T;
    double A, B, C, D;
    vector<pair<double,double>> xy(N*2);
    double diff = DBL_MAX;
    vector<bool> db(N*2,false);
    double ans=0;
    int see=0;
    rep(i, N) {
        cin >> A >> B >> C >> D;
        xy[i*2]={A,B};
        xy[i*2+1]={C,D};
        if(A==0&&B==0)see=i*2;
        if(C==0&&D==0)see=i*2+1;
        ans+=sqrt(pow(A-C,2)+pow(B-D,2));
    }
    ans/=T;
    cout << ans << endl;
    db[see] = true;
    see =(see%2==0) ? see+1 : see-1;
    db[see] = true;
    int tmp_see=see;
    rep(i, N-1){
        diff=DBL_MAX;
        rep(j,xy.size()){
            if(db[j])continue;
            double tmp=sqrt(pow(xy[see].first-xy[j].first,2)+pow(xy[see].second-xy[j].second,2));
            if(diff>tmp || diff==tmp){
                diff=tmp;
                tmp_see=j;
            }
        }
        ans+=diff/S;
        cout << xy[tmp_see].first << " "<<xy[tmp_see].second<<" "<<diff/S << endl;
        db[tmp_see]=true;
        see=(tmp_see%2==0)?tmp_see+1 : tmp_see-1;
        db[see] = true;
    }
    cout << fixed << setprecision(20) << ans << endl;
}