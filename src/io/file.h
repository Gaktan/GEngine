#ifndef __IO__FILE__H__
#define __IO__FILE__H__

GBeginNameSpace()

ui32 file_size(const String &path);

void file_read(const String& path, const ui32 size, Vector<byte> &byte_array);

GEndNameSpace()

#endif //__IO__FILE__H__
