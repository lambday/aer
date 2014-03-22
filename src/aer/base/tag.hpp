#ifndef AER_BASE_TAG_H_
#define AER_BASE_TAG_H_

#include <string>

namespace aer
{
	template <typename T>
	class Tag
	{
	public:
		typedef T type;

		Tag(const std::string& name) : 
			name_(name), id_()
		{
		}

		Tag(const Tag& other) : 
			name_(other.name_), id_(other.id_)
		{
		}

		Tag& operator=(const Tag& other)
		{
			name_ = other.name_;
			id_ = other.id_;
		}
		
		inline int id() const
		{
			return id_;
		}

		inline std::string name() const
		{
			return name_;
		}

	private:
		std::string name_;
		int id_;
	};
}

#endif

