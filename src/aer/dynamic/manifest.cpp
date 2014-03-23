#include <aer/dynamic/manifest.hpp>

#include <unordered_map>

namespace aer
{

	class Manifest::Self
	{
		public:
			std::string description;
			std::unordered_map<std::string, Any> metaclasses;
	};

	Manifest::Manifest(const std::string& description, 
			const std::initializer_list<std::pair<std::string,Any>> metaclasses) :
		self()
	{
		self->description = description;
		for (const auto& m : metaclasses) 
			addMetaclass(m.first, m.second);
	}

	Manifest::Manifest(const Manifest& other) : 
		self()
	{
		self->description = other.self->description;
		self->metaclasses = other.self->metaclasses;
	}

	Manifest::~Manifest()
	{
	}

	std::string Manifest::description() const
	{
		return self->description;
	}

	void Manifest::addMetaclass(const std::string& name, Any metaclass)
	{
		self->metaclasses[name] = metaclass;
	}

	Any Manifest::findMetaclass(const std::string& name) const
	{
		if (!self->metaclasses.count(name))
			throw std::logic_error("Haven't found metaclass named " + name);
		return self->metaclasses.at(name);
	}

}

