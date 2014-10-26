#include "Msg.h"
#include "Slice.h"
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

		/*
		lRet.append(lField.m_Name);
		lRet.append("[");
		lRet.append(BasicField::get_field(aMsg + lOffset, lField.m_Len, lField.m_Align, lField.m_Padding));
		lRet.append("]");
		lOffset += lField.m_Len;
		*/
		
		lRet.append(lField.m_Name);
		lRet.append("[");
		Slice lSlice = BasicField::get_field_s(aMsg + lOffset, lField.m_Len, lField.m_Align, lField.m_Padding);
		lRet.append(lSlice.data, lSlice.len);
		lRet.append("]");

		lOffset += lField.m_Len;
		
	}

	return lRet;
}