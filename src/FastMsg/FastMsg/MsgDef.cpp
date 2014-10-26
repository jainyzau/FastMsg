#include "MsgDef.h"

#define MsgField(Name, Len) Field(#Name, Len),

MsgInit(MsgAdmin);
MsgInit(MsgOperationStart);
MsgInit(MsgTest);
