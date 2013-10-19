#include "igloo/igloo_alt.h"
using namespace igloo;

#include "../src/core.cpp"

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
		It(should_print_options) {

		}
		It(should_return_options_view) {
			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			Assert::That(view->display(), Equals(view));
		}
	};
	Describe(getOption_method) {
		It(should_ask_user_for_option) {

			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			view->getOption();

		}
		It(should_accept_valid_option) {

			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			view->getOption();

		}
		It(should_reject_invalid_option) {

			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			view->getOption();

		}
		It(should_return_valid_option) {

			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			view->getOption();

		}
	};
	Describe(getOptions_method) {
		It(should_return_all_of_the_options) {
			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			Assert::That(view->getOptions()[0], Equals(0));
			Assert::That(view->getOptions()[1], Equals(1));
			Assert::That(view->getOptions()[2], Equals(2));
		}
	};
};

int main(int argc, const char *argv[]) {
    return TestRunner::RunAllTests(argc, argv);
}