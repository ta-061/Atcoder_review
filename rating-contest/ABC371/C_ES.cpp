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
    int N, mg, mh;
    cin >> N;
    ll ans = 0;

    vector<map<int, bool>> Mg(N+1);
    vector<map<int, bool>> Mh(N+1); 
    vector<map<int, bool>> chakmap(N+1); 
    vector<int> degree_Mg(N + 1, 0); 
    vector<int> degree_Mh(N + 1, 0); 
    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0)); 
    
    cin >> mg;
    rep(i, 0, mg) {
        int a, b;
        cin >> a >> b;
        degree_Mg[a]++;
        degree_Mg[b]++;
        Mg[a][b] = true;
        Mg[b][a] = true;
    }
    
    cin >> mh;
    rep(i, 0, mh) {
        int a, b;
        cin >> a >> b;
        degree_Mh[a]++;
        degree_Mh[b]++;
        Mg[a][b] = true;
        Mg[b][a] = true;
    }
    
    rep(i, 1, N + 1) {
        rep(j, i + 1, N + 1) {
            cin >> A[i][j]; 
        }
    }
    for(auto i : degree_Mg){
        cout << i << " ";
    }cout << endl;
    for(auto i : degree_Mh){
        cout << i << " ";
        }cout << endl;
    
    bool all_equal = false;
    while (!all_equal) {
        all_equal = true; 
        rep(i, 1, N + 1) {
        while (degree_Mh[i] < degree_Mg[i]) {
            int min_cost = INT_MAX;
            int best_j = -1;
          
            rep(j, 1, N + 1) {
                if (i != j &&!Mh[i][j]&&degree_Mh[j]<degree_Mg[j]&&!chakmap[i][j]) {
                    if (A[i][j] < min_cost) {
                        min_cost = A[i][j];
                        best_j = j;
                    }
                }
            }

            if (best_j != -1) {
                Mh[i][best_j] = true;
                Mh[best_j][i] = true;
                chakmap[i][best_j] = true;
                chakmap[best_j][i] = true;
                degree_Mh[i]++;
                degree_Mh[best_j]++;
                ans += min_cost;
                cout << i << "つける" << best_j << endl;
            }else{
                all_equal = false;
                break;
            }
        }
        while (degree_Mh[i]>degree_Mg[i]) {
            int min_cost = INT_MAX;
            int best_j = -1;
          
            rep(j, 1, N + 1) {
                if (i!=j&&Mh[i][j]&&degree_Mh[j]>degree_Mg[j]) {
                    if (A[i][j] < min_cost) {
                        min_cost = A[i][j];
                        best_j = j;
                    }
                }
            }

            if (best_j != -1) {
                Mh[i][best_j] = false;
                Mh[best_j][i] = false;
                chakmap[i][best_j] = true;
                chakmap[best_j][i] = true;
                degree_Mh[i]--;
                degree_Mh[best_j]--;
                ans += min_cost;
                cout << i << "消す" << best_j << endl;
            }else{
                all_equal = false;
                break;
            }
        }
    }
    }
    cout << ans << endl;
    for(auto i : degree_Mg){
        cout << i << " ";
    }cout << endl;
    for(auto i : degree_Mh){
        cout << i << " ";
        }cout << endl;

    return 0;
}