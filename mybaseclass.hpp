#ifndef TEST_BASE_CLASS_H_
#define TEST_BASE_CLASS_H_

#include <aer/aer.hpp>

class MyBaseClass : public aer::Object
{
	public:
		virtual int myMethod()
		{
			return 0;
		}
};


#endif
