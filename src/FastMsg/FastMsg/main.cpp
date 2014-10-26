#include "MsgDef.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int main()
{

	cout << "Msg Size:" << sizeof(Msg) << endl;
	cout << "MsgAdmin Size:" << sizeof(MsgAdmin) << endl;
	cout << "MsgOperationStart Size:" << sizeof(MsgOperationStart) << endl;
	cout << "MsgNewOrder Size:" << sizeof(MsgNewOrder) << endl;
	cout << "======================" << endl;

	MsgAdmin lMsgAdmin;
	lMsgAdmin.MsgType.set("Admin");
	lMsgAdmin.MsgLen.set("14");

	cout << lMsgAdmin.to_s() << endl;
	cout << "======================" << endl;

	MsgOperationStart lMsgOperationStart;
	lMsgOperationStart.MsgType.set("OperSt");
	lMsgOperationStart.MsgLen.set("69");
	lMsgOperationStart.VirtualServerNo.set("J61A0G");
	lMsgOperationStart.ARNSeqNo.set("3");
	lMsgOperationStart.ERNSeqNo.set("2");
	lMsgOperationStart.ProxyVirtualServerNo_1.set("J61A0H");
	lMsgOperationStart.ProxyARNSeqNo_1.set("4");
	lMsgOperationStart.ProxyERNSeqNo_1.set("5");

	cout << lMsgOperationStart.to_s() << endl;
	cout << "======================" << endl;


	MsgNewOrder lMsgNewOrder;
	lMsgNewOrder.MsgType.set("A111");
	lMsgNewOrder.MsgLen.set("37");
	lMsgNewOrder.ExchangeCode.set("1");
	lMsgNewOrder.MarketCode.set("11");
	lMsgNewOrder.VirtualServerNo.set("J61A0H");
	lMsgNewOrder.Price.set("199999999");
	cout << lMsgNewOrder.to_s() << endl;

	time_t lTime;
	time(&lTime);
	cout << lTime << endl;
	for(int i = 0; i < 1000000; ++i)
	{
		lMsgNewOrder.to_s();
	}

	time(&lTime);
	cout << lTime << endl;
	cout << std::string((const char*)&lMsgNewOrder, sizeof(lMsgNewOrder)) << endl;


	return 0;
}