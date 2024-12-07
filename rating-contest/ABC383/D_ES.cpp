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
vi sieve(int limit) {
    vector<bool> is(limit+1,true);
    is[0]=false;is[1]=false;
    for (int i=2;i*i<=limit;i++){
        if(is[i]){
            for(int j=i*i;j<=limit;j+=i) is[j]=false;
        }
    }
    vi pr;
    for(int i=2;i<=limit;i++){
        if(is[i]) pr.push_back(i);
    }
    return pr;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N; cin >> N;
    long double N_ld = N;
    long double lim_p8 = pow(N_ld, 1.0L/8.0L); 
    auto is_prime=[&](ll x)->bool{
        if(x<2) return false;
        if(x%2==0 && x!=2) return false;
        for (ll i=3;i*i<=x;i+=2) {
            if(x%i==0) return false;
        }
        return true;
    };
    int count=0;
    for (int p=2; p<=(int)ceil(lim_p8); p++){
        if(is_prime(p)){
            __int128 val=1;
            for(int e=0;e<8;e++) val*=p;
            if(val <= N) count++;
        }
    }
    ll limit_sqrt=(ll)floor(sqrtl(N_ld));
    vi pr=sieve((int)limit_sqrt);
    int count_p=0;
    for (int i=0; i<(int)pr.size(); i++){
        ll p = pr[i];
        ll p2 = (ll)p*p;
        if(p2 > N) break;
        ll limit_q=(ll)floor(sqrtl(N_ld / p2));
        int pos=(int)(upper_bound(pr.begin(), pr.end(), (int)limit_q)-pr.begin());
        int count_candidates = pos-(i+1);
        if(count_candidates > 0) count_p += count_candidates;
    }
    cout <<count+count_p;
    return 0;
}
