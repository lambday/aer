#ifndef AER_DYNAMIC_SYMBOL_H_
#define AER_DYNAMIC_SYMBOL_H_

namespace aer
{
	class Symbol
	{
	private:
		Symbol& operator=(const Symbol& other);

	public:
		Symbol(void* symbol) : m_symbol(symbol)
		{
		}
		Symbol(const Symbol& other)
		{
			m_symbol = other.m_symbol;
		}
		inline bool ready() 
		{
			return m_symbol;
		}
		inline void* unsafeCall()
		{
			void* (*symbol_ptr)();
			*(void**)(&symbol_ptr) = m_symbol;
			return (*symbol_ptr)();
		}
	private:
		void* m_symbol;
	};
}

#endif
