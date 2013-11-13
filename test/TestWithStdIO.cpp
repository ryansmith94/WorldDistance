#include "TestWithStdIO.h"
#include <cstdio>
#include <fstream>
#include <iostream>

TestWithStdIO::TestWithStdIO(const char* inFile, const char* outFile) : inStream(inFile), outStream(outFile) {
    // Store the previous buffers for destruction.
    cinbuf = std::cin.rdbuf();
    coutbuf = std::cout.rdbuf();

    // Redirect the buffers to the files.
    std::cin.rdbuf(inStream.rdbuf());
    std::cout.rdbuf(outStream.rdbuf());
}
TestWithStdIO::~TestWithStdIO() {
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    inStream.close();
    outStream.close();
}
