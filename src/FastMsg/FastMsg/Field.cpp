#include "Field.h"
#include <cstring>

std::string BasicField::get_field( const char* aField, size_t aLen, FieldValueAlign aAlign /*= AlignRight*/, char aPadding /*= ' ' */ )
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

void BasicField::set_field( char* aField, size_t aLen, const std::string& aNewValue, FieldValueAlign aAlign /*= AlignRight*/, char aPadding /*= ' '*/ )
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

Slice BasicField::get_field_s( const char* aField, size_t aLen, FieldValueAlign aAlign /*= AlignRight*/, char aPadding /*= ' ' */ )
{
	if (aAlign == AlignRight)
	{
		const char* p = aField;
		while(aLen > 0 && *p++ == aPadding) --aLen;
		if (aLen > 0)
		{
			return Slice(p-1, aLen);
		}
	}
	else
	{
		const char* p = aField + aLen - 1;
		while (aLen > 0 && *p-- == aPadding) --aLen;
		if (aLen > 0)
		{
			return Slice(aField, aLen);
		}
	}

	return Slice();
}