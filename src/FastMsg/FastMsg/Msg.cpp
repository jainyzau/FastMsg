#include "Msg.h"

std::string Msg::get( const char* aField, size_t aLen )
{
	while(aLen > 0 && *aField++ == ' ') --aLen;
	if (aLen > 0)
	{
		return std::string(aField - 1, aLen);
	}
	else
	{
		return "";
	}
}

void Msg::set( char* aField, size_t aLen, const std::string& aValue )
{
	memcpy(aField, aValue.c_str(), aLen);
}

std::string Msg::self_to_s(const char* aMsg, const Field* aFields)
{
	std::string lRet;
	size_t lOffset = 0;
	for (int i = 0; aFields[i].m_Len != 0; ++i)
	{
		const Field& lField = aFields[i];
		lRet += lField.m_Name + "[" 
			+ Msg::get(aMsg + lOffset, lField.m_Len) + "]";
		lOffset += lField.m_Len;
	}

	return lRet;
}