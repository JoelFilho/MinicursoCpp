#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
 public:
  virtual string speak() = 0;
  virtual ~Animal() = default;
};

class Cat : public Animal {
 public:
  Cat() : name("Cat") {}
  Cat(const string& name) : name(name) {}
  string speak() override { return name + " Meows loudly"; }

 private:
  string name;
};

class Cow : public Animal {
 public:
  Cow() : name("Cow") {}
  Cow(const string& name) : name(name) {}
  string speak() override { return name + " Moos"; }

 private:
  string name;
};

int main() {
  // NÃO FAÇA ASSIM! Veja as próximas lições em Smart Pointers!
  Animal* a1 = new Cat;
  Animal* a2 = new Cow;
  vector<Animal*> animals = {a1, a2, new Cat("Garfield"), new Cow("Betty")};
  for (auto animal : animals) {
    cout << animal->speak() << '\n';
  }

  for (auto animal_ptr : animals) {
    delete animal_ptr;
  }
}