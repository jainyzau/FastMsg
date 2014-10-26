#ifndef _TEST_FIELD_H_
#define _TEST_FIELD_H_
#include <string>

enum FieldValueAlign
{
	AlignLeft,
	AlignRight,		
};

template<size_t FieldLen>
class FieldEx
{
public:

	std::string get(FieldValueAlign aAlign = AlignRight, char aPadding = ' ') const;
	void set(const std::string aValue);
	char value[FieldLen];
	static const size_t _FieldLen = FieldLen;
};

template<size_t FieldLen>
void FieldEx<FieldLen>::set( const std::string aValue )
{
	memcpy(value, aValue.c_str(), FieldLen);
}
template<size_t FieldLen>
std::string FieldEx<FieldLen>::get(FieldValueAlign aAlign, char aPadding = ' ') const
{
	if (aAlign == AlignRight)
	{
		const char* p = value;
		size_t len = _FieldLen;
		while(len > 0 && *p++ == ' ') --len;
		if (len > 0)
		{
			return std::string(p - 1, len);
		}
		else
		{
			return "";
		}
	}
	return "";
}
class MsgTest3
{
public:
	FieldEx<6> m_MsgType;
	FieldEx<8> m_MsgLen;
};
#endif