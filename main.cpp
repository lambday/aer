#include <aer/aer.hpp>
#include <iostream>

class MyBaseClass : public aer::Object
{
};

static aer::Tag<int> int_parameter;

int main()
{
	auto library = aer::Library("mylibrary.so");
	auto manifest = library.manifest();
	auto metaclass = manifest.metaclass<MyBaseClass>("basic"); 
	auto object = metaclass.instance();

	object->set(int_parameter, 4040);
	std::cout << "Value is " << object->get(int_parameter);
}
