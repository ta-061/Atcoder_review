#include <bits/stdc++.h>
using namespace std;

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;

using ull = unsigned long long;
using ll = long long;
ll INF = 2e18;
#include <boost/multiprecision/cpp_int.hpp>
namespace multip = boost::multiprecision;
using lll = multip::int128_t;
using ld = long double;
using bl = bool;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m); // modintのmodをmに設定使い方
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
// pq<int> max_queue;  で定義
// pq_g<int> min_queue; で定義

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vc<int>; using vll = vc<long long>; using vvi = vv<int>; using vvll = vv<ll>; using vvvll = vv<vll>;
using vs = vector<string>; using vvs = vv<string>;
using vb = vc<bl>; using vvb = vv<bl>; using vvvb = vv<vb>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;



#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define DREP1(i, n) for (auto i = n; (i) >= 0; --(i))
#define DREP2(i, l, r) for (auto i = (l); (i) >= (r); --(i))
#define drep(...) OVERLOAD_REP(__VA_ARGS__, DREP2, DREP1)(__VA_ARGS__)

#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl

//if (regex_match(s, regex("")))YN;//文字列sの判定を行う。コメントアウトを外して「""」の中に判定する内容を入れる

template<>
struct std::vector<bool>: std::basic_string<bool> {
    using std::basic_string<bool>::basic_string, std::basic_string<bool>::operator =;
    explicit vector(size_t n): vector(n, false) {}
};
bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

vl dx = { 1,0,-1,0 };
vl dy = { 0,1,0,-1 };
//vl dx={1,1,0,-1,-1,-1,0,1};
//vl dy={0,1,1,1,0,-1,-1,-1};

//ラムダ記法
/*auto func = lambda($(0) * 3 + 1);*/
// 引数を取得するマクロ
#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))
// ラムダ式を短く書くマクロ
#define lambda(...) ([&](auto&&... _args) { return (__VA_ARGS__); })

#define yu_qurid(x,y) ((x)*(x)+(y)*(y))//ユークリッド距離 sqrtはしてないなので注意
#define mannhattan(x1,x2,y1,y2) (abs(x1-x2)+abs(y1-y2)) // マンハッタン距離 = |x1-x2|+|y1-y2|

template<class T>T tousa_sum1(T l, T d, T r) {//初項,公差,末項 で総和を求める
    T wide = (r - l) / d + 1;
    return (l + r) * wide / 2;
}
template<class T>T tousa_sum2(T a, T d, T n) {//初項,交差,項数 で総和を求める
    return (a * 2 + d * (n - 1)) * n / 2;
}
ll kousa_kousuu(ll l, ll r, ll d) {//初項,末項,交差 で等差数列の項数を求める
    return (r - l) / d + 1;
}
mint touhi_sum(mint a, mint r, ll n) {//初項,公比,項数で等比数列の総和を求める
    if (r == 1) {
        return a * n;
    }
    mint bunsi = a * (r.pow(n) - mint(1));
    mint bunbo = r - 1;
    return bunsi / bunbo;
}

#define vc_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する

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
// exit_with(...)	指定した処理を実行した後、プログラムを終了する
// break_with(...)	指定した処理を実行した後、ループを終了する
// continue_with(...)	指定した処理を実行した後、次のループ反復にスキップする
#define exit_with(...) ({ __VA_ARGS__; exit(0); })
#define break_with(...) ({ __VA_ARGS__; break; })
#define continue_with(...) ({ __VA_ARGS__; continue; })


int main() {
    // code
    return 0;
}