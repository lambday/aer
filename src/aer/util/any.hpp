#ifndef AER_ANY_H_
#define AER_ANY_H_

#include <string.h>
#include <stdexcept>

#define likely(x) x

/**
 * This code is based on 
 */

namespace aer
{
	namespace impl
	{
		class BaseAnyPolicy
		{
			public:
				virtual void set(void** storage, const void* v) const = 0;
				virtual void clear(void** storage) const = 0;
		};

		template <typename T>
		class PointerValueAnyPolicy : public BaseAnyPolicy
		{
			public:
				virtual void set(void** storage, const void* v) const
				{
					*(storage) = new T(*reinterpret_cast<T const*>(v));
				}
				virtual void clear(void** storage) const
				{
					delete reinterpret_cast<T*>(*storage);
				}
		};
	}

	class Any
	{
	public:
		struct Empty;

		Any() : policy(selectPolicy<Empty>()), storage(nullptr)
		{
		}
		template <typename T>
		explicit Any(const T& v) : policy(selectPolicy<T>()), storage(nullptr)
		{
			policy->set(&storage, &v);
		}
		Any(const Any& other) : policy(other.policy), storage(nullptr)
		{
			policy->set(&storage, other.storage);
		}
		Any& operator=(const Any& other)
		{
			//assert(policy == other.policy); 
			policy = other.policy;
			policy->set(&storage, other.storage);
			return *(this);
		}
		~Any()
		{
			policy->clear(&storage);
		}
		template <typename T>
		T& as() const
		{
			if (likely(sameType<T>()))
			{
				return *(reinterpret_cast<T*>(storage));
			} 
			throw std::exception();
		}
		template <typename T>
		inline bool sameType() const
		{
			return (policy == selectPolicy<T>());
		}
		inline bool empty() const
		{
			return (policy == selectPolicy<Empty>());
		}
	private:
		template <typename T>
		static impl::BaseAnyPolicy* selectPolicy()
		{
			typedef impl::PointerValueAnyPolicy<T> SelectedPolicy;
			static SelectedPolicy policy;
			return &policy;
		}
	private:
		impl::BaseAnyPolicy* policy;
		void* storage;
	};

	struct Any::Empty
	{
	};
}

#endif
