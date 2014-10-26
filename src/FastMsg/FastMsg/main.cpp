#include "MsgDef.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	MsgAdmin lMsgAdmin;
	lMsgAdmin.MsgType.set(" Admin");
	lMsgAdmin.MsgLen.set("      14");

	cout << lMsgAdmin.to_s() << endl;
	cout << lMsgAdmin.MsgType.get() << endl;

	MsgOperationStart lMsgOperationStart;
	lMsgOperationStart.MsgType.set("OperSt");
	lMsgOperationStart.MsgLen.set("      69");
	lMsgOperationStart.VirtualServerNo.set("J61A0G");
	lMsgOperationStart.ARNSeqNo.set("00000003");
	lMsgOperationStart.ERNSeqNo.set("00000002");
	lMsgOperationStart.ProxyVirtualServerNo_1.set("J61A0H");
	lMsgOperationStart.ProxyARNSeqNo_1.set("00000004");
	lMsgOperationStart.ProxyERNSeqNo_1.set("00000005");

	cout << lMsgOperationStart.to_s() << endl;

	cout << sizeof(MsgOperationStart) << endl;
	cout << sizeof(lMsgAdmin) << endl;

	MsgNewOrder lMsgNewOrder;
	lMsgNewOrder.Price.set("199999999.0000");
	cout << lMsgNewOrder.Price.get() << endl;
	cout << sizeof(MsgNewOrder) << endl;


	return 0;
}