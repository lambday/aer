#ifndef AER_UTIL_IMPLEMENTATION_PTR_H_
#define AER_UTIL_IMPLEMENTATION_PTR_H_

#include <memory>

namespace aer
{
	template <typename T>
	class DPtr : public std::unique_ptr<T>
	{
	public:
		typedef typename std::unique_ptr<T>::pointer Pointer;

		DPtr() : 
			std::unique_ptr<T>(new T)
		{
		}
		// TODO avoid allocation for stateless 'private's
		DPtr(const DPtr<Pointer>& other) : 
			std::unique_ptr<T>(std::move(other))
		{
		}
	};
}

#endif
