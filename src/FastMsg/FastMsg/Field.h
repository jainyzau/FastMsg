#ifndef _FIELD_H_
#define _FIELD_H_
#include <string>
#include "FieldMeta.h"

class BasicField
{
public:
	static std::string get_field( const char* aField, size_t aLen, FieldValueAlign aAlign = AlignRight, char aPadding = ' ' );
	static void set_field( char* aField, size_t aLen, const std::string& aNewValue, FieldValueAlign aAlign = AlignRight, char aPadding = ' ');
};

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
	BasicField::set_field(value, FieldLen, aValue, Align, Padding);
}
template<size_t FieldLen, FieldValueAlign Align, char Padding>
std::string Field<FieldLen, Align, Padding>::get() const
{
	return BasicField::get_field(value, _FieldLen, _Align, _Padding);
}

#endif