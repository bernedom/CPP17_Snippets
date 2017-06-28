/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
* This example illustrates the usage of trailing return types
**/

struct A {
  struct B {
    struct C {
      struct D {};

      D foo(const C &); // returns an instance of A::B::C::D
      D bar(const C &); // returns an instance of A::B::C::D
    };
  };
};
// Standard, the scope of D has to be specified
A::B::C::D A::B::C::foo(const C &){};

// Trailing return type, D is in scope of A::B::C
auto A::B::C::bar(const C &) -> D{};

// automatic computation of the return type
template <typename A, typename B>
auto add(A a, B b) -> decltype(a + b)
{
  return a + b;
}

int main(int, char **) {}
