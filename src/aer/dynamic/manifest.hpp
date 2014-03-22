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
			Metaclass<T> metaclass(const std::string& name)
			{
				Any metaclass = findMetaclass(name);
				return recall_type<Metaclass<T>>(metaclass);
			}
			std::string description() const;
		protected:
			void addMetaclass(const std::string& name, Any metaclass);
			Any findMetaclass(const std::string& name);
		private:
			struct Self;
			DPtr<Self> self;
	};

}

#endif

