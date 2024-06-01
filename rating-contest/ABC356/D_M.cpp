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
using vb = vector<bool>;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)

#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

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
const int MOD = 998244353;

int main() {
    ull N, M, sum=0, tmp=0;
    int bit=0;
    cin >> N>> M;
    if(N==0){
        bit=1;
    }else if (N<255){
        bit=log2(N);
    }else{
        ull z=N>>10;
        bit=log2(z)+9;
    }

    rep(i,bit-1){
        if(M&(1LL<<i)){
            sum+=bit-1;
            tmp++;
        }
    }
    ull mask=0;
    ull tmpp=0;
    cout << bitset<60>(1LL<<bit)<<endl;
    if(M&(1LL<<bit)){
        cout << "っこ"<<endl;
        mask = (1LL << (bit + 1)) - 1;
        tmpp =M| mask;
        sum+=1LL<<tmpp;
    }
    cout << "N="<<bitset<60>(N)<<endl<<"M="<<bitset<60>(M) <<endl<<"m="<<bitset<60>(mask)<< endl;
    cout << sum << endl;

    return 0;
}
