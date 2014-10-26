#ifndef _FIELD_H_
#define _FIELD_H_
#include <string>
struct Field
{
	Field(const std::string aName, size_t aLen): m_Name(aName), m_Len(aLen){}
	std::string m_Name;
	size_t m_Len;
};
#endif