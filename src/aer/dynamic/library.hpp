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
			Library(const std::string& filename);
			~Library();
			As<Manifest> manifest();
		private:
			std::shared_ptr<LibraryHandle> m_handle;
	};

	As<Library> loadLibrary(const std::string& filename);

}

#endif
