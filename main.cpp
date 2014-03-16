#include <aer/aer.hpp>
#include <iostream>

class MyBaseClass : public aer::Object
{
	public:
		int myMethod()
		{
			return 0;
		}
};

static aer::Tag<int> int_parameter;

int main()
{
	auto library = aer::loadLibrary("./plugin.so");
	auto manifest = library->manifest();
	auto metaclass = manifest->metaclass<MyBaseClass>("basic"); 
	aer::As<MyBaseClass> object = metaclass->instance();

	object->set(int_parameter, 4040);
	object->myMethod();
	std::cout << "Value is " << object->get(int_parameter);
}
