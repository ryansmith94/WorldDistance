#ifndef OptionsView_CPP
#define OptionsView_CPP
#include <sstream>
#include <iostream>
#include "OptionsView.h"
#define LF (char)0x0A
using namespace std;

template <class OptionType>
OptionsView<OptionType>::OptionsView(OptionType* opts, int len) {
    options = opts;
    numberOfOptions = len;
}

template <class OptionType>
OptionsView* OptionsView<OptionType>::display() {
    for (int i = 0; i < numberOfOptions; i += 1) {
        cout << "\t" << i + 1 << ". " << options[i] << LF;
    }
    cout << LF;
    return this;
}

template <class OptionType>
int OptionsView<OptionType>::getOption() {
    int selected = -1;
    string input;

    do {
        cout << "<\tPlease select an option (1-" << numberOfOptions <<  "): ";
        getline(cin, input);
        stringstream myStream(input);
        myStream >> selected;
    } while (selected < 1 || selected > numberOfOptions);

    return (selected - 1);
}

template <class OptionType>
OptionType* OptionsView<OptionType>::getOptions() {
    return options;
}

#endif
