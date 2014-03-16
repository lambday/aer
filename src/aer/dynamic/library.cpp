#include <aer/dynamic/library.hpp>

namespace aer
{
	class LibraryHandle
	{
	public:
		LibraryHandle(const std::string& filename)
		{
			handle = dlopen(filename.c_str(), RTLD_LAZY);
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
				dlclose(handle);
			}
		}
		template <typename T>
		std::function<T()> factoryMethod(const std::string& name)
		{
			T (*fm)();
			*(void**)(&fm) = dlsym(handle, name.c_str());
			return std::function<T()>(fm);
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

	As<Manifest> Library::manifest()
	{
		return m_handle->factoryMethod<As<Manifest>>("aerManifest")();
	}

	As<Library> loadLibrary(const std::string& filename)
	{
		return As<Library>(new Library(filename));
	}

}
