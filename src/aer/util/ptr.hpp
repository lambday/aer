#ifndef AER_UTIL_PTR_H_
#define AER_UTIL_PTR_H_

#include <memory>

namespace aer
{
	template <typename T>
	class ptr : public std::shared_ptr<T>
	{
	public:
		ptr(T* p) : std::shared_ptr<T>(p)
		{
		}
		ptr(const ptr<T>& other) : std::shared_ptr<T>(std::move(other))
		{
		}
	};
}

#endif

