#include <aer/base/object.hpp>

#include <unordered_map>
#include <iostream>

namespace aer
{
	/** @brief
	 *
	 */
	struct Object::Self
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

	Object::Object() : self()
	{
	}

	Object::Object(const Object& other) : self()
	{
	}

	Object::~Object()
	{
	}

	void Object::set(int tag_id, const Any& any)
	{
		self->set(tag_id, any);
		fire_updated(tag_id);
	}

	Any Object::get(int tag_id) const
	{
		return self->get(tag_id);
	}

}
