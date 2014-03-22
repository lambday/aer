#include <aer/aer.hpp>

#include <mybaseclass.hpp>
#include <iostream>
#include <vector>
#include <map>

class MyConcreteClass : public MyBaseClass
{

};

extern "C" aer::Manifest aerManifest()
{
	std::cout << "Creating manifest for you\n";
	static aer::Metaclass<MyBaseClass> metaclazz(aer::erase_type(std::function<aer::As<MyBaseClass>()>(
				[]() -> aer::As<MyBaseClass>
				{
					return aer::As<MyBaseClass>(new MyConcreteClass()); 
				})));
	static aer::Manifest manifest("Stupid library with stupid classes", {std::make_pair("basic", aer::erase_type(metaclazz))});

	return manifest;
}
