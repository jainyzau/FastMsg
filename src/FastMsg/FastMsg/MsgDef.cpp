#include "MsgDef.h"

#define MsgField(Name, Len) FieldMeta(#Name, Len),
#define MsgFieldEx(Name, Len, Align, Padding) FieldMeta(#Name, Len, Align, Padding),

MsgInit(MsgAdmin);
MsgInit(MsgOperationStart);
MsgInit(MsgNewOrder);
