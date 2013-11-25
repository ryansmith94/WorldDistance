#ifndef TestDeletePlacesView_H
#define TestDeletePlacesView_H
#include "../src/DeletePlacesView.h"
#include "TestWIthStdIO.h"
#include "compareFiles.h"
#include "igloo/igloo_alt.h"
#ifndef TMP_OUT
#define TMP_OUT "../tmp/out.txt"
#endif
using namespace igloo;

Describe(DeletePlacesView_class) {
	It(Should_expose_a_start_method) {
        Assert::That(!!(&DeletePlacesView::start), Equals(1));
    }
	Describe(start_method) {
		It(Should_return_the_delete_place_view) {
            TestWithStdIO ioTest("../test/DeletePlacesView/validInput1.txt", TMP_OUT);
            HashTable ht;
            Place place1("placeA", 0, 0);
            Place *place2 = new Place("placeB", 0.0, 0.0);
            place1.addChild(place2);
            ht.add(&place1);
            ht.add(place2);
            DeletePlacesView view(&place1, &ht);
            Assert::That(view.start(), Equals(&view));
        }
		It(Should_get_a_valid_address_from_the_user) {
            {
                TestWithStdIO ioTest("../test/DeletePlacesView/validInput1.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                DeletePlacesView view(&place1, &ht);
                view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DeletePlacesView/validOutput1.txt"), Equals(1));
        }
		It(Should_delete_the_place) {
            {
                TestWithStdIO ioTest("../test/DeletePlacesView/validInput2.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.loadPlace("../test/noData.txt", &ht);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                DeletePlacesView view(&place1, &ht);
                view.start();
                Assert::That(place1.getNbrChildren(), Equals(0));
                Assert::That(ht.get("placeB")->getSize(), Equals(0));
            }
            Assert::That(compareFiles(TMP_OUT, "../test/DeletePlacesView/validOutput2.txt"), Equals(1));
        }
	};
};

#endif