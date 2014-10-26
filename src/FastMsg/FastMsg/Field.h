#ifndef _FIELD_H_
#define _FIELD_H_
#include <string>
#include "FieldMeta.h"
#include "Msg.h"

template<size_t FieldLen, FieldValueAlign Align = AlignRight, char Padding = ' '>
class Field
{
public:

	std::string get() const;
	void set(const std::string aValue);
	char value[FieldLen];

	static const size_t _FieldLen = FieldLen;
	static const FieldValueAlign _Align = Align;
	static const char _Padding = Padding;
};

template<size_t FieldLen, FieldValueAlign Align, char Padding>
void Field<FieldLen, Align, Padding>::set( const std::string aValue )
{
	Msg::set_field(value, FieldLen, aValue, Align, Padding);
}
template<size_t FieldLen, FieldValueAlign Align, char Padding>
std::string Field<FieldLen, Align, Padding>::get() const
{
	return Msg::get_field(value, _FieldLen, _Align, _Padding);
}

#endif