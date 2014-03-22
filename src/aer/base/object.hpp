#ifndef AER_BASE_OBJECT_H_
#define AER_BASE_OBJECT_H_

#include <aer/base/tag.hpp>
#include <aer/base/type.hpp>
#include <aer/base/context.hpp>
#include <aer/util/any.hpp>
#include <aer/util/d_ptr.hpp>
#include <aer/util/as.hpp>

#include <type_traits>
#include <unordered_map>

namespace aer
{

	class Object
	{
	public:
		Object();
		Object(const Object& other);
		~Object();

		template <typename T>
		inline void set(const Tag<T>& tag, const T& value)
		{
			set(tag.id(), erase_type(value));
		}

		template <typename T>
		inline T get(const Tag<T>& tag) const
		{
			const Any value = get(tag.id());
			return recall_type<T>(value);
		}

		template <typename T>
		inline void set(const std::string& name, const T& value)
		{
			set(tag<T>(name).id(), erase_type(value));
		}

		template <typename T>
		inline T get(const std::string& name, const Type<T>& type) const
		{
			const Any value = get(tag<T>(name).id());
			return recall_type<T>(value);
		}
	
	protected:

		virtual void fire_updated(int tag_id) 
		{
		};

		template<typename T>
		inline Tag<T> tag(const std::string& name) const
		{
		//	return m_context->tag_for<T>(name);
		}

		void set(int tag_id, const Any& any);
		Any get(int tag_id) const;

	protected:
	private:
		class Self;
		DPtr<Self> self;
	};
}

#endif
