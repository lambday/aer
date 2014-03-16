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
	
	template <typename T>
	struct EnableSelf : public std::enable_shared_from_this<T>
	{
		inline As<T> self()
		{
			return As<T>(std::enable_shared_from_this<T>::shared_from_this());
		}
	};


}

#endif

