#ifndef TestDistanceApp_H
#define TestDistanceApp_H
#include "../src/DistanceApp.h"
#include "TestWithStdIO.cpp"
#include "compareFiles.cpp"
#include "igloo/igloo_alt.h"
#ifndef TMP_OUT
#define TMP_OUT "../tmp/out.txt"
#endif
#define TMP_SAVE_OUT "../tmp/saveout.txt"
#define LOAD_IN "../test/Place/LoadTestData.txt"
using namespace igloo;

Describe(DistanceApp_class) {
    It(should_expose_a_start_method) {
        Assert::That(!!(&DistanceApp::start), Equals(1));
    }
    It(should_save_places) {
        {
            TestWithStdIO ioTest("../test/DistanceApp/quitValidInput.txt", TMP_OUT);
            DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
            app.start();
        }
        Assert::That(compareFiles(TMP_SAVE_OUT, "../test/Place/SaveTestData.txt"), Equals(1));
    }
    It(should_load_places) {
        {
            TestWithStdIO ioTest("../test/DistanceApp/distanceInput.txt", TMP_OUT);
            DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
            app.start();
        }
        Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/distanceOutput.txt"), Equals(1));
    }
    Describe(start_method) {
        It(should_return_the_distance_app) {
            TestWithStdIO ioTest("../test/DistanceApp/quitValidInput.txt", TMP_OUT);
            DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
            Assert::That(app.start(), Equals(&app));
        }
        It(should_output_a_menu_of_options) {
			{
				TestWithStdIO ioTest("../test/DistanceApp/quitValidInput.txt", TMP_OUT);
				DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
				app.start();
			}
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/quitValidOutput.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_below_minimum) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/quitInvalidInput1.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/quitInvalidOutput.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_above_maximum) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/quitInvalidInput2.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/quitInvalidOutput.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_of_wrong_type) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/quitInvalidInput3.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/quitInvalidOutput.txt"), Equals(1));
        }
        It(should_show_the_distance_view_if_that_option_is_chosen) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/distanceInput.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/distanceOutput.txt"), Equals(1));
        }
        It_Skip(should_show_the_places_view_if_that_option_is_chosen) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/placesInput.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/placesOutput.txt"), Equals(1));
        }
        It_Skip(should_show_the_add_place_view_if_that_option_is_chosen) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/addPlaceInput.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/addPlaceOutput.txt"), Equals(1));
        }
        It_Skip(should_show_the_delete_place_view_if_that_option_is_chosen) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/deletePlaceInput.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/deletePlaceOutput.txt"), Equals(1));
        }
        It_Skip(should_show_the_modify_place_view_if_that_option_is_chosen) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/modifyPlaceInput.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/modifyPlaceOutput.txt"), Equals(1));
        }
        It(should_quit_if_that_option_is_chosen) {
            {
                TestWithStdIO ioTest("../test/DistanceApp/quitValidInput.txt", TMP_OUT);
                DistanceApp app(LOAD_IN, TMP_SAVE_OUT);
                app.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceApp/quitValidOutput.txt"), Equals(1));
        }
    };
};

#endif
