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

int H, W;
char grid[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];
int start_r, start_c, goal_r, goal_c;
int R[MAX_N], C[MAX_N], E[MAX_N];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool bfs(int sr, int sc) {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == goal_r && c == goal_c) return true;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W || grid[nr][nc] == '#' || visited[nr][nc]) continue;

            for (int j = 0; j < MAX_N; ++j) {
                if (R[j] == nr && C[j] == nc) {
                    int new_energy = E[j];
                    if (new_energy >= 0) {
                        new_energy = max(0, new_energy);
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                    break;
                }
            }
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }

    return false;
}

int main() {
    cin >> H >> W;

    rep (i, H) {
        rep (j, W) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start_r = i;
                start_c = j;
            } else if (grid[i][j] == 'T') {
                goal_r = i;
                goal_c = j;
            }
        }
    }

    int N;
    cin >> N;
    bool flag=true;
    rep (i, N) {
        cin >> R[i] >> C[i] >> E[i];
        --R[i]; 
        --C[i];
        if(start_r == R[i]&&start_c == C[i])flag = false;
    }
    if(flag){
        cout << "No" << endl;
        return 0;
    }


    memset(visited, false, sizeof(visited));
    if (bfs(start_r, start_c)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}