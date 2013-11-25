#ifndef TestPlacesView_H
#define TestPlacesView_H
#include "../src/PlacesView.h"
#include "TestWIthStdIO.h"
#include "compareFiles.h"
#include "igloo/igloo_alt.h"
#ifndef TMP_OUT
#define TMP_OUT "../tmp/out.txt"
#endif
using namespace igloo;

Describe(PlacesView_class) {
	It(Should_expose_a_start_method) {
        Assert::That(!!(&PlacesView::start), Equals(1));
    }
	Describe(start_method) {
		It(Should_return_the_placesview) {
            TestWithStdIO ioTest("../test/PlacesView/validInput1.txt", TMP_OUT);
            HashTable ht;
            Place place1("placeA", 0, 0);
            Place *place2 = new Place("placeB", 0.0, 0.0);
            place1.addChild(place2);
            ht.add(&place1);
            ht.add(place2);
            PlacesView view(&place1, &ht);
            Assert::That(view.start(), Equals(&view));
        }
		It(Should_output_addresses_that_match_the_given__valid_address) {
            {
                TestWithStdIO ioTest("../test/PlacesView/validInput1.txt", TMP_OUT);
                HashTable ht;
                Place place1("placeA", 0, 0);
                Place *place2 = new Place("placeB", 0.0, 0.0);
                place1.addChild(place2);
                ht.add(&place1);
                ht.add(place2);
                PlacesView view(&place1, &ht);
                view.start();
            }
            Assert::That(compareFiles(TMP_OUT, "../test/PlacesView/validOutput1.txt"), Equals(1));
        }
	};
};

#endif