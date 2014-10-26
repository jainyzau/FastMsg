#ifndef _MSG_DEF_H_
#define _MSG_DEF_H_
#include <string>
#include "Msg.h"
#include "field.h"

#define MsgField(Name, Len) char Name[Len];

#define DefineMsg(aMsgName, aMsgBase)																	\
class aMsgName: public aMsgBase																			\
{																										\
public:																									\
	aMsgName() { memset(this, 0x20, sizeof(aMsgName));}													\
	std::string to_s() const { return aMsgBase::to_s() + Msg::self_to_s((const char*)this, _fields); }	\
	aMsgName##Fields;																					\
private:																								\
	static Field _fields[];																				\
};

#define MsgInit(aMsgName)				\
	Field aMsgName::_fields[] = {		\
	aMsgName##Fields					\
	MsgField(MsgEndTag, 0)				\
	};

DefineMsg(MsgAdmin, Msg);
DefineMsg(MsgOperationStart, MsgAdmin);
DefineMsg(MsgTest, MsgOperationStart);
#endif