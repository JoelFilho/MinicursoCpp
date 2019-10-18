#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(const vector<T>& vec) {
  cout << "[";

  bool first = true;

  for (const auto& k : vec) {
    if (first) {
      cout << k;
      first = false;
    } else {
      cout << ", " << k;
    }
  }

  cout << "]";
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  print_vector(v);

  vector<float> v2 = {0, 0.25, 0.5, 0.75, 1};
  print_vector(v2);
}