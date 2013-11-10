#ifndef OptionsView_CPP
#define OptionsView_CPP
#include <sstream>
#include <iostream>
#include "OptionsView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

template <class OptionType>
OptionsView::OptionsView(OptionType* opts, int len) {
    options = opts;
    numberOfOptions = len;
}

template <class OptionType>
OptionsView* OptionsView::display() {
    for (int i = 0; i < numberOfOptions; i += 1) {
        cout << "\t" << i + 1 << ". " << options[i] << LF;
    }
    cout << LF;
    return this;
}

template <class OptionType>
virtual int OptionsView::getOption() {
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
virtual OptionType* OptionsView::getOptions() {
    return options;
}

#endif
