#include <iostream>
#include <string>

using namespace std;

class Person {
 public:
    Person(const string& name, int age) : name(name), age(age){}
 private:
    string name;
    int age;
};