#include <aer/base/context.hpp>

#include <unordered_map>

namespace aer
{
	/** @brief
	 *
	 */
	struct Context::ContextImplementation
	{
		std::unordered_map<std::string, Any> m_tags;
	};
}

