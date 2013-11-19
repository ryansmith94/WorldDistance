#ifndef TestOptionsViewPlaces_H
#define TestOptionsViewPlaces_H
#include "../src/OptionsViewPlaces.h"
#include "TestWithStdIO.h"
#include "compareFiles.h"
#include "igloo/igloo_alt.h"
#ifndef TMP_OUT
#define TMP_OUT "../tmp/out.txt"
#endif
using namespace igloo;

Describe(OptionsViewPlaces_class) {
    It(should_expose_a_display_method) {
        Assert::That(!!(&OptionsViewPlaces::display), Equals(1));
    }
    It(should_expose_a_getOption_method) {
        Assert::That(!!(&OptionsViewPlaces::getOption), Equals(1));
    }
    It(should_expose_a_getOptions_method) {
        Assert::That(!!(&OptionsViewPlaces::getOptions), Equals(1));
    }
    Describe(display_method) {
        It(should_print_options) {
            Node<Place>* opts;
            Place place1("place1", 0.0, 0.0);
            Place place2("place2", 0.0, 0.0);
            Place place3("place3", 0.0, 0.0);
            opts = new Node<Place>(&place1);
            opts->setNext(new Node<Place>(&place2));
            opts->getNext()->setNext(new Node<Place>(&place3));
            OptionsViewPlaces view(opts);
            {
                TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", TMP_OUT);
                view.display();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsViewPlaces/validOutput1.txt"), Equals(1));
        }
        It(should_return_the_options_view_places) {
            Node<Place>* opts;
            Place place1("place1", 0.0, 0.0);
            Place place2("place2", 0.0, 0.0);
            Place place3("place3", 0.0, 0.0);
            opts = new Node<Place>(&place1);
            opts->setNext(new Node<Place>(&place2));
            opts->getNext()->setNext(new Node<Place>(&place3));
            OptionsViewPlaces view(opts);

            TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", TMP_OUT);
            Assert::That(view.display(), Equals(&view));
        }
    };
    Describe(getOption_method) {
        It(should_return_a_valid_option_inputted_above_minimum) {
            Node<Place>* opts;
            Place place1("place1", 0.0, 0.0);
            Place place2("place2", 0.0, 0.0);
            Place place3("place3", 0.0, 0.0);
            opts = new Node<Place>(&place1);
            opts->setNext(new Node<Place>(&place2));
            opts->getNext()->setNext(new Node<Place>(&place3));
            OptionsViewPlaces view(opts);

            TestWithStdIO ioTest("../test/OptionsView/validInput1.txt", TMP_OUT);
			view.display();
            Assert::That(view.getOption(), Equals(0));
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsViewPlaces/validOuput1.txt"), Equals(1));
        }
        It(should_return_a_valid_option_inputted_below_maximum) {
            Node<Place>* opts;
            Place place1("place1", 0.0, 0.0);
            Place place2("place2", 0.0, 0.0);
            Place place3("place3", 0.0, 0.0);
            opts = new Node<Place>(&place1);
            opts->setNext(new Node<Place>(&place2));
            opts->getNext()->setNext(new Node<Place>(&place3));
            OptionsViewPlaces view(opts);

            TestWithStdIO ioTest("../test/OptionsView/validInput2.txt", TMP_OUT);
			view.display();
            Assert::That(view.getOption(), Equals(2));
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsViewPlaces/validOuput1.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_below_minimum) {
            Node<Place>* opts;
            Place place1("place1", 0.0, 0.0);
            Place place2("place2", 0.0, 0.0);
            Place place3("place3", 0.0, 0.0);
            opts = new Node<Place>(&place1);
            opts->setNext(new Node<Place>(&place2));
            opts->getNext()->setNext(new Node<Place>(&place3));
            OptionsViewPlaces view(opts);

            TestWithStdIO ioTest("../test/OptionsView/invalidInput1.txt", TMP_OUT);
			view.display();
            Assert::That(view.getOption(), Equals(0));
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsViewPlaces/invalidOuput1.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_above_maximum) {
            Node<Place>* opts;
            Place place1("place1", 0.0, 0.0);
            Place place2("place2", 0.0, 0.0);
            Place place3("place3", 0.0, 0.0);
            opts = new Node<Place>(&place1);
            opts->setNext(new Node<Place>(&place2));
            opts->getNext()->setNext(new Node<Place>(&place3));
            OptionsViewPlaces view(opts);

            TestWithStdIO ioTest("../test/OptionsView/invalidInput2.txt", TMP_OUT);
			view.display();
            Assert::That(view.getOption(), Equals(2));
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsViewPlaces/invalidOuput1.txt"), Equals(1));
        }
        It(should_reject_an_invalid_option_of_wrong_type) {
            Node<Place>* opts;
            Place place1("place1", 0.0, 0.0);
            Place place2("place2", 0.0, 0.0);
            Place place3("place3", 0.0, 0.0);
            opts = new Node<Place>(&place1);
            opts->setNext(new Node<Place>(&place2));
            opts->getNext()->setNext(new Node<Place>(&place3));
            OptionsViewPlaces view(opts);

            TestWithStdIO ioTest("../test/OptionsView/invalidInput3.txt", TMP_OUT);
			view.display();
            Assert::That(view.getOption(), Equals(2));
            Assert::That(compareFiles(TMP_OUT, "../test/OptionsViewPlaces/invalidOuput1.txt"), Equals(1));
        }
    };
    Describe(getOptions_method) {
        It(should_return_all_of_the_options) {
            Node<Place>* opts;
            Place place1("place1", 0.0, 0.0);
            Place place2("place2", 0.0, 0.0);
            Place place3("place3", 0.0, 0.0);
            opts = new Node<Place>(&place1);
            opts->setNext(new Node<Place>(&place2));
            opts->getNext()->setNext(new Node<Place>(&place3));
            OptionsViewPlaces view(opts);

            Assert::That(view.getOptions(), Equals(opts));
        }
    };
};

#endif
