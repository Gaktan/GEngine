#ifndef __IO__FILE__H__
#define __IO__FILE__H__

GBeginNameSpace()

ui32 file_size(const string &path);

void file_read(const string& path, const ui32 size, vector<byte> &byte_array);

GEndNameSpace()

#endif //__IO__FILE__H__
