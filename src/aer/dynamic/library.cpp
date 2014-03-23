#include <aer/dynamic/library.hpp>

namespace aer
{
	class LibraryHandle
	{
	public:
		LibraryHandle(const std::string& filename)
		{
			handle = dlopen(filename.c_str(), RTLD_NOW | RTLD_LOCAL);
			if (handle) 
			{
				std::cout << "Loaded\n";
			}
			else
			{
				std::cout << "Failed: " << dlerror() << "\n";
			}
		}
		~LibraryHandle()
		{
			if (handle)
			{
				std::cout << "Closing library\n";
				dlclose(handle);
			}
		}
		template <typename T>
		T call(const std::string& name)
		{
			T (*fm)();
			*(void**)(&fm) = dlsym(handle, name.c_str());
			if (!fm) 
				throw std::logic_error("Haven't found method " + name);
			return fm();
		}
	private:
		void* handle;
	};

	Library::Library(const std::string& filename) : 
		m_handle(std::make_shared<LibraryHandle>(filename))
	{
	}

	Library::~Library()
	{
	}

	Manifest Library::manifest()
	{
		return m_handle->call<Manifest>(manifest_accessor_name);
	}

	Library loadLibrary(const std::string& filename)
	{
		return Library(filename);
	}

	const char* Library::manifest_accessor_name = "aerManifest";

}
