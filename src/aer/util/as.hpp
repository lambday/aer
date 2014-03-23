#ifndef AER_UTIL_PTR_H_
#define AER_UTIL_PTR_H_

#include <memory>

namespace aer
{

	template <typename T>
	class As : public std::shared_ptr<T>
	{
	public:
		As(T* p) : std::shared_ptr<T>(p)
		{
		}
		As(const As<T>& other) : std::shared_ptr<T>(std::move(other))
		{
		}
		As(std::shared_ptr<T> other) : std::shared_ptr<T>(std::move(other))
		{
		}
		~As()
		{
		}
	};

}

#endif

