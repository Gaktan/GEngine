#ifndef __IO__FILE__H__
#define __IO__FILE__H__

GBeginNameSpace()

gUInt file_size(const gString &path);

void file_read(const gString& path, const gUInt size, gVector<gByte> &array);

GEndNameSpace()

#endif //__IO__FILE__H__
