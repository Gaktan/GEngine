#ifndef __ENGINE__SINGLETON__H__
#define __ENGINE__SINGLETON__H__

GBeginNameSpace()

template<class S>
class Singleton
{
protected:
	Singleton() {};
	Singleton(const S &other) = delete;
	virtual ~Singleton() {};

	void operator = (const S&) = delete;

public:

	static S& GetInstance()
	{
		static S instance;
		return instance;
	};
};

GEndNameSpace()

#endif // __ENGINE__SINGLETON__H__
