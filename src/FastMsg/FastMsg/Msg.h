#ifndef _MSG_H_
#define _MSG_H_
#include "FieldMeta.h"
#include "Field.h"
#include "MsgFields.h"
#include "MsgDefineInc.h"

class Msg
{
public:
	std::string to_s() const { return self_to_s((const char*)this, _fields); };	
	static std::string self_to_s(const char* aMsg, const FieldMeta* aFields);

	MsgHeaderFields
	static FieldMeta _fields[];
};

#define MsgDefine(aMsgName, aMsgBase)																	\
class aMsgName: public aMsgBase																			\
{																										\
public:																									\
	aMsgName() { memset(this, 0x20, sizeof(aMsgName));}													\
	std::string to_s() const { return aMsgBase::to_s() + Msg::self_to_s((const char*)this + sizeof(aMsgBase), _fields); }	\
	aMsgName##Fields;																					\
private:																								\
	static FieldMeta _fields[];																			\
};

#define MsgInit(aMsgName)					\
	FieldMeta aMsgName::_fields[] = {		\
	aMsgName##Fields						\
	MsgField(MsgEndTag, 0)					\
};
#endif