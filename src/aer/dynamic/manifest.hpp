#ifndef AER_DYNAMIC_MANIFEST_H_
#define AER_DYNAMIC_MANIFEST_H_

#include <aer/dynamic/metaclass.hpp>

#include <aer/util/implementation_ptr.hpp>

namespace aer
{

	class Manifest 
	{
		public:
			Manifest();
			Manifest(const Manifest& other);
			~Manifest();
			template <typename T>
			Metaclass<T> metaclass(const std::string& name)
			{
				return Metaclass<T>();
			}
		protected:
			struct ManifestImplementation;
		private:
			implementation_ptr<ManifestImplementation> m_implementation;
	};

}

#endif

