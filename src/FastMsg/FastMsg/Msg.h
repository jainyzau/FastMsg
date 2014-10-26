#ifndef _MSG_H_
#define _MSG_H_
#include "Field.h"

#define MsgAdminFields			\
	MsgField(MsgType, 6)		\
	MsgField(MsgLen, 8)		

#define MsgTestFields			\
	MsgField(MsgType2, 6)		\
	MsgField(MsgLen2, 8)		\
	MsgField(Ms, 2)

#define MsgTest2Fields	\
	MsgField(F1, 2)

#define MsgOperationStartFields			\
	MsgField(VirtualServerNo, 6)		\
	MsgField(ARNSeqNo, 8)				\
	MsgField(ERNSeqNo, 8)				\
	MsgField(ProxyVirtualServerNo_1, 6)	\
	MsgField(ProxyARNSeqNo_1, 8)		\
	MsgField(ProxyERNSeqNo_1, 8)		\
	MsgField(ProxyVirtualServerNo_2, 6)	\
	MsgField(ProxyARNSeqNo_2, 8)		\
	MsgField(ProxyERNSeqNo_2, 8)		\
	MsgField(ProxyVirtualServerNo_3, 6)	\
	MsgField(ProxyARNSeqNo_3, 8)		\
	MsgField(ProxyERNSeqNo_3, 8)	

class Msg
{
public:
	std::string to_s() const { return ""; };	
	static std::string get(const char* aField, size_t aLen);
	static void set(char* aField, size_t aLen, const std::string& aValue);
	static std::string self_to_s(const char* aMsg, const Field* aFields);
};

#define MsgSetField(aField, aValue) Msg::set(aField, sizeof(aField), aValue)
#define MsgGetField(aField) Msg::get(aField, sizeof(aField))
#endif