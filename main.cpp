#include <aer/base/object.hpp>
#include <iostream>


void libraries()
{
/*
	DynamicLibrary dl("./libtest_plugin.so");
	if (!dl.ready())
	{
		printf("Error: %s", dlerror());
	}
	Symbol symbol = dl.symbol("create");
	if (!symbol.ready())
	{
		printf("Error: %s", dlerror());
	}
	else
	{
		symbol.unsafeCall();
	}
*/
}

int main()
{
	aer::Tag<float> float_tag;
	aer::Tag<int> int_tag;
	aer::Object object;
	object.set(int_tag, 3);
	object.set(float_tag, 4.0f);
	std::cout << "Value is " << object.get(int_tag);
}
