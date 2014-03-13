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
		
		inline int id() const
		{
			return m_id;
		}

		inline std::string name() const
		{
			return m_name;
		}

	private:
		std::string m_name;
		int m_id;
	};
}

#endif

