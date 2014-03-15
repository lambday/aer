#ifndef AER_DYNAMIC_LIBRARY_H_
#define AER_DYNAMIC_LIBRARY_H_

#include <aer/dynamic/manifest.hpp>

#include <string>
#include <dlfcn.h>

namespace aer
{
	class LibraryHandle
	{
	public:
		LibraryHandle(const std::string& filename)
		{
			handle = dlopen(filename.c_str(), RTLD_LAZY);
		}
		~LibraryHandle()
		{
			if (handle)
			{
				dlclose(handle);
			}
		}
	private:
		void* handle;
	};

	class Library
	{
		public:
			Library(const std::string& filename);
			~Library();
			Manifest manifest() const;
		private:
			std::shared_ptr<LibraryHandle> m_handle;
	};
}

#endif
