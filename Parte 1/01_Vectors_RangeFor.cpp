#include <iostream>
#include <vector>

using namespace std;

void c_array() {
  int arr[] = {1, 2, 3, 4, 5};

  cout << "arr:\n";

  // Não faça assim!
  int N = sizeof(arr) / sizeof(int);

  for (int i = 0; i < N; i++) {
    cout << arr[i] << ' ';
  }

  cout << "\n\n";
}

void c_array_range() {
  int arr[] = {1, 2, 3, 4, 5};

  cout << "arr:\n";

  for (int k : arr) {
    cout << k << ' ';
  }

  cout << "\n\n";
}

void vectors() {
  vector<int> vec = {1, 2, 3, 4, 5};

  cout << "vec:\n";

  for (int k : vec) {
    cout << k << ' ';
  }

  cout << "\n\n";
}

int main() {
  c_array();
  c_array_range();
  vectors();
}