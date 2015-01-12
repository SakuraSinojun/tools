#pragma once

// #include "archive.h"

#include <iostream>
#include "serialize/archive.h"

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

    char& at(int offset);
    char& operator[](int offset);
    operator char*() { return data; }
    operator void*() { return data; }
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

Archive& operator<<(Archive& ar, tools::Buffer& buf);
Archive& operator>>(Archive& ar, tools::Buffer& buf);

std::ostream& operator<<(std::ostream& o, tools::Buffer& ub);









