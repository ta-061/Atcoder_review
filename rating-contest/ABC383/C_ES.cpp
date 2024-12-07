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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> S(H);
    for (int i=0; i<H; i++) cin >> S[i];
    queue<array<int,3>> q;
    vector<vector<bool>> visit(H, vector<bool>(W,false));
    for (int i=0; i< H; i++){
        for (int j=0; j<W; j++){
            if (S[i][j]=='H') {
                q.push({i,j,0});
                visit[i][j]=true;
                S[i][j]='.';
            }
        }
    }
    int ans = 0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    while(!q.empty()) {
        auto [x,y,dist]=q.front();
        q.pop();
        if(dist>D) continue;
        if (S[x][y]=='.') {
            ans++;
            S[x][y]='f';
        }
        if (dist<D) {
            for (int k=0; k < 4; k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if (nx<0||nx>=H||ny<0||ny>=W) continue;
                if (!visit[nx][ny] && S[nx][ny] !='#' && S[nx][ny] !='H') {
                    visit[nx][ny]=true;
                    q.push({nx, ny, dist+1});
                }
            }
        }
    }
    cout<<ans;
    return 0;
}