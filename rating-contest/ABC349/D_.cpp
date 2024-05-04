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
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

map<ull, ull> partitions;
ull smal_left, big_right;
ull big_left;


ull smal_input(ull target,ull i){
    ull change;
    ull tmp;
    if(40<i){
        tmp = 1ULL<<40;
        tmp *= 1ULL << (i-40);
        change=target+tmp;
    }else{
        tmp = 1ULL<<i;
        change=target+tmp;
    }
    cout << "smal___"<<target <<"change="<< change <<i<<"      "<< tmp<< endl;
    partitions[target]=change;
    return change;
}

ull big_input(ull target ,ull i){
    ull change;
    ull tmp;
    if(40<i){
        tmp = 1ULL<<40;
        tmp *= 1ULL << (i-40);
        change=target-tmp;
    }else{
        tmp = 1ULL<<i;
        change=target-tmp;
    }
    cout<< "big___" << target <<"change="<< change <<" "<< i<< "      "<<tmp<<endl<<endl;
    partitions[change]=target;
    big_left=target;
    return change;
}

// 3940649673945088 3940649673949184
// 3940649673949184 4503599627370496
// 4503599627370496 9007199254740992
// 9007199254740992 11258999068426240
// 11258999068426240 11540474045136896

// 11540474045136896 11549270138159104
// 11549270138159104 11549545016066048
// 11549545016066048 11549545024454656

// 3940649673945088 3940649673949184
// 3940649673949184 4503599627370496
// 4503599627370496 9007199254740992
// 9007199254740992 18014398509481984
// 11558066231181311 11558066231181312

// 11558066231181312 11549270138159104
// 11549270138159104 11549545016066048
// 11549545016066048 11549545024454656

// 11558066231181312-11540474045136896

ull smal_chak(ull nex){
    ull ans=0;
    while(nex%2==0&&nex!=0){
        ans++;
        nex/=2;
    }
    return ans;
}
ull jou(ull i){
    ull tmp;
    if(40<i){
        tmp = 1ULL<<40;
        tmp *= 1ULL << (i-40);
        return tmp;
    }else{
        tmp = 1ULL<<i;
        return tmp;
    }
}

ull big_chak(ull nex){
    ull ans=0;
    while(nex%2==0&&(nex-1)*jou(ans)>=smal_left){
        ans++;
        nex/=2;
        //cout << "nex="<<nex <<endl;
    }
    //cout << "ans="<<ans << "nex"<<nex<<endl;
    return ans;
}

int main() {
    ull L, R;
    cin >> L >> R;
    smal_left = L;
    big_right = big_left = R;

    ull smal_flag = 0, big_flag =0;
    while (smal_left!=big_left&&smal_left!=R&&big_right!=L) {
        smal_flag = smal_chak(smal_left);
        smal_left = smal_input(smal_left, smal_flag);
        if(smal_left==big_right)break;
        big_flag = big_chak(big_right);
        big_right = big_input(big_right, big_flag);
        
        for (const auto& partition : partitions) {
            cout << partition.first << " " << partition.second << endl;
        }
        cout<<"smal_flag="<<smal_flag<<"big_flag= "<<big_flag<<endl<< endl;
    }
    cout << partitions.size() << endl;
    for (const auto& partition : partitions) {
        cout << partition.first << " " << partition.second << endl;
    }

    
    return 0;
}

