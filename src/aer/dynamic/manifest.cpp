#include <aer/dynamic/manifest.hpp>

#include <unordered_map>

namespace aer
{

	class Manifest::Self
	{
		public:
			std::string description;
			std::unordered_map<std::string, Any> classes;
	};

	Manifest::Manifest(const std::string& description, 
			const std::initializer_list<std::pair<std::string,Any>> classes) :
		self()
	{
		self->description = description;
		for (const auto& m : classes) 
			addClass(m.first, m.second);
	}

	Manifest::Manifest(const Manifest& other) : 
		self()
	{
		self->description = other.self->description;
		self->classes = other.self->classes;
	}

	Manifest::~Manifest()
	{
	}

	std::string Manifest::description() const
	{
		return self->description;
	}

	void Manifest::addClass(const std::string& name, Any clazz)
	{
		self->classes[name] = clazz;
	}

	Any Manifest::findClass(const std::string& name) const
	{
		if (!self->classes.count(name))
			throw std::logic_error("Haven't found metaclass named " + name);
		return self->classes.at(name);
	}

}

