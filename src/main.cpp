#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "I work... for now >;)" << endl;

	// Demonstration of OptionsView
	cout << endl << "Just testing the OptionsView class ;)" << endl;
	string opts[] = {"Option 1", "Option 2", "Quit"};
	OptionsView<string>* o = new OptionsView<string>(opts, sizeof(opts) / sizeof(string));
	cout << o->display()->getOption() << endl; // Notice that you can chain calls `display()->getOption()`

	return 0;
}