#pragma once

// #include "archive.h"

#include <iostream>

namespace tools {

class Buffer 
{
public:
    Buffer(const char * buffer, int size);
    Buffer(int size, char c = '\0');
    Buffer();
    Buffer(const Buffer& o);
    ~Buffer();

    int length() { return len; }
    const char * buffer() { return data; }
    bool isEmpty();

    void assign(const char * data, int len);
    void assign(int size, char c = '\0');

    void append(const char* data, int size);
    void erase_before(int offset);

    char& at(int offset);
    char& operator[](int offset);
    operator char*() { return data; }
    Buffer& operator=(const Buffer& o);
    Buffer& operator=(const Buffer* o);

    int     mArgN;
    long    mArgL;
    void*   mArgP;

private:
    int     len;
    char*   data;
};

} // namespace tools

#ifdef __TOOLS_ARCHIVE__
Archive& operator<<(Archive& ar, tools::Buffer& buf);
Archive& operator>>(Archive& ar, tools::Buffer& buf);
#endif

std::ostream& operator<<(std::ostream& o, tools::Buffer& ub);









