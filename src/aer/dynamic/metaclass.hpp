#ifndef AER_DYNAMIC_METACLASS_H_
#define AER_DYNAMIC_METACLASS_H_

#include <aer/base/object.hpp>
#include <aer/util/d_ptr.hpp>
#include <aer/util/as.hpp>

#include <memory>

namespace aer
{

	class Manifest;

	template <typename T>
	class Metaclass
	{
		public:
			Metaclass(As<Manifest> manifest) : m_manifest(manifest)
			{
			}
			Metaclass(const Metaclass<T>& other) : m_manifest(other.m_manifest)
			{
			}
			~Metaclass()
			{
			}
			As<T> instance() const
			{
				return As<T>(new T());
			}
		private:
			As<Manifest> m_manifest;
	};

}

#endif
