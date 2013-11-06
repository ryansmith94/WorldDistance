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
        OptionsView(OptionType* opts, int len) {
            options = opts;
            numberOfOptions = len;
        }
        OptionsView* display() {
            for (int i = 0; i < numberOfOptions; i += 1) {
                cout << "\t" << i + 1 << ". " << options[i] << LF;
            }
            cout << LF;
            return this;
        }
        virtual int getOption() {
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
        virtual OptionType* getOptions() {
            return options;
        }
};

#endif
