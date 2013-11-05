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
        Assert::That((new Place("name", 0, 0))->getName() == "name", Equals(1));
    }
	It(should_expose_a_getName_method){
		Assert::That(!!(&Place::getName), Equals(1));
	}
	It(should_expose_a_getLongitude_method){
		Assert::That(!!(&Place::getLongitude), Equals(1));
	}
	It(should_expose_a_getLatitude_method){
		Assert::That(!!(&Place::getLatitude), Equals(1));
	}
	It(should_expose_a_setName_method){
		Assert::That(!!(&Place::setName), Equals(1));
	}
	It(should_expose_a_getParent_method){
		Assert::That(!!(&Place::getParent), Equals(1));
	}
	It(should_expose_a_getMatchedChildren_method){
		Assert::That(!!(&Place::getMatchedChildren), Equals(1));
	}
	It(should_expose_a_getChild_method){
		Assert::That(!!(&Place::getChild), Equals(1));
	}
	It(should_expose_a_getNbrChildren_method){
		Assert::That(!!(&Place::getNbrChildren), Equals(1));
	}
	It(should_expose_a_addChild_method){
		Assert::That(!!(&Place::addChild), Equals(1));
	}
	It(should_expose_a_removeChild_method){
		Assert::That(!!(&Place::removeChild), Equals(1));
	}
	It(should_expose_a_loadPlace_method){
		Assert::That(!!(&Place::loadPlace), Equals(1));
	}
	It(should_expose_a_savePlace_method){
		Assert::That(!!(&Place::savePlace), Equals(1));
	}
	Describe(getName_method){
		It(should_return_the_place_name){
			Place testPlace("name",1.2,2.3);
			Assert::That(testPlace.getName(), Equals("name"));
		}
	};
	Describe(getLongitude_method){
		It(should_return_the_place_longitude){
			Place testPlace("name",1.2,2.3);
			Assert::That(testPlace.getLongitude(), Equals(1.2f));
		}
	};
	Describe(getLatitude_method){
		It(should_return_the_place_latitude){
			Place testPlace("name",1.2,2.3);
			Assert::That(testPlace.getLatitude(), Equals(2.3f));
		}
	};
	Describe(setName_method){
		It(should_change_the_place_name){
			Place testPlace("name",1.2,2.3);
			Assert::That(testPlace.getName(), Equals("name"));
			testPlace.setName("newName");
			Assert::That(testPlace.getName(), Equals("newName"));
		}
		It(should_update_the_place_address){
			Place testPlace("name",1.2,2.3);
			Assert::That(testPlace.getAddress(), Equals("name"));
			testPlace.setName("newName");
			Assert::That(testPlace.getAddress(), Equals("newName"));
		}
		It(should_update_the_address_of_all_children){
			Place testPlace("name",1.2,2.3);
			Place *anotherPlace = new Place("another name",3.4,4.5);
			Place *yetAnotherPlace = new Place("yet another name",5.6,6.7);
			testPlace.addChild(anotherPlace);
			testPlace.addChild(yetAnotherPlace);
			Assert::That(anotherPlace->getAddress(), Equals("name, another name"));
			Assert::That(yetAnotherPlace->getAddress(), Equals("name, yet another name"));
			testPlace.setName("newName");
			Assert::That(anotherPlace->getAddress(), Equals("newName, another name"));
			Assert::That(yetAnotherPlace->getAddress(), Equals("newName, yet another name"));
		}
	};
	Describe(getParent_method){
		It(should_return_a_pointer_to_the_parent_place){
			Place testPlace("name",1.2,2.3);
			Place *anotherPlace = new Place("another name",3.4,4.5);
			testPlace.addChild(anotherPlace);
			Assert::That(anotherPlace->getParent(), Equals(&testPlace));
		}
	};
	Describe(getMatchedPlaces_method){
		It(should_return_any_places_matching_a_searched_place_name){
			Place testPlace("one",1.2,2.3);
			Place *testPlace2 = new Place("two",3.4,4.5);
			Place *testPlace3 = new Place("three",5.6,6.7);
			Place *testPlace4 = new Place("one",7.8,8.9);
			Place *testPlace5 = new Place("fiftyone",1.12,1.13);
			Place *testPlace6 = new Place("six",1.14,1.15);
			testPlace.addChild(testPlace2);
			testPlace.addChild(testPlace3);
			testPlace2->addChild(testPlace4);
			testPlace3->addChild(testPlace5);
			testPlace4->addChild(testPlace6);
			Assert::That(testPlace.getMatchedChildren("one")->getSize(), Equals(3));
			Assert::That(testPlace.getMatchedChildren("one")->getData(0), Equals(&testPlace));
			Assert::That(testPlace.getMatchedChildren("one")->getData(1), Equals(testPlace4));
			Assert::That(testPlace.getMatchedChildren("one")->getData(2), Equals(testPlace5));
		}
		It(should_return_all_places_matching_address){
			Place testPlace("one",1.2,2.3);
			Place *testPlace2 = new Place("two",3.4,4.5);
			Place *testPlace3 = new Place("three",5.6,6.7);
			Place *testPlace4 = new Place("one",7.8,8.9);
			Place *testPlace5 = new Place("fiftyone",1.12,1.13);
			Place *testPlace6 = new Place("six",1.14,1.15);
			testPlace.addChild(testPlace2);
			testPlace.addChild(testPlace3);
			testPlace2->addChild(testPlace4);
			testPlace3->addChild(testPlace5);
			testPlace4->addChild(testPlace6);
			Assert::That(testPlace.getMatchedChildren("one, two, one")->getSize(), Equals(1));
			Assert::That(testPlace.getMatchedChildren("one, two, one")->getData(0), Equals(testPlace4));
		}
		It(should_return_all_places_in_the_order_found_when_empty_string_searched){
			Place testPlace("one",1.2,2.3);
			Place *testPlace2 = new Place("two",3.4,4.5);
			Place *testPlace3 = new Place("three",5.6,6.7);
			Place *testPlace4 = new Place("one",7.8,8.9);
			Place *testPlace5 = new Place("fiftyone",1.12,1.13);
			Place *testPlace6 = new Place("six",1.14,1.15);
			testPlace.addChild(testPlace2);
			testPlace.addChild(testPlace3);
			testPlace2->addChild(testPlace4);
			testPlace3->addChild(testPlace5);
			testPlace4->addChild(testPlace6);
			Assert::That(testPlace.getMatchedChildren("")->getSize(), Equals(6));
			Assert::That(testPlace.getMatchedChildren("")->getData(0), Equals(&testPlace));
			Assert::That(testPlace.getMatchedChildren("")->getData(1), Equals(testPlace2));
			Assert::That(testPlace.getMatchedChildren("")->getData(2), Equals(testPlace4));
			Assert::That(testPlace.getMatchedChildren("")->getData(3), Equals(testPlace6));
			Assert::That(testPlace.getMatchedChildren("")->getData(4), Equals(testPlace3));
			Assert::That(testPlace.getMatchedChildren("")->getData(5), Equals(testPlace5));
		}
	};
	Describe(getChild_method){
		It(should_return_the_child_at_the_index_provided){
			Place testPlace("one",1.2,2.3);
			Place *testPlace2 = new Place("two",3.4,4.5);
			Place *testPlace3 = new Place("three",5.6,6.7);
			Place *testPlace4 = new Place("one",7.8,8.9);
			testPlace.addChild(testPlace2);
			testPlace.addChild(testPlace3);
			testPlace.addChild(testPlace4);
			Assert::That(testPlace.getChild(0),Equals(testPlace2));
			Assert::That(testPlace.getChild(1),Equals(testPlace3));
			Assert::That(testPlace.getChild(2),Equals(testPlace4));
		}
	};
	Describe(getNbrChildren_method){
		It(should_return_the_number_of_children){
			Place testPlace("one",1.2,2.3);
			Place *testPlace2 = new Place("two",3.4,4.5);
			Place *testPlace3 = new Place("three",5.6,6.7);
			Assert::That(testPlace.getNbrChildren(), Equals(0));
			testPlace.addChild(testPlace2);
			Assert::That(testPlace.getNbrChildren(), Equals(1));
			testPlace.addChild(testPlace3);
			Assert::That(testPlace.getNbrChildren(), Equals(2));
		}
	};
	Describe(addChild_method){
		It(should_add_the_given_child_place_to_the_list_of_children){
			Place testPlace("one",1.2,2.3);
			Place *testPlace2 = new Place("two",3.4,4.5);
			testPlace.addChild(testPlace2);
			Assert::That(testPlace.getChild(0)), Equals(testPlace2);
		}
	};
	Describe(removeChild_method){
		It(should_remove_the_given_child_){
			Place testPlace("one",1.2,2.3);
			Place *testPlace2 = new Place("two",3.4,4.5);
			testPlace.addChild(testPlace2);
			Assert::That(testPlace.getNbrChildren(), Equals(1));
			testPlace.removeChild(0);
			Assert::That(testPlace.getNbrChildren(), Equals(0));
		}
	};
	Describe(loadPlace_method){
		It(should_load_places_from_a_file){
			Place testPlace("Earth",0.0,0.0);
			testPlace.loadPlace("../test/Place/LoadTestData.txt");
			Assert::That(testPlace.getChild(0)->getName(), Equals("UK"));
			Assert::That(testPlace.getChild(0)->getLongitude(), Equals(2.4333f));
			Assert::That(testPlace.getChild(0)->getLatitude(), Equals(53.55f));
			Assert::That(testPlace.getChild(1)->getChild(0)->getChild(0)->getName(), Equals("Birmingham"));
			Assert::That(testPlace.getChild(1)->getChild(0)->getChild(0)->getLongitude(), Equals(86.8127f));
			Assert::That(testPlace.getChild(1)->getChild(0)->getChild(0)->getLatitude(), Equals(33.5248f));
		}
	};
	Describe(savePlace_method){
		It(should_save_places_to_a_file){
			Place testPlace("Earth",0.0,0.0);
			testPlace.loadPlace("../test/Place/LoadTestData.txt");
			testPlace.savePlace("../test/Place/SaveTestData.txt");
			Assert::That(compareFiles("../test/Place/LoadTestData.txt", "../test/Place/SaveTestData.txt"), Equals(1));
		}
	};
	Describe(getAddress_methhod){
		It(should_get_the_address){
			Place testPlace("Earth",0.0,0.0);
			Place *testPlace2 = new Place("UK",3.4,4.5);
			Place *testPlace3 = new Place("London",3.4,4.5);
			testPlace.addChild(testPlace2);
			testPlace2->addChild(testPlace3);
			Assert::That(testPlace3->getAddress(), Equals("Earth, UK, London"));
		}
	};
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
        It_Skip(should_show_the_distance_view_if_that_option_is_chosen) {
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
        It_Skip(should_return_the_distance_view) {
            TestWithStdIO ioTest("../test/DistanceView/validInput1.txt", "../tmp/out.txt");
            Place place("name", 0, 0);
            DistanceView view(&place);
            Assert::That(view.start(), Equals(&view));
        }
        It_Skip(should_accept_two_valid_places) {
            TestWithStdIO ioTest("../test/DistanceView/validInput1.txt", "../tmp/out.txt");
            Place place("name", 0, 0);
            DistanceView view(&place);
            view.start();
            Assert::That(compareFiles("../tmp/out.txt", "../test/DistanceView/validOutput1.txt"), Equals(1));
        }
        It_Skip(should_reject_an_invalid_address) {
            TestWithStdIO ioTest("../test/DistanceView/invalidInput1.txt", "../tmp/out.txt");
            Place place("name", 0, 0);
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