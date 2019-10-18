#include <exception>
#include <iostream>

template <typename T>
class Pointer {
 public:
  Pointer() : ptr(nullptr) { cout << "Constructed empty\n"; }

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

 private:
  T* ptr;
};

// Ver próximo exemplo para extensão e uso.