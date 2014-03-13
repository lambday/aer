#ifndef AER_BASE_CONTEXT_H_
#define AER_BASE_CONTEXT_H_

#include <aer/util/any.hpp>
#include <aer/base/tag.hpp>

#include <string>
#include <unordered_map>

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
		ContextImplementation* m_implementation;
	};
}

#endif
