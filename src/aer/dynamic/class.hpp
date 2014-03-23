#ifndef AER_DYNAMIC_CLASS_H_
#define AER_DYNAMIC_CLASS_H_

#include <aer/base/object.hpp>
#include <aer/util/d_ptr.hpp>
#include <aer/util/as.hpp>

#include <memory>

namespace aer
{

	/** @brief 
	 * 
	 *
	 */
	template <typename T>
	class Class
	{
		typedef std::function<As<T>()> SpawnFunction;
		public:
			Class(Any sf) : 
				spawn_function(recall_type<SpawnFunction>(sf))
			{
			}
			Class(const Class<T>& other) :
				spawn_function(other.spawn_function)
			{
			}
			~Class()
			{
			}
			As<T> instance() const
			{
				return spawn_function();
			}
		private:
			const SpawnFunction spawn_function;
	};

}

#endif
