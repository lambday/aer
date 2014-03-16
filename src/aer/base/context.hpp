#ifndef AER_BASE_CONTEXT_H_
#define AER_BASE_CONTEXT_H_

#include <aer/util/any.hpp>
#include <aer/util/d_ptr.hpp>
#include <aer/util/as.hpp>
#include <aer/base/tag.hpp>

#include <string>

namespace aer
{
	class Context : public EnableSelf<Context>
	{
	public:
		Context();
		~Context();
		template <typename T>
		inline Tag<T> tag_for(const std::string& name)
		{
			const Any tag = anytag(name);
			return tag.as<Tag<T>>();
		}
	protected:
		Any anytag(const std::string& name) const;

	private:
		struct Private;
		DPtr<Private> m_implementation;
	};
}

#endif
