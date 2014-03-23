#include <aer/aer.hpp>
#include <iostream>

#include <mybaseclass.hpp>

static aer::Tag<int> int_parameter = aer::Tag<int>("f");

int main()
{
	auto library = aer::loadLibrary("./plugin.so");
	auto manifest = library.manifest();
	auto metaclass = manifest.classByName<MyBaseClass>("basic"); 
	auto object = metaclass.instance();

	object->set(int_parameter, 4040);
	object->myMethod();
	std::cout << "Value is " << object->get(int_parameter) << "\n";
	object->set(int_parameter, 4020);
	object->myMethod();
	std::cout << "Value is " << object->get(int_parameter) << "\n";
}
