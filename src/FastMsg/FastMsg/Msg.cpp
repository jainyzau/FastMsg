#include "Msg.h"

FieldMeta Msg::_fields[] = {
	FieldMeta("MsgType", 6),
	FieldMeta("MsgLen", 8),
	FieldMeta("MsgEndTag", 0)			
};

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

void Msg::set_field( char* aField, size_t aLen, const std::string& aNewValue, FieldValueAlign aAlign /*= AlignRight*/, char aPadding /*= ' '*/ )
{
	size_t lPaddingLen = aLen - aNewValue.size();
	if (lPaddingLen > 0)
	{
		if (aAlign == AlignRight)
		{
			memset(aField, aPadding, lPaddingLen);
			memcpy(aField + lPaddingLen, aNewValue.c_str(), aNewValue.size());
		}
		else
		{
			char *p = aField + aLen - 1;
			memset(p - lPaddingLen, aPadding, lPaddingLen);
			memcpy(aField, aNewValue.c_str(), aNewValue.size());
		}
	}
	else
	{
		memcpy(aField, aNewValue.c_str(), aLen);
	}
}