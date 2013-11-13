#ifndef TestWithStdIO_H
#define TestWithStdIO_H
#include <cstdio>
#include <fstream>
#include <iostream>

class TestWithStdIO {
        std::streambuf *cinbuf;
        std::streambuf *coutbuf;
        std::ifstream inStream;
        std::ofstream outStream;
    public:
        TestWithStdIO(const char* inFile, const char* outFile);
        ~TestWithStdIO();
};
#endif
