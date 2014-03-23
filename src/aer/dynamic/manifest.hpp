#ifndef AER_DYNAMIC_MANIFEST_H_
#define AER_DYNAMIC_MANIFEST_H_

#include <aer/dynamic/metaclass.hpp>

#include <aer/util/d_ptr.hpp>
#include <aer/util/as.hpp>

#include <iostream>
#include <vector>

namespace aer
{

	class Library;

	class Manifest
	{
		public:
			Manifest(const std::string& description, const std::initializer_list<std::pair<std::string,Any>> metaclasses);
			Manifest(const Manifest& other);
			~Manifest();
			template <typename T>
			Metaclass<T> metaclass(const std::string& name) const
			{
				Any metaclass = findMetaclass(name);
				return recall_type<Metaclass<T>>(metaclass);
			}
			std::string description() const;
		protected:
			void addMetaclass(const std::string& name, Any metaclass);
			Any findMetaclass(const std::string& name) const;
		private:
			struct Self;
			DPtr<Self> self;
	};

#define AER_BEGIN_MANIFEST(DESCRIPTION)								\
extern "C" aer::Manifest aerManifest()								\
{																	\
	static aer::Manifest manifest(DESCRIPTION,{						\

#define AER_EXPORT(CLASSNAME, BASE_CLASSNAME, IDENTIFIER)			\
	std::make_pair(IDENTIFIER, aer::erase_type(						\
		aer::Metaclass<BASE_CLASSNAME>(aer::erase_type(				\
			std::function<aer::As<BASE_CLASSNAME>()>(				\
				[]() -> aer::As<BASE_CLASSNAME>						\
				{													\
					return aer::As<BASE_CLASSNAME>(new CLASSNAME);	\
				}													\
				))))),												\

#define AER_END_MANIFEST()											\
		});															\
	return manifest;												\
}

}

#endif

