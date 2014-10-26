#ifndef _MSG_INIT_INC_H_
#define _MSG_INIT_INC_H_

#define MsgField(Name, Len) FieldMeta(#Name, Len),
#define MsgFieldEx(Name, Len, Align, Padding) FieldMeta(#Name, Len, Align, Padding),

#endif