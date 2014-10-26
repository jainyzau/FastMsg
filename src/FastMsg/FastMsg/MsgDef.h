#ifndef _MSG_DEF_H_
#define _MSG_DEF_H_
#include "Msg.h"
#include "Field.h"
#include "MsgFields.h"
#include "MsgDefineInc.h"

MsgDefine(MsgAdmin, Msg);
MsgDefine(MsgOperationStart, MsgAdmin);
MsgDefine(MsgNewOrder, MsgAdmin);

#endif