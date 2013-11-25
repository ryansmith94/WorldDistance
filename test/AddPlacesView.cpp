#ifndef TestAddPlacesView_H
#define TestAddPlacesView_H
#include "../src/AddPlacesView.h"
#include "TestWithStdIO.h"
#include "compareFiles.h"
#include "igloo/igloo_alt.h"
#ifndef TMP_OUT
#define TMP_OUT "../tmp/out.txt"
#endif
using namespace igloo;

Describe(AddPlacesView_class) {
	It(Should_expose_a_start_method) {
        Assert::That(!!(&AddPlacesView::start), Equals(1));
    }
	Describe(start_method) {
		It(Should_return_the_add_place_view) {
            TestWithStdIO ioTest("../test/AddPlacesView/validInput1.txt", TMP_OUT);
            HashTable ht;
            Place place1("placeA", 0, 0);
            Place *place2 = new Place("placeB", 0.0, 0.0);
            place1.addChild(place2);
            ht.add(&place1);
            ht.add(place2);
            AddPlacesView view(&place1, &ht);
            Assert::That(view.start(), Equals(&view));
        }
		It(Should_get_valid_properties_for_the_place) {
            {
                TestWithStdIO ioTest("../test/AddPlacesView/validInput1.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                AddPlacesView view(&place1, &ht);
                view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/AddPlacesView/validOutput1.txt"), Equals(1));
        }
		It(Should_add_the_place) {
            {
                TestWithStdIO ioTest("../test/AddPlacesView/validInput1.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.loadPlace("../test/DeletePlacesView/noData.txt", &ht);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                AddPlacesView view(&place1, &ht);
                view.start();
                Assert::That(ht.get("placeC")->getSize(), Equals(1));
                Assert::That(place1.getNbrChildren(), Equals(2));
            }
        }
	};
};

#endif