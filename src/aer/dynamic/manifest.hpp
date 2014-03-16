#ifndef AER_DYNAMIC_MANIFEST_H_
#define AER_DYNAMIC_MANIFEST_H_

#include <aer/dynamic/metaclass.hpp>

#include <aer/util/d_ptr.hpp>

namespace aer
{

	class Library;

	class Manifest : public EnableSelf<Manifest>
	{
		public:
			Manifest();
			Manifest(const Manifest& other);
			~Manifest();
			template <typename T>
			As<Metaclass<T>> metaclass(const std::string& name)
			{
				Metaclass<T>* metaclass = nullptr;
				return As<Metaclass<T>>(metaclass);
			}
		private:
			struct Private;
			DPtr<Private> m_implementation;
	};

}

#endif

