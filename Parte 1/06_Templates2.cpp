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
  vector<int> v = {1, 2, 3, 4, 5};
  cout << v << '\n';

  vector<float> v2 = {0, 0.25, 0.5, 0.75, 1};
  cout << v2 << '\n';

  vector<vector<int>> v3 = {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}};
  cout << v3 << '\n';
}