#include <aer/base/object.hpp>

#include <unordered_map>
#include <iostream>

namespace aer
{
	/** @brief
	 *
	 */
	struct Object::Private
	{
		void set(int tag_id, const Any& any)
		{
			map[tag_id] = any;
		}
		Any get(int tag_id)
		{
			return map.at(tag_id);
		}
		std::unordered_map<int, Any> map;
	};

	Object::Object() : m_context(new Context()), m_implementation()
	{
	}

	Object::~Object()
	{
	}

	void Object::set(int tag_id, const Any& any)
	{
		m_implementation->set(tag_id, any);
		fire_updated(tag_id);
	}

	Any Object::get(int tag_id) const
	{
		return m_implementation->get(tag_id);
	}

}
