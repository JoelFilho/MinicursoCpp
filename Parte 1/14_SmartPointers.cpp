#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct C {
  C(int id) : id(id) { cout << id << " constructed\n"; }
  ~C() { cout << id << " destroyed\n"; }

 private:
  int id;
};

int main() {
  vector<unique_ptr<C>> v;
  v.emplace_back(new C(0));
  v.emplace_back(make_unique<C>(1));
  v.push_back(make_unique<C>(2));

  auto c3 = make_unique<C>(3);
  v.push_back(move(c3));
  cout << 'c3: ' << c3.get() << '\n';
}