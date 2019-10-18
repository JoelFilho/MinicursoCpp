#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int>& vec) {
  cout << "[";

  bool first = true;

  for (int k : vec) {
    if (first) {
      cout << k;
      first = false;
    } else {
      cout << ", " << k;
    }
  }

  cout << "]";
}

void increment(vector<int>& vec) {
  for (int& k : vec) {
    k++;
  }
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  print_vector(v);
  increment(v);
  print_vector(v);
}