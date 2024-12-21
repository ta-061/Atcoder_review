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
int main(){
    ll N,M,Sx,Sy;
    cin >> N >> M >> Sx >> Sy;
    ll oldx=Sx,oldy=Sy;
    map<ll, set<ll>>mpx;
    map<ll, set<ll>>mpy;
    rep(i,N){
        ll x,y;
        cin >> x >> y;
        mpx[x].insert(y);
        mpy[y].insert(x);
    }
    ll ans=0;
    rep(i,M){
        char t;
        ll C;
        cin >>t >> C;
        if(t=='U'){
            Sy+=C;
        }else if(t=='D'){
            Sy-=C;
        }else if(t=='L'){
            Sx-=C;
        }else if(t=='R'){
            Sx+=C;
        }
        if(oldx==Sx){
            if(mpx.find(Sx)!=mpx.end()){
                ll L=min(Sy,oldy);
                ll H=max(Sy,oldy);
                auto &st=mpx[Sx];
                auto it = st.lower_bound(L);
                while(it!=st.end()&&*it<=H){
                    ans++;
                    ll target=*it;
                    ys.erase(target);
                    mpy[*it].erase(Sx);
                    it=st.erase(it);
                    if(mpy[target].empty())mpy.erase(target);
                }
                if(st.empty())mpx.erase(Sx);
            }
        }else{
            if(mpy.find(Sy)!=mpy.end()){
                ll L=min(Sx,oldx);
                ll H=max(Sx,oldx);
                auto &st=mpy[Sy];
                auto it = st.lower_bound(L);
                while(it!=st.end()&&*it<=H){
                    ans++;
                    ll target=*it;
                    mpx[*it].erase(Sy);
                    st.erase(it);
                    it=st.erase(it);
                    if(mpx[target].empty())mpx.erase(target);
                }
                if(st.empty())mpy.erase(Sy);
            }
        }
        oldy=Sy;
        oldx=Sx;
    }
    cout << Sx << " " << Sy << " " << ans << endl;
}
