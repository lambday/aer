#ifndef AER_UTIL_IMPLEMENTATION_PTR_H_
#define AER_UTIL_IMPLEMENTATION_PTR_H_

#include <memory>

namespace aer
{
	template <typename T>
	class implementation_ptr : public std::unique_ptr<T>
	{
	public:
		typedef typename std::unique_ptr<T>::pointer pointer;
		implementation_ptr(pointer p) : std::unique_ptr<T>(p)
		{
		}
		implementation_ptr(const implementation_ptr<pointer>& other) : std::unique_ptr<T>(std::move(other))
		{
		}
	};
}

#endif
