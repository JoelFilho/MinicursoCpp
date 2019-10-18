#include <iostream>
#include <string>

using namespace std;

int main() {
  const char* c_string = "Hello World!";
  cout << c_string << '\n';

  //
  char char_array[] = {"Hello World."};
  cout << char_array << '\n';
  char_array[11] = '!';
  cout << char_array << '\n';

  //
  string s = "Hello World!";

  cout << s << '\n';

  s += '\n';
  for (auto c : s) {
    cout << c;
  }

  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
  }
}