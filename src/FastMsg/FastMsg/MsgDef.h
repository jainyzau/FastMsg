#ifndef _MSG_DEF_H_
#define _MSG_DEF_H_
#include "Msg.h"
#include "Field.h"
#include "MsgFields.h"

#define MsgField(Name, Len) Field<Len> Name;
#define MsgFieldEx(Name, Len, Align, Padding) Field<Len, Align, Padding> Name;

MsgDefine(MsgAdmin, Msg);
MsgDefine(MsgOperationStart, MsgAdmin);
MsgDefine(MsgNewOrder, MsgAdmin);

#endif