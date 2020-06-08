/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author zjsdut
 */

#ifndef ALGO_UTILS
#define ALGO_UTILS
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <map>
#include <numeric>
#include <set>
#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_
#include <iostream>
#include <vector>
struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} fast_ios_;
template<typename... Ts>
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t);
template<typename T, typename U>
std::istream &operator>>(std::istream &in, std::pair<T, U> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &vec) {
  for (auto &x : vec)
    stream >> x;
  return stream;
}

template<typename... Ts>
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t) {
  std::apply([&in](auto &... args) { ((in >> args), ...); }, t);
  return in;
}
void scan() {
}

template<class T, class... Args>
void scan(T &a, Args &... rest) {
  std::cin >> a;
  scan(rest...);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  bool first = true;
  for (const T &t : vec) {
    if (first)
      first = false;
    else
      out << ' ';
    out << t;
  }
  return out;
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p) {
  out << p.first << ' ' << p.second;
  return out;
}

template<typename T>
std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::vector<T>> &t) {
  for (const auto &row : t) {
    out << row << '\n';
  }
  return out;
}

template<typename T>
void print(const T &t) {
  std::cout << t << ' ';
}

template<typename T, typename... Args>
void print(const T &t, const Args &... rest) {
  print(t);
  print(rest...);
}

template<typename T>
void println(const T &t) {
  std::cout << t << '\n';
}

template<typename T, typename... Args>
void println(const T &t, const Args &... rest) {
  print(t);
  println(rest...);
}
inline int ri() {
  int x;
  std:: cin >> x;
  return x;
}
#endif// JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_

//
// Created by zjsdu on 5/28/2020.
//

#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_ALIAS_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_ALIAS_HPP_
#include <string>
#include <cassert>
#include <queue>
using ll = long long;
using ull = unsigned long long;
using vl = std::vector<ll>;
using vb = std::vector<bool>;
using vi = std::vector<int>;
using vs = std::vector<std::string>;
using pii = std::pair<int, int>;
using pli = std::pair<ll, int>;
using pil = std::pair<int, ll>;
using pll = std::pair<ll, ll>;
using vpii = std::vector<pii>;
template<typename T, typename U = std::less<T>>
using pq = std::priority_queue<T, std::vector<T>, U>;
template<typename... Ts>
using vt = std::vector<std::tuple<Ts...>>;
template<typename T>
class vv {
  std::vector<std::vector<T>> data;

 public:
  explicit vv(int n) {
    assert(n > 0);
    data.assign(n, std::vector<T>{});
  }
  vv(int n, int m, T init = T{}) {
    assert(n > 0 && m > 0);
    data.assign(n, std::vector<T>(m, init));
  }
  std::vector<T> &operator[](size_t i) {
    assert(i < data.size());
    return data[i];
  }
  void fill(T val) {
    for (auto &row : data)
      std::fill(row.begin(), row.end(), val);
  }
  friend std::istream &operator>>(std::istream &in, vv<T> &val) {
    return in >> val.data;
  }
  friend std::ostream &operator<<(std::ostream &out, const vv<T> &val) {
    return out << val.data;
  }
  friend auto begin(const vv<T> &val) {
    return val.data.begin();
  }
  friend auto end(const vv<T> &val) {
    return val.data.end();
  }
  friend auto rbegin(const vv<T> &val) {
    return val.data.rbegin();
  }
  friend auto rend(const vv<T> &val) {
    return val.data.rend();
  }
};

#define rng3(i, a, b)                                                          \
  for (std::common_type<decltype(a), decltype(b)>::type i = a; i < b; ++i)
#define rng2(i, n) rng3(i, 0, n)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rng(...) GET_MACRO(__VA_ARGS__, rng3, rng2)(__VA_ARGS__)
#define up(i, a, b)                                                            \
  for (std::common_type<decltype(a), decltype(b)>::type i = a; i <= b; ++i)
#define down(i, b, a)                                                          \
  for (std::common_type<decltype(a), decltype(b)>::type i = b; i >= a; i--)
#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define rep(n)                                                                 \
  for (auto TOKENPASTE2(_iter_, __LINE__) = n;                                 \
       TOKENPASTE2(_iter_, __LINE__) > 0; --TOKENPASTE2(_iter_, __LINE__))
#define FOR(x, cont) for (const auto &x : cont)
#define For(x, cont) for (auto &x : cont)
#define ALL(x) begin(x), end(x)
// hat off to 300iq
#define RALL(x) rbegin(x), rend(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int) (x).size()
#define UNIQ(vec) (vec).erase(std::unique(ALL(vec)), std::end(vec))
#define LB(cont, x) int(std::lower_bound(ALL(cont), x) - std::begin(cont))
#define UB(cont, x) int(std::upper_bound(ALL(cont), x) - std::begin(cont))
#define x first
#define y second
#endif// JHELPER_EXAMPLE_PROJECT_LIBRARY_ALIAS_HPP_

inline void yes() {
  std::cout << "Yes\n";
}
inline void no() {
  std::cout << "No\n";
}
inline void yn(bool p) {
  std::cout << (p ? "Yes\n" : "No\n");
}
template<typename A, typename B> bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B> bool chkmax(A &a, const B &b) {
  return b > a ? a = b, true : false;
}

template<typename T> struct reversion_wrapper { T &iterable; };
template<typename T> auto begin(reversion_wrapper<T> w) {
  using std::rbegin;
  return rbegin(w.iterable);
}
template<typename T> auto end(reversion_wrapper<T> w) {
  using std::rend;
  return rend(w.iterable);
}
template<typename T> reversion_wrapper<T> reverse(T &&iterable) {
  return {iterable};
}
template<typename T, typename U> T ceil(T x, U y) {
  assert(y > 0);
  if (x > 0)
    x += y - 1;
  return x / y;
}

template<typename T, typename U> T floor(T x, U y) {
  assert(y > 0);
  if (x < 0)
    x -= y - 1;
  return x / y;
}

template<class...> struct typelist {};

template<class T, class... Ts>
constexpr bool any_same = (std::is_same_v<T, Ts> || ...);

template<class F> struct y_combinator {
  template<class... TLs> struct ref {
    y_combinator &self;
    template<class... Args> decltype(auto) operator()(Args &&... args) const {
      using G = std::conditional_t<any_same<typelist<Args...>, TLs...>,
                                   ref<TLs...>, ref<TLs..., typelist<Args...>>>;
      return self.f(G{self}, std::forward<Args>(args)...);
    }
  };
  F f;
  template<class... Args> decltype(auto) operator()(Args &&... args) {
    return ref<>{*this}(std::forward<Args>(args)...);
  }
};
template<class F> y_combinator(F) -> y_combinator<F>;
#ifndef debug
#define debug(...) 42
#endif
#endif// ALGO_UTILS
//
// Created by zjsdu on 5/30/2020.
//

#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_GRID_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_GRID_HPP_
template<typename T> class grid {
  int n, m;
  T *table = nullptr;

 public:
  using value_type = typename T::value_type::value_type;

 public:
  grid(int row, int col) {
    assert(row > 0 && col > 0);
    n = row;
    m = col;
  }
  grid(int row, int col, T &t) : table(&t) {
    assert(row > 0 && col > 0);
    n = row;
    m = col;
  }
  inline bool cover(int i, int j) const {
    return i >= 0 and i < n && j >= 0 && j < m;
  }
  static constexpr int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
  inline std::vector<std::pair<int, int>> rc(int x, int y) const {
    assert(cover(x, y));
    std::vector<std::pair<int, int>> res;
    for (int i = 0; i < 4; i++) {
      if (cover(x + dx[i], y + dy[i]))
        res.emplace_back(x + dx[i], y + dy[i]);
    }
    return res;
  }
  inline std::vector<value_type *> neighbor(int x, int y) const {
    assert(cover(x, y));
    std::vector<value_type*> res;
    for (int i = 0; i < 4; i++) {
      if (cover(x + dx[i], y + dy[i]))
        res.push_back(&((*table)[x + dx[i]][y + dy[i]]));
    }
    return res;
  }
};
#endif// JHELPER_EXAMPLE_PROJECT_LIBRARY_GRID_HPP_

using namespace std;
class DSolveTheMaze {
 public:
  static void solve(istream &, ostream &) {
    int n, m;
    scan(n, m);
    vs maze(n);
    scan(maze);
    grid g(n, m, maze);
    rng (i, n)
      rng (j, m)
        if (maze[i][j] == 'B') {
          debug(i, j);
          for (auto e : g.neighbor(i, j)) {
            if (*e == 'G') {
              return no();
            }
            if (*e == '.') {
              *e = '#';
            }
          }
        }

    debug(maze);
    vv<bool> vis(n, m);
    y_combinator{[&](auto dfs, int x, int y) {
      if (vis[x][y] or maze[x][y] == '#')
        return;
      vis[x][y] = true;
      for (auto [nx, ny] : g.rc(x, y))
        dfs(nx, ny);
    }}(n - 1, m - 1);
    rng (i, n)
      rng (j, m)
        if (maze[i][j] == 'G' && !vis[i][j]) {
          return no();
        }
    yes();
  }
};
/*
 * Make sure that your laptop is plugged in or the build may be slow.
 */


int main() {
  DSolveTheMaze solver;
  auto& in = std::cin;
  auto& out = std::cout;
  int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

  return 0;
}
