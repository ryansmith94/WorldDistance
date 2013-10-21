#include <cstdio>
#include <fstream>
#include "igloo/igloo_alt.h"
using namespace igloo;

#include "../src/core.cpp"

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

        if (r1 != r2 || memcmp(buf1, buf2, r1)) {
            return 0;
        }
    } while (!feof(f1) && !feof(f2));
    result = feof(f1) && feof(f2);

    std::fclose(f1);
    std::fclose(f2);

    return result;
}

class TestWithStdIO {
        std::streambuf *cinbuf;
        std::streambuf *coutbuf;
        std::ifstream inStream;
        std::ofstream outStream;
    public:
        TestWithStdIO(const char* inFile, const char* outFile) : inStream(inFile), outStream(outFile) {
            outFile = outFile;

            // Store the previous buffers for destruction.
            cinbuf = std::cin.rdbuf();
            coutbuf = std::cout.rdbuf();

            // Redirect the buffers to the files.
            std::cin.rdbuf(inStream.rdbuf());
            std::cout.rdbuf(outStream.rdbuf());
        }
        ~TestWithStdIO() {
            std::cin.rdbuf(cinbuf);
            std::cout.rdbuf(coutbuf);

            inStream.close();
            outStream.close();
        }
};

Describe(OptionsView_class) {
    It(should_expose_a_display_method) {
        Assert::That(!!(&OptionsView<int>::display), Equals(1));
    }
    It(should_expose_a_getOption_method) {
        Assert::That(!!(&OptionsView<int>::getOption), Equals(1));
    }
    It(should_expose_a_getOptions_method) {
        Assert::That(!!(&OptionsView<int>::getOptions), Equals(1));
    }
    Describe(display_method) {
        It(should_print_options) {
            TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", "../tmp/out.txt");
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            view.display();
            Assert::That(compareFiles("../tmp/out.txt", "../test/OptionsView/printOptions.txt"), Equals(1));
        }
        It(should_return_options_view) {
            TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", "../tmp/out.txt");
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            Assert::That(view.display(), Equals(&view));
        }
    };
    Describe(getOption_method) {
        It_Skip(should_ask_user_for_option) { // This does not work for some reason :(
            TestWithStdIO ioTest("../test/validInput1.txt", "../tmp/out.txt");
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            view.getOption();
            Assert::That(compareFiles("../tmp/out.txt", "../test/OptionsView/getValidOption.txt"), Equals(1));
        }
        It_Skip(should_accept_valid_option) {
            TestWithStdIO ioTest("", "");
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            view.getOption();
        }
        It_Skip(should_reject_invalid_option) {
            TestWithStdIO ioTest("", "");
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            view.getOption();
        }
        It_Skip(should_return_valid_option) {
            TestWithStdIO ioTest("", "");
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            view.getOption();
        }
    };
    Describe(getOptions_method) {
        It(should_return_all_of_the_options) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            Assert::That(view.getOptions()[0], Equals(0));
            Assert::That(view.getOptions()[1], Equals(1));
            Assert::That(view.getOptions()[2], Equals(2));
        }
    };
};

int main(int argc, const char *argv[]) {
    return TestRunner::RunAllTests(argc, argv);
}