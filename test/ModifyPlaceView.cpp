#ifndef TestModifyPlacesView_H
#define TestModifyPlacesView_H
#include "../src/ModifyPlaceView.h"
#include "TestWIthStdIO.h"
#include "compareFiles.h"
#include "igloo/igloo_alt.h"
#ifndef TMP_OUT
#define TMP_OUT "../tmp/out.txt"
#endif
using namespace igloo;

Describe(ModifyPlacesView_class) {
	It(Should_expose_a_start_method) {
        Assert::That(!!(&ModifyPlacesView::start), Equals(1));
    }
	Describe(start_method) {
		It(Should_return_the_modify_place_view) {
            TestWithStdIO ioTest("../test/ModifyPlacesView/validInput1.txt", TMP_OUT);
            HashTable ht;
            Place place1("placeA", 0, 0);
            Place *place2 = new Place("placeB", 0.0, 0.0);
            place1.addChild(place2);
            ht.add(&place1);
            ht.add(place2);
            ModifyPlacesView view(&place1, &ht);
            Assert::That(view.start(), Equals(&view));
        }
		It(Should_get_a_valid_address_from_the_user) {
            {
                TestWithStdIO ioTest("../test/ModifyPlacesView/validInput1.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                ModifyPlacesView view(&place1, &ht);
                view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/ModifyPlacesView/validOutput1.txt"), Equals(1));
        }
		It(Should_get_the_user_to_enter_valid_modified_details) {
            {
                TestWithStdIO ioTest("../test/ModifyPlacesView/invalidInput1.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                ModifyPlacesView view(&place1, &ht);
                view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/ModifyPlacesView/invalidOutput1.txt"), Equals(1));
        }
		It(Should_modify_place_name) {
            {
                TestWithStdIO ioTest("../test/ModifyPlacesView/inputName.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                ModifyPlacesView view(&place1, &ht);
                view.start();
                Assert::That(place2->getName(), Equals("newPlaceB"));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/ModifyPlacesView/outputName.txt"), Equals(1));
        }
        It(Should_modify_place_longitude) {
            {
                TestWithStdIO ioTest("../test/ModifyPlacesView/inputLongitude.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                ModifyPlacesView view(&place1, &ht);
                view.start();
                Assert::That(place2->getLongitude(), Equals(1337));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/ModifyPlacesView/outputLongitude.txt"), Equals(1));
        }
        It(Should_modify_place_latitude) {
            {
                TestWithStdIO ioTest("../test/ModifyPlacesView/inputLatitude.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                ModifyPlacesView view(&place1, &ht);
                view.start();
                Assert::That(place2->getLatitude(), Equals(1337));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/ModifyPlacesView/outputLatitude.txt"), Equals(1));
        }
	};
};

#endif