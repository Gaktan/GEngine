#include "precomp.h"

#include "io/file.h"

#include <iostream>
#include <fstream>

GBeginNameSpace()

gUInt file_size(const gString &path)
{
	std::ifstream file(path.c_str(), std::ios::binary);

	assertWithMessage(file.is_open(), stringFormat("ERROR! Trying to open inexistent file '%s'.", path.c_str()));

	std::streampos begin, end;

	begin = file.tellg();
	file.seekg(0, std::ios::end);
	end = file.tellg();
	file.close();

	return end - begin;
}

void file_read(const gString& path, const gUInt size, gVector<gByte> &array)
{
	std::ifstream  file(path.c_str(), std::ios::binary);

	assertWithMessage(file.is_open(), stringFormat("ERROR! Trying to open inexistent file '%s'.", path.c_str()));

	file.seekg(0, std::ios::beg);
	file.read(&array[0], size);

	file.close();
}


GEndNameSpace()
