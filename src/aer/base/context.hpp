#ifndef AER_BASE_CONTEXT_H_
#define AER_BASE_CONTEXT_H_

#include <aer/util/any.hpp>
#include <aer/util/implementation_ptr.hpp>
#include <aer/base/tag.hpp>

#include <string>

namespace aer
{
	class Context
	{
	public:
		template <typename T>
		inline Tag<T> tag_for(const std::string& name)
		{
			const Any tag = anytag(name);
			return tag.as<Tag<T>>();
		}
	protected:
		Any anytag(const std::string& name) const;

		struct ContextImplementation;
	private:
		implementation_ptr<ContextImplementation> m_implementation;
	};
}

#endif
