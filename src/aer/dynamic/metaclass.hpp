#ifndef AER_DYNAMIC_METACLASS_H_
#define AER_DYNAMIC_METACLASS_H_

#include <aer/base/object.hpp>
#include <aer/util/implementation_ptr.hpp>
#include <aer/util/ptr.hpp>

#include <memory>

namespace aer
{

	template <typename T>
	class Metaclass
	{
		public:
			Metaclass()
			{
			}
			Metaclass(const Metaclass<T>& other)
			{
			}
			~Metaclass()
			{
			}
			ptr<T> instance() const
			{
				return ptr<T>(new T());
			}
	};

}

#endif
