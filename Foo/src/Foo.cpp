#include <foo/Foo.hpp>

#include <cpuinfo_x86.h>
#include <iostream>

namespace foo {
  void helloWorld() {
		std::cout << "foo::hello()";
  }

void Foo::operator()() const {
	std::cout << "foo::Foo()()";
}
}

