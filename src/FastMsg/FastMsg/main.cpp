#include "MsgDef.h"
#include "TestField.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	MsgAdmin lMsgAdmin;
	MsgSetField(lMsgAdmin.MsgType, " Admin");
	MsgSetField(lMsgAdmin.MsgLen, "      14");

	cout << lMsgAdmin.to_s() << endl;

	MsgOperationStart lMsgOperationStart;
	MsgSetField(lMsgOperationStart.MsgType, "OperSt");
	MsgSetField(lMsgOperationStart.MsgLen, "      69");
	MsgSetField(lMsgOperationStart.VirtualServerNo, "J61A0H");
	MsgSetField(lMsgOperationStart.ARNSeqNo, "00000003");
	MsgSetField(lMsgOperationStart.ERNSeqNo, "00000002");
	MsgSetField(lMsgOperationStart.ProxyVirtualServerNo_1, "J61A0G");
	MsgSetField(lMsgOperationStart.ProxyARNSeqNo_1, "00000004");
	MsgSetField(lMsgOperationStart.ProxyERNSeqNo_1, "00000005");

	cout << lMsgOperationStart.to_s() << endl;

	cout << sizeof(MsgOperationStart) << endl;
	cout << sizeof(lMsgAdmin) << endl;
	cout << sizeof(MsgTest) << endl;
	cout << sizeof(MsgTest3) << endl;

	MsgTest3 lmt;
	
	lmt.m_MsgType.set("   mt3");
	cout << lmt.m_MsgType.get() << endl;

	return 0;
}