#ifndef TestLList_H
#define TestLList_H
#include "../src/LList.h"
#include "igloo/igloo_alt.h"
using namespace igloo;

Describe(LList_class){
	It(should_construct_a_LList){
		Assert::That((new LList<int>()) != NULL, Equals(1));
	}
	It(should_expose_a_getSize_method){
		Assert::That(!!(&LList<int>::getSize), Equals(1));
	}
	It(should_expose_a_append_method){
		Assert::That(!!(&LList<int>::append), Equals(1));
	}
	It(should_expose_a_insert_method){
		Assert::That(!!(&LList<int>::insert), Equals(1));
	}
	It(should_expose_a_remove_method){
		Assert::That(!!(&LList<int>::remove), Equals(1));
	}
	It(should_expose_a_getData_method){
		Assert::That(!!(&LList<int>::getData), Equals(1));
	}
	It(should_expose_a_addAll_method){
		Assert::That(!!(&LList<int>::addAll), Equals(1));
	}
	It(should_expose_a_clear_method){
		Assert::That(!!(&LList<int>::clear), Equals(1));
	}
	Describe(getSize_method){
		It(should_return_the_size_of_an_empty_list){
			LList<int> list;
			Assert::That(list.getSize(), Equals(0));
		}
		It(should_return_the_size_of_a_filled_list){
			LList<int> list;
			int a,b,c; a=3; b=5; c=2;
			list.append(&a);
			list.append(&b);
			list.append(&c);
			Assert::That(list.getSize(), Equals(3));
			list.clear();
		}
	};
	Describe(append_method){
		It(should_append_a_item_to_the_start_of_the_list_if_it_is_the_first_item){
			LList<int> list;
			int a = 3;
			Assert::That(list.getSize(), Equals(0));
			list.append(&a);
			Assert::That(list.getSize(), Equals(1));
			Assert::That(list.getData(0), Equals(&a));
			list.clear();
		}
		It(should_append_a_item_to_the_end_of_the_list){
			LList<int> list;
			int a,b; a=3; b=5;
			Assert::That(list.getSize(), Equals(0));
			list.append(&a);
			list.append(&b);
			Assert::That(list.getSize(), Equals(2));
			Assert::That(list.getData(1), Equals(&b));
			list.clear();
		}
	};
	Describe(insert_method){
		It(should_insert_an_item_at_the_start_of_a_list){
			int a,b,c; a=3; b=5; c=2;
			LList<int> list;
			list.append(&a);
			list.append(&b);
			Assert::That(list.getData(0), Equals(&a));
			Assert::That(list.getSize(), Equals(2));
			list.insert(&c,0);
			Assert::That(list.getData(0), Equals(&c));
			Assert::That(list.getSize(), Equals(3));
			list.clear();
		}
		It(should_insert_an_item_in_a_middle_of_a_list){
			int a,b,c; a=3; b=5; c=2;
			LList<int> list;
			list.append(&a);
			list.append(&b);
			Assert::That(list.getData(1), Equals(&b));
			Assert::That(list.getSize(), Equals(2));
			list.insert(&c,1);
			Assert::That(list.getData(1), Equals(&c));
			Assert::That(list.getSize(), Equals(3));
			list.clear();
		}
		It(should_insert_an_item_at_the_end_of_a_list){
			int a,b,c; a=3; b=5; c=2;
			LList<int> list;
			list.append(&a);
			list.append(&b);
			Assert::That(list.getSize(), Equals(2));
			list.insert(&c,2);
			Assert::That(list.getData(2), Equals(&c));
			Assert::That(list.getSize(), Equals(3));
			list.clear();
		}
	};
	Describe(remove_method){
		It(should_remove_the_first_element_of_a_list){
			int *a = new int(3);
			int *b = new int(5);
			int *c = new int(2);
			LList<int> list;
			list.append(a);
			list.append(b);
			list.append(c);
			Assert::That(list.getSize(), Equals(3));
			Assert::That(list.getData(0), Equals(a));
			list.remove(0);
			Assert::That(list.getSize(), Equals(2));
			Assert::That(list.getData(0), Equals(b));
		}
		It(should_remove_the_middle_element_of_a_list){
			int *a = new int(3);
			int *b = new int(5);
			int *c = new int(2);
			LList<int> list;
			list.append(a);
			list.append(b);
			list.append(c);
			Assert::That(list.getSize(), Equals(3));
			Assert::That(list.getData(1), Equals(b));
			list.remove(1);
			Assert::That(list.getSize(), Equals(2));
			Assert::That(list.getData(1), Equals(c));
		}
		It(should_remove_the_last_element_of_a_list){
			int *a = new int(3);
			int *b = new int(5);
			int *c = new int(2);
			LList<int> list;
			list.append(a);
			list.append(b);
			list.append(c);
			Assert::That(list.getSize(), Equals(3));
			Assert::That(list.getData(2), Equals(c));
			list.remove(2);
			Assert::That(list.getSize(), Equals(2));
		}
		It(should_remove_the_only_element_of_a_list){
			int *a = new int(3);
			LList<int> list;
			list.append(a);
			Assert::That(list.getSize(), Equals(1));
			list.remove(0);
			Assert::That(list.getSize(), Equals(0));
		}
	};
	Describe(getData_method){
		It(should_get_the_first_element_of_a_list){
			int a,b,c; a=3; b=5; c=2;
			LList<int> list;
			list.append(&a);
			list.append(&b);
			list.append(&c);
			Assert::That(list.getData(0), Equals(&a));
			list.clear();
		}
		It(should_get_the_last_element_of_a_list){
			int a,b,c; a=3; b=5; c=2;
			LList<int> list;
			list.append(&a);
			list.append(&b);
			list.append(&c);
			Assert::That(list.getData(1), Equals(&b));
			list.clear();
		}
		It(should_get_a_middle_element_of_a_list){
			int a,b,c; a=3; b=5; c=2;
			LList<int> list;
			list.append(&a);
			list.append(&b);
			list.append(&c);
			Assert::That(list.getData(2), Equals(&c));
			list.clear();
		}
	};
	Describe(addAll_method){
		It(should_add_all_elements_of_passed_list_to_the_list){
			int a,b,c,d,e; a=1; b=2; c=3; d=4; e=5;
			LList<int> list1;
			LList<int> list2;
			list1.append(&a);
			list1.append(&b);
			list1.append(&c);
			list2.append(&d);
			list2.append(&e);
			list1.addAll(&list2);
			Assert::That(list1.getSize(), Equals(5));
			Assert::That(list1.getData(0), Equals(&a));
			Assert::That(list1.getData(1), Equals(&b));
			Assert::That(list1.getData(2), Equals(&c));
			Assert::That(list1.getData(3), Equals(&d));
			Assert::That(list1.getData(4), Equals(&e));
			list1.clear();
			list2.clear();
		}
	};
	Describe(clear_method){
		It(should_clear_all_elements_from_a_list_without_destructing_them){
			int a,b,c; a=3; b=5; c=2;
			LList<int> list;
			list.append(&a);
			list.append(&b);
			list.append(&c);
			Assert::That(list.getSize(), Equals(3));
			list.clear();
			Assert::That(list.getSize(), Equals(0));
			Assert::That(a, Equals(3));
			Assert::That(b, Equals(5));
			Assert::That(c, Equals(2));
		}
	};
};

#endif
