#ifndef _SLICE_H_
#define _SLICE_H_
class Slice
{
public:
	Slice(const char* aData = NULL, size_t aLen = 0): data(aData), len(aLen) {}
	const char* data;
	size_t len;
};
#endif