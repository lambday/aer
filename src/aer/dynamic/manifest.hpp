#ifndef AER_DYNAMIC_MANIFEST_H_
#define AER_DYNAMIC_MANIFEST_H_

#include <aer/dynamic/class.hpp>

#include <aer/util/d_ptr.hpp>
#include <aer/util/as.hpp>

#include <iostream>
#include <vector>

namespace aer
{

	class Library;

	/** @brief Manifest is an object that stores metadata of library.
	 * Each manifest has description and a set of metaclasses 
	 * (see @ref aer::Metaclass) which are responsible for 
	 * creating instances of exported classes.
	 */
	class Manifest
	{
		public:
			Manifest(const std::string& description, const std::initializer_list<std::pair<std::string,Any>> metaclasses);
			Manifest(const Manifest& other);
			~Manifest();

			/** Returns class by its name.
			 *
			 * @param name the name of the metaclass to obtain
			 * @return 
			 * @throw
			 */
			template <typename T>
			Class<T> classByName(const std::string& name) const
			{
				Any clazz = findClass(name);
				return recall_type<Class<T>>(clazz);
			}

			/** Returns description stored in the manifest.
			 */
			std::string description() const;
		protected:
			void addClass(const std::string& name, Any clazz);
			Any findClass(const std::string& name) const;
		private:
			struct Self;
			DPtr<Self> self;
	};

/** Starts manifest declaration with its description. 
 * Always immediately follow this macro with 
 * @ref AER_EXPORT or @ref AER_END_MANIFEST.
 */
#define AER_BEGIN_MANIFEST(DESCRIPTION)								\
extern "C" aer::Manifest aerManifest()								\
{																	\
	static aer::Manifest manifest(DESCRIPTION,{						\

/** Declares class to be exported.
 * Always use this macro between @ref AER_BEGIN_MANIFEST and 
 * @ref AER_END_MANIFEST
 */
#define AER_EXPORT(CLASSNAME, BASE_CLASSNAME, IDENTIFIER)			\
	std::make_pair(IDENTIFIER, aer::erase_type(						\
		aer::Class<BASE_CLASSNAME>(aer::erase_type(					\
			std::function<aer::As<BASE_CLASSNAME>()>(				\
				[]() -> aer::As<BASE_CLASSNAME>						\
				{													\
					return aer::As<BASE_CLASSNAME>(new CLASSNAME);	\
				}													\
				))))),												\

/** Ends manifest declaration.
 * Always use this macro after @ref AER_BEGIN_MANIFEST
 */
#define AER_END_MANIFEST()											\
		});															\
	return manifest;												\
}

}

#endif

