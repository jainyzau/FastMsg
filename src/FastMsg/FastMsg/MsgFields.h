#ifndef _MSG_FIELDS_H_
#define _MSG_FIELDS_H_

#define MsgAdminFields			\
	MsgField(MsgType, 6)		\
	MsgField(MsgLen, 8)		

#define MsgNewOrderFields					\
	MsgFieldEx(Price, 14, AlignLeft, '0')


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

#endif