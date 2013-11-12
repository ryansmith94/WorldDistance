#ifndef TestDistanceView_H
#define TestDistanceView_H
#include "../src/DistanceView.h"
#include "TestWithStdIO.cpp"
#include "compareFiles.cpp"
#include "igloo/igloo_alt.h"
#ifndef TMP_OUT
#define TMP_OUT "../tmp/out.txt"
#endif
using namespace igloo;

Describe(DistanceView_class) {
    It(should_expose_a_start_method) {
        Assert::That(!!(&DistanceView::start), Equals(1));
    }
    Describe(start_method) {
        It(should_return_the_distance_view) {
            TestWithStdIO ioTest("../test/DistanceView/validInput1.txt", TMP_OUT);
			HashTable ht;
            Place place("name", 0, 0);
			Place *place2 = new Place("place1", 0.0, 0.0);
            place.addChild(place2);
			ht.add(&place);
			ht.add(place2);
            DistanceView view(&place, &ht);
            Assert::That(view.start(), Equals(&view));
        }
        It(should_accept_two_valid_places) {
            {
				TestWithStdIO ioTest("../test/DistanceView/validInput1.txt", TMP_OUT);
				HashTable ht;
				Place place("name", 0, 0);
				Place *place2 = new Place("place1", 0.0, 0.0);
				place.addChild(place2);
				ht.add(&place);
				ht.add(place2);
				DistanceView view(&place, &ht);
				view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceView/validOutput1.txt"), Equals(1));
        }
        It(should_accept_two_valid_places_of_same_name) {
            {
                TestWithStdIO ioTest("../test/DistanceView/validInput2.txt", TMP_OUT);
                HashTable ht;
				Place place("name", 0, 0);
				Place *place2 = new Place("place1", 0.0, 0.0);
				Place *place3 = new Place("place2", 0.0,0.0);
				place.addChild(place2);
				place2->addChild(place3);
				ht.add(&place);
				ht.add(place2);
				ht.add(place3);
				DistanceView view(&place, &ht);
				view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceView/validOutput2.txt"), Equals(1));
        }
        It(should_reject_an_invalid_address) {
            {
				TestWithStdIO ioTest("../test/DistanceView/invalidInput1.txt", TMP_OUT);
				HashTable ht;
				Place place("name", 0, 0);
				Place *place2 = new Place("place1", 0.0, 0.0);
				place.addChild(place2);
				ht.add(&place);
				ht.add(place2);
				DistanceView view(&place, &ht);
				view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceView/invalidOutput1.txt"), Equals(1));
        }
        It(should_output_the_correct_distance_between_the_two_places) {
            {
				TestWithStdIO ioTest("../test/DistanceView/validInput3.txt", TMP_OUT);
				HashTable ht;
				Place place("name", 0, 0);
				Place *place2 = new Place("London", 0.1275, 51.5072);
				Place *place3 = new Place("New York", 74.0060, 40.7144);
				place.addChild(place2);
				place.addChild(place3);
				ht.add(&place);
				ht.add(place2);
				ht.add(place3);
				DistanceView view(&place, &ht);
				view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DistanceView/validOutput3.txt"), Equals(1));
        }
    };
};

#endif
