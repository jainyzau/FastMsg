#include "Msg.h"
#include "MsgInitInc.h"

FieldMeta Msg::_fields[] = {
	MsgHeaderFields
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
			+ BasicField::get_field(aMsg + lOffset, lField.m_Len) + "]";
		lOffset += lField.m_Len;
	}

	return lRet;
}