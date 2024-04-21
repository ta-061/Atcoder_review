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
ll chek(ll K, ll count, ll old){
    if(count==0)return K-1;
    ll num_max=K/pow(9,count);
    K = K-(num_max)*pow(9,count);
    if(old == num_max)num_max++;
    //cout << "K="<<K<<" count="<<count<<" num_max="<<num_max<<endl;
    return chek(K,count-1,num_max)+pow(10, count)*num_max;
}
int main() {
    int N, M, A, B;
    cin >> N >> M;
    vi row(N,0);
    vi col(N,0);
    vector<pair<int, int>> ans;
    unordered_map<int, unordered_map<int, int>> an;
    rep(i,M){
        cin >> A >> B;
        row[A-1]++;
        col[B-1]++;
        ans.emplace_back(A,B);
        an[A-1][B-1]=2;
    }
    // for(auto& i :row){
    //     cout << i << " ";
    // }
    // for(auto& i :col){
    //     cout <<endl << i;
    // }
    // cout <<endl<<endl;
    
    rep(i,N){
        if(row[i]<M){
            rep(j, N){
                if(col[j]<M&&an[i][j]!=2){
                    ans.push_back(make_pair(i+1,j+1));
                    row[i]++;
                    col[j]++;
                    an[i][j]=1;
                    //cout << i+1 <<" "<< j+1<<endl;
                    // rep(x,N){
                    //     rep(y,N){
                    //         cout << an[x][y]<<" ";
                    //     }
                    //     cout <<endl;
                    // }
                    // for(auto& p :col){
                    //     cout << p << " ";
                    // }
                    // for(auto& p :row){
                    //     cout <<endl << p;
                    // }
                    // cout <<endl;
                    if(row[i]==M){
                        break;
                    }
                }
            }
            //cout <<endl;
        }
    }
    int ta=0;
    int tmp=0;
    rep(i,N){
        if(col[i]<M){
            ta=i;
            break;
        }
    }
    while (row[N - 1] < M) {
        bool flag=false;
        rep(i,ans.size()) {
            if (ans[i].second == tmp+1 && an[ans[i].first-1][ans[i].second-1] != 2 && an[ans[i].first-1][ta] == 0) {
                //cout <<ans[i].first<<" "<< ans[i].second<<" "<< an[ans[i].first-1][ans[i].second-1]<< " "<<an[ans[i].first-1][N-1]<<endl;
                an[ans[i].first-1][ans[i].second-1]=0;
                ans[i].second = ta+1;
                an[ans[i].first-1][ta]=1;
                // cout <<ans[i].first<<" "<< ans[i].second<<endl<<endl;
                an[N-1][tmp]=1;
                row[N - 1]++;
                col[ta-1]++;
                flag=true;
                break;
            }
        }
        if(flag)ans.emplace_back(N, tmp+1);
        tmp++;
    }
    // rep(x,N){
    //     rep(y,N){
    //         cout << an[x][y]<<" ";
    //     }
    //     cout <<endl;
    // }

    cout << ans.size() << endl;
    for (auto& p : ans) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}