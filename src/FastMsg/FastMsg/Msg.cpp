#include "Msg.h"

std::string Msg::self_to_s(const char* aMsg, const FieldMeta* aFields)
{
	std::string lRet;
	size_t lOffset = 0;
	
	for (int i = 0; aFields[i].m_Len != 0; ++i)
	{
		const FieldMeta& lField = aFields[i];
		lRet += lField.m_Name + "[" 
			+ Msg::get_field(aMsg + lOffset, lField.m_Len) + "]";
		lOffset += lField.m_Len;
	}

	return lRet;
}

std::string Msg::get_field( const char* aField, size_t aLen, FieldValueAlign aAlign /*= AlignRight*/, char aPadding /*= ' ' */ )
{
	std::string lField;
	if (aAlign == AlignRight)
	{
		const char* p = aField;
		while(aLen > 0 && *p++ == aPadding) --aLen;
		if (aLen > 0)
		{
			lField.assign(p - 1, aLen);
		}
	}
	else
	{
		const char* p = aField + aLen - 1;
		while (aLen > 0 && *p-- == aPadding) --aLen;
		if (aLen > 0)
		{
			lField.assign(aField, aLen);
		}
	}

	return lField;
}

void Msg::set_field( char* aField, size_t aLen, FieldValueAlign aAlign /*= AlignRight*/, char aPadding /*= ' '*/ )
{

}