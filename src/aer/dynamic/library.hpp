#ifndef AER_DYNAMIC_LIBRARY_H_
#define AER_DYNAMIC_LIBRARY_H_

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
		template <typename R, typename T>
		Symbol<R (const T&)> symbol(const std::string& name) const
		{
			dlsym(handle, name);
		}
	private:
		void* handle;
	}

	class Library
	{
	private:
		Library(const Library& other);
		Library(Library&& other);
		Library& operator=(const Library& other);

	public:
		Library(const std::string& filename) : m_handle(new LibraryHandle(filename))
		{
		}
		~Library()
		{
		}
	private:
		shared_ptr<LibraryHandle> m_handle;
	};
}

#endif
