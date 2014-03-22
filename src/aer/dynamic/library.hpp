#ifndef AER_DYNAMIC_LIBRARY_H_
#define AER_DYNAMIC_LIBRARY_H_

#include <aer/dynamic/manifest.hpp>

#include <string>
#include <dlfcn.h>
#include <iostream>

namespace aer
{

	class LibraryHandle;

	class Library
	{
		public:
			static const char* manifest_accessor_name;
		public:
			Library(const std::string& filename);
			Library(const Library& other);
			Library& operator=(const Library& other);
			~Library();
			Manifest manifest();
		private:
			As<LibraryHandle> m_handle;
	};

	Library loadLibrary(const std::string& filename);

}

#endif
