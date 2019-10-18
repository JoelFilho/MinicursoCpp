#include <algorithm>
#include <iostream>
#include <vector>

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
  sort(begin(vec), end(vec));
  cout << vec << '\n';
}