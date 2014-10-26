#ifndef _MSG_DEFINE_INC_H_
#define _MSG_DEFINE_INC_H_

#define MsgField(Name, Len) Field<Len> Name;
#define MsgFieldEx(Name, Len, Align, Padding) Field<Len, Align, Padding> Name;

#endif