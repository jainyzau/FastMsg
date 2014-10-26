#ifndef _MSG_H_
#define _MSG_H_
#include "FieldMeta.h"

class Msg
{
public:
	std::string to_s() const { return ""; };	
	static std::string self_to_s(const char* aMsg, const FieldMeta* aFields);
	static std::string get_field( const char* aField, size_t aLen, FieldValueAlign aAlign = AlignRight, char aPadding = ' ' );
	static void set_field( char* aField, size_t aLen, FieldValueAlign aAlign = AlignRight, char aPadding = ' ');
};

#define MsgDefine(aMsgName, aMsgBase)																	\
class aMsgName: public aMsgBase																			\
{																										\
public:																									\
	aMsgName() { memset(this, 0x20, sizeof(aMsgName));}													\
	std::string to_s() const { return aMsgBase::to_s() + Msg::self_to_s((const char*)this, _fields); }	\
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