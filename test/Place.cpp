#ifndef TestPlace_H
#define TestPlace_H
#include "../src/Place.cpp"
#include "compareFiles.cpp"
#include "igloo/igloo_alt.h"
using namespace igloo;

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

#endif
