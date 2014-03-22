#ifndef AER_DYNAMIC_METACLASS_H_
#define AER_DYNAMIC_METACLASS_H_

#include <aer/base/object.hpp>
#include <aer/util/d_ptr.hpp>
#include <aer/util/as.hpp>

#include <memory>

namespace aer
{

	class Manifest;

	template <typename T>
	class Metaclass
	{
		public:
			Metaclass(Any spawner) : spawner_(spawner)
			{
			}
			Metaclass(const Metaclass<T>& other)
			{
				spawner_ = other.spawner_;
			}
			~Metaclass()
			{
			}
			As<T> instance() const
			{
				return recall_type<std::function<As<T>()>>(spawner_)();
			}
		private:
			Any spawner_;
			//class Self;
			//DPtr<Self> self;
	};

}

#endif
