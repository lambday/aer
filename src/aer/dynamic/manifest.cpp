#include <aer/dynamic/manifest.hpp>

namespace aer
{

	struct Manifest::ManifestImplementation
	{

	};

	Manifest::Manifest() : m_implementation(new ManifestImplementation)
	{
	}

	Manifest::Manifest(const Manifest& other) : m_implementation(new ManifestImplementation)
	{
	}

	Manifest::~Manifest()
	{
	}

}

