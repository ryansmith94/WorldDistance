#ifndef OptionsView_H
#define OptionsView_H
#include <sstream>
#include <iostream>
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

template <class OptionType>
class OptionsView {
    protected:
        OptionType* options;
        int numberOfOptions;
    public:
        OptionsView(OptionType* opts, int len);
        OptionsView* display();
        int getOption(string message = "");
        OptionType* getOptions();
};

template <class OptionType>
OptionsView<OptionType>::OptionsView(OptionType* opts, int len) {
    options = opts;
    numberOfOptions = len;
}

template <class OptionType>
OptionsView<OptionType>* OptionsView<OptionType>::display() {
    for (int i = 0; i < numberOfOptions; i += 1) {
        cout << "\t" << i + 1 << ". " << options[i] << LF;
    }
    cout << LF;
    return this;
}

template <class OptionType>
int OptionsView<OptionType>::getOption(string message) {
    int selected = -1;
    string input;

    do {
        if (message == "") {
            cout << "<\tPlease select an option (1-" << numberOfOptions << "): ";
        } else {
            cout << "<\t" << message << ": ";
        }
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
