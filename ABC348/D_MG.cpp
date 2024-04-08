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

const int MAX_H = 200;
const int MAX_W = 200;
const int MAX_N = 300;

int H, W, N;
vvi grid(MAX_H,vi(MAX_W));
vvi visited(MAX_H,vi(MAX_W,-1));
int start_r, start_c, goal_r, goal_c;
int R, C, E;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


bool bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    q.emplace(sr, sc);
    visited[sr][sc] = grid[sr][sc];

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        rep (i, 4) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int ne = visited[r][c]-1;
            if (nr < 0 || nr >= H || nc < 0 || nc >= W || grid[nr][nc] == -1 || visited[r][c]<1) continue;
            if(visited[nr][nc] < grid[nr][nc] || visited[nr][nc]<visited[r][c]-1 ){
                visited[nr][nc]=max(grid[nr][nc], visited[r][c]-1);
                q.emplace(nr, nc);
            }
            if (visited[goal_r][goal_c]>-1) return true;
        }
    }

    return false;
}

int main() {
    cin >> H >> W;
    char a;

    rep (i, H) {
        rep (j, W) {
            cin >> a;
            if(a == '#'){
                grid[i][j]=-1;
            }
            if (a == 'S') {
                start_r = i;
                start_c = j;
            } else if (a == 'T') {
                goal_r = i;
                goal_c = j;
            }
        }
    }

    cin >> N;
    rep (i, N) {
        cin >> R >> C >> E;
        --R; 
        --C;
        grid[R][C]=E;
    }

    
    if (bfs(start_r, start_c)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}