#include <cstdio>
#include <cstring>
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

        if (r1 != r2 || std::memcmp(buf1, buf2, r1)) {
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
        It_Skip(should_print_options) {
            TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", "../tmp/out.txt");
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            view.display();
            Assert::That(compareFiles("../tmp/out.txt", "../test/OptionsView/printOptions.txt"), Equals(1));
        }
        It(should_return_the_options_view) {
            TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", "../tmp/out.txt");
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            Assert::That(view.display(), Equals(&view));
        }
    };
    Describe(getOption_method) {
        It(should_return_a_valid_option_inputted_above_minimum) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", "../tmp/out.txt");
            Assert::That(view.getOption(), Equals(0));
            Assert::That(compareFiles("../tmp/out.txt", "../test/OptionsView/getValidOption.txt"), Equals(1));
        }
        It(should_return_a_valid_option_inputted_below_maximum) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            TestWithStdIO ioTest("../test/OptionsView/validInput2.txt", "../tmp/out.txt");
            Assert::That(view.getOption(), Equals(2));
            Assert::That(compareFiles("../tmp/out.txt", "../test/OptionsView/getValidOption.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_below_minimum) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            TestWithStdIO ioTest("../test/OptionsView/invalidInput1.txt", "../tmp/out.txt");
            Assert::That(view.getOption(), Equals(0));
            Assert::That(compareFiles("../tmp/out.txt", "../test/OptionsView/getInvalidOption.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_above_maximum) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            TestWithStdIO ioTest("../test/OptionsView/invalidInput2.txt", "../tmp/out.txt");
            Assert::That(view.getOption(), Equals(2));
            Assert::That(compareFiles("../tmp/out.txt", "../test/OptionsView/getInvalidOption.txt"), Equals(1));
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

Describe(Place_class) {
    It(should_construct_a_place) {
        Assert::That((new Place("name", 0, 0, NULL))->getName() == "name", Equals(1));
    }
};

Describe(DistanceApp_class) {
    It(should_expose_a_start_method) {
        Assert::That(!!(&DistanceApp::start), Equals(1));
    }
    Describe(start_method) {
        It(should_return_the_distance_app) {
            TestWithStdIO ioTest("../test/DistanceApp/quitValidInput.txt", "../tmp/out.txt");
            DistanceApp app;
            Assert::That(app.start(), Equals(&app));
        }
        It(should_output_a_menu_of_options) {
            TestWithStdIO ioTest("../test/DistanceApp/quitValidInput.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/quitValidOutput.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_below_minimum) {
            TestWithStdIO ioTest("../test/DistanceApp/quitInvalidInput1.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/quitInvalidOutput.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_above_maximum) {
            TestWithStdIO ioTest("../test/DistanceApp/quitInvalidInput2.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/quitInvalidOutput.txt"), Equals(1));
        }
        It(should_show_the_distance_view_if_that_option_is_chosen) {
            TestWithStdIO ioTest("../test/DistanceApp/distanceInput.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/distanceOutput.txt"), Equals(1));
        }
        It(should_show_the_places_view_if_that_option_is_chosen) {
            TestWithStdIO ioTest("../test/DistanceApp/placesInput.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/placesOutput.txt"), Equals(1));
        }
        It(should_show_the_add_place_view_if_that_option_is_chosen) {
            TestWithStdIO ioTest("../test/DistanceApp/addPlaceInput.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/addPlaceOutput.txt"), Equals(1));
        }
        It(should_show_the_delete_place_view_if_that_option_is_chosen) {
            TestWithStdIO ioTest("../test/DistanceApp/deletePlaceInput.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/deletePlaceOutput.txt"), Equals(1));
        }
        It(should_show_the_modify_place_view_if_that_option_is_chosen) {
            TestWithStdIO ioTest("../test/DistanceApp/modifyPlaceInput.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/modifyPlaceOutput.txt"), Equals(1));
        }
        It(should_quit_if_that_option_is_chosen) {
            TestWithStdIO ioTest("../test/DistanceApp/quitValidInput.txt", "../tmp/out.txt");
            DistanceApp app;
            app.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceApp/quitValidOutput.txt"), Equals(1));
        }
    };
};

Describe(DistanceView_class) {
    It(should_expose_a_start_method) {
        Assert::That(!!(&DistanceView::start), Equals(1));
    }
    Describe(start_method) {
        It(should_return_the_distance_view) {
            TestWithStdIO ioTest("../test/DistanceView/validInput1.txt", "../tmp/out.txt");
            Place place("name", 0, 0, NULL);
            DistanceView view(&place);
            Assert::That(view.start(), Equals(&view));
        }
        It(should_accept_two_valid_addresses) {
            TestWithStdIO ioTest("../test/DistanceView/validInput1.txt", "../tmp/out.txt");
            Place place("name", 0, 0, NULL);
            DistanceView view(&place);
            view.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceView/validOutput1.txt"), Equals(1));
        }
        It(should_reject_an_invalid_address) {
            TestWithStdIO ioTest("../test/DistanceView/invalidInput1.txt", "../tmp/out.txt");
            Place place("name", 0, 0, NULL);
            DistanceView view(&place);
            view.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceView/invalidOutput1.txt"), Equals(1));
        }
        It_Skip(should_output_the_correct_distance_between_the_two_places) {
            /*TestWithStdIO ioTest("../test/someFile.txt", "../tmp/out.txt");
            Place place("name", 0, 0, NULL);
            DistanceView view(&place);
            view.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/someFile.txt"), Equals(1));*/
        }
    };
};

int main(int argc, const char *argv[]) {
    return TestRunner::RunAllTests(argc, argv);
}