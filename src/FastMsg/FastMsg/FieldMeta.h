#ifndef _FIELD_META_H_
#define _FIELD_META_H_
#include <string>

enum FieldValueAlign
{
	AlignLeft,
	AlignRight,		
};

struct FieldMeta
{
	FieldMeta(const std::string aName, size_t aLen, FieldValueAlign aAlign = AlignRight, char aPadding = ' ')
		: m_Name(aName)
		, m_Len(aLen)
		, m_Align(aAlign)
		, m_Padding(aPadding)
	{}
	std::string m_Name;
	size_t m_Len;
	FieldValueAlign m_Align;
	char m_Padding;
};
#endif