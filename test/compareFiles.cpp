#include "compareFiles.h"

int compareFiles(const char* outFile, const char* expectedFile) {
    int N = 100;
    std::FILE* f1;
    std::FILE* f2;
    char buf1[N];
    char buf2[N];
    int result = 0;

    f1 = std::fopen(outFile, "r");
    f2 = std::fopen(expectedFile, "r");

    do {
        size_t r1 = std::fread(buf1, 1, N, f1);
        size_t r2 = std::fread(buf2, 1, N, f2);

        if (r1 != r2 || std::memcmp(buf1, buf2, r1)) {
            return 0;
        }
    } while (!feof(f1) && !feof(f2));
    result = feof(f1) && feof(f2);

    std::fclose(f1);
    std::fclose(f2);

    return result;
}
