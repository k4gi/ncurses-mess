#include <string>
#include <iostream>

#include "enigma_machine.h"

int main() {
	enigma_machine hello;
	std::cout << "hello\n";
	
	hello.set_wheel(0,0,0);
	//hello.set_wheel(1,1,1);
	hello.set_wheel(2,2,2);
	hello.set_reflector(0);

	std::string out = hello.encode("pp'whg  csc"); //brownfox
	std::cout << out;

	return 0;
}
