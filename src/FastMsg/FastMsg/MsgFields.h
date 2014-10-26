#ifndef _MSG_FIELDS_H_
#define _MSG_FIELDS_H_

#define MsgHeaderFields					\
	MsgField(MsgType, 6)				\
	MsgField(MsgLen ,8)

#define MsgAdminFields					\
	MsgField(ExchangeCode, 1)			\
	MsgField(MarketCode, 2)				\
	MsgField(VirtualServerNo, 6)		


#define MsgNewOrderFields					\
	MsgFieldEx(Price, 14, AlignRight, '0')


#define MsgOperationStartFields			\
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