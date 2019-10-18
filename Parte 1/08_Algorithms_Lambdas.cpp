#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  os << "[";

  bool first = true;

  for (const auto& k : vec) {
    if (first) {
      os << k;
      first = false;
    } else {
      os << ", " << k;
    }
  }

  os << "]";

  return os;
}

int main() {
  vector<int> vec;
  int i = 0;
  while (cin >> i) {
    vec.push_back(i);
  }

  cout << vec << '\n';

  transform(begin(vec), end(vec), begin(vec),
            [](const auto& k) { return k / 2; });
  cout << vec << '\n';

  int sum = accumulate(begin(vec), end(vec), 0, [](auto a, auto b){ return a + b; });
  cout << sum << '\n';
}