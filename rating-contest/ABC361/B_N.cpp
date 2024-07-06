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
    int a, b, c, d, e, f, g, h,i,j,k,l;
    cin >> a>> b>> c >> d >> e >>f;
    cin >> g>> h>> i >> j >> k >>l;
    int a_x, a_y, a_z;
    int b_x, b_y, b_z;
    a_x = max(a,g);
    a_y = max(b,h);
    a_z = max(c,i);

    b_x = min(d, j);
    b_y = min(e, k);
    b_z = min(f, l);
    int diff_x=max(0,b_x-a_x);
    int diff_y=max(0,b_y-a_y);
    int diff_z=max(0,b_z-a_z);
    cout << a_x<<" "<< a_y<<" "<< a_z<<endl;
    cout << b_x<<" "<< b_y<<" "<< b_z<<endl;
    cout << diff_x<<" "<< diff_y<<" "<< diff_z;

    if(diff_x*diff_y*diff_z>0){
        cout << "Yes";
    }else{
        cout <<"No";

    }
    
    
    return 0;
}