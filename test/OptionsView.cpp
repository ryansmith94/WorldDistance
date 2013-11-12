#ifndef TestOptionsView_H
#define TestOptionsView_H
#include "../src/OptionsView.h"
#include "TestWithStdIO.cpp"
#include "compareFiles.cpp"
#include "igloo/igloo_alt.h"
#ifndef TMP_OUT
#define TMP_OUT "../tmp/out.txt"
#endif
using namespace igloo;

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
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
			{
				TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", TMP_OUT);
				view.display();
			}
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsView/printOptions.txt"), Equals(1));
        }
        It(should_return_the_options_view) {
            TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", TMP_OUT);
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);
            Assert::That(view.display(), Equals(&view));
        }
    };
    Describe(getOption_method) {
        It(should_return_a_valid_option_inputted_above_minimum) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            {
                TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", TMP_OUT);
                Assert::That(view.getOption(), Equals(0));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsView/getValidOption.txt"), Equals(1));
        }
        It(should_return_a_valid_option_inputted_below_maximum) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            {
                TestWithStdIO ioTest("../test/OptionsView/validInput2.txt", TMP_OUT);
                Assert::That(view.getOption(), Equals(2));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsView/getValidOption.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_below_minimum) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            {
                TestWithStdIO ioTest("../test/OptionsView/invalidInput1.txt", TMP_OUT);
                Assert::That(view.getOption(), Equals(0));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsView/getInvalidOption.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_above_maximum) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            {
                TestWithStdIO ioTest("../test/OptionsView/invalidInput2.txt", TMP_OUT);
                Assert::That(view.getOption(), Equals(2));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsView/getInvalidOption.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_of_wrong_type) {
            int opts[] = {0, 1, 2};
            OptionsView<int> view(opts, 3);

            {
                TestWithStdIO ioTest("../test/OptionsView/invalidInput3.txt", TMP_OUT);
                Assert::That(view.getOption(), Equals(2));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsView/getInvalidOption.txt"), Equals(1));
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
#endif
