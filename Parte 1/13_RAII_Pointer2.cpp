#include <exception>
#include <iostream>
#include <utility>
using namespace std;

template <typename T>
class Pointer {
 public:
  Pointer() : ptr(nullptr) { cout << "Constructed empty\n"; }
  Pointer(const Pointer&) = delete;
  Pointer(Pointer&& p) : ptr(p.release()) {
    cout << "Constructed with Move constructor\n";
  }

  Pointer& operator=(const Pointer&) = delete;
  Pointer& operator=(Pointer&& p) {
    cout << "Moving using assignment\n";
    delete ptr;
    ptr = p.release();
    return *this;
  }

  Pointer(T* p) : ptr(p) { cout << "Constructed with pointer\n"; }

  ~Pointer() {
    delete ptr;
    cout << "Destructed\n";
  }

  T* operator->() {
    if (!ptr) throw logic_error("Null Pointer!");
    return ptr;
  }

  T& operator*() {
    if (!ptr) throw logic_error("Null Pointer!");
    return *ptr;
  }

  T* get() { return ptr; }
  T* release() {
    auto p = ptr;
    ptr = nullptr;
    return p;
  }

 private:
  T* ptr;
};

struct C {
  C(int id = -1) : id(id) { cout << id << " constructed\n"; }
  ~C() { cout << id << " destroyed\n"; }

 private:
  int id;
};

int main() {
  Pointer<C> p1;
  Pointer<C> p2(new C(2));
  Pointer<C> p3 = move(p2);
  Pointer<C> p4(new C(4));
}