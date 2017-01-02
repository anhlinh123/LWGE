#ifndef __IASSERTER_H__
#define __IASSERTER_H__

#include "../types.h"
#include "../ServiceLocator.h"

#define ASSERT(condition, ...)	\
	ServiceLocator::GetAsserter()->Assert(condition, __FILE__, __LINE__, __VA_ARGS__)

class IAsserter
{
public:
	virtual ~IAsserter() {};

	virtual void Assert(bool condition, const c8* file, u32 line, const c8* message...) = 0;
};

#endif // !__IASSERTER_H__
