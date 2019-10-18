#include <iostream>
#include <string>

using namespace std;

enum class Gender { Male, Female, NonBinary };

struct Person {
  string name;
  Gender gender;
  int age;
};

int main() {
  Person p1{"Joel", Gender::Male, 26};
  cout << p1.name << ", " << p1.age << '\n';
}