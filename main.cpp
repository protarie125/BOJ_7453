#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl A, B, C, D;
vl AB, CD;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  A = vl(n);
  B = vl(n);
  C = vl(n);
  D = vl(n);
  for (auto i = 0; i < n; ++i) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  const auto& n2 = n * n;
  AB.reserve(n2);
  CD.reserve(n2);

  for (auto i = 0; i < n; ++i) {
    const auto& a = A[i];
    const auto& c = C[i];
    for (auto j = 0; j < n; ++j) {
      const auto& b = B[j];
      const auto& d = D[j];
      AB.push_back(a + b);
      CD.push_back(c + d);
    }
  }

  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());

  auto ans = ll{0};
  ll l = 0;
  ll r = n2 - 1;
  while (l < n2 && 0 <= r) {
    const auto& p = AB[l];
    const auto& q = CD[r];
    if (p + q < 0) {
      ++l;
    } else if (0 < p + q) {
      --r;
    } else {
      ll lc = 1;
      ll rc = 1;
      while (l + 1 < n2 && p == AB[l + 1]) {
        ++lc;
        ++l;
      }
      while (0 <= r - 1 && q == CD[r - 1]) {
        ++rc;
        --r;
      }

      ans += lc * rc;
      ++l;
    }
  }
  cout << ans;

  return 0;
}