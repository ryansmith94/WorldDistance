#include "igloo/igloo_alt.h"
#include "fstream"
using namespace igloo;

#include "../src/core.cpp"


class ChangeStdIO {
		std::streambuf *cinbuf;
		std::streambuf *coutbuf;
	public:
		ChangeStdIO(char inFile[], char outFile[]) {
			// Get file streams.
			std::ifstream inStream(inFile);
			std::ofstream outStream(outFile);

			// Store the standard buffers for resetting.
			cinbuf = std::cin.rdbuf();
			coutbuf = std::cout.rdbuf();

			// Redirect the buffers to the files.
		    std::cin.rdbuf(inStream.rdbuf());
		    std::cout.rdbuf(outStream.rdbuf());
		}
		~ChangeStdIO() {
			// Redirect the buffers back to the originals.
			std::cin.rdbuf(cinbuf);
    		std::cout.rdbuf(coutbuf);

    		// Free memory.
			delete cinbuf;
			delete coutbuf;
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
			ChangeStdIO* io = new ChangeStdIO("out.txt", "../test/in.txt");

			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			view->getOption();

			delete io;
		}
		It(should_accept_valid_option) {
			ChangeStdIO* io = new ChangeStdIO("out.txt", "../test/in.txt");

			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			view->getOption();

			delete io;
		}
		It(should_reject_invalid_option) {
			ChangeStdIO* io = new ChangeStdIO("out.txt", "../test/in.txt");

			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			view->getOption();

			delete io;
		}
		It(should_return_valid_option) {
			ChangeStdIO* io = new ChangeStdIO("out.txt", "../test/in.txt");

			int opts[] = {0, 1, 2};
			OptionsView<int>* view = new OptionsView<int>(opts, 3);
			view->getOption();

			delete io;
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