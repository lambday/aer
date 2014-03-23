#include <aer/aer.hpp>

#include <mybaseclass.hpp>
#include <iostream>
#include <vector>
#include <map>

class MyConcreteClass : public MyBaseClass
{
	int myMethod() override
	{
		std::cout << "My method of MyConcreteClass called\n";
		return 0;
	}
};

class MyOtherConcreteClass : public MyBaseClass
{
	int myMethod() override
	{
		std::cout << "My method of MyOtherConcreteClass called\n";
		return 0;
	}
};

AER_BEGIN_MANIFEST("Simple library")
AER_EXPORT(MyConcreteClass, MyBaseClass, "basic")
AER_EXPORT(MyOtherConcreteClass, MyBaseClass, "other_basic")
AER_END_MANIFEST()
