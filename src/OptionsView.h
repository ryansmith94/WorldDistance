#ifndef OptionsView_H
#define OptionsView_H
#include <sstream>
#include <iostream>
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

/**
 * @author Ryan Smith, Oliver Parker
 */
template <class OptionType>
class OptionsView {
    protected:
        OptionType* options;
        int numberOfOptions;
    public:
        /**
         * Constructs a OptionsView.
         * @param opts an array of options.
         * @param len the number of options (length of the opts array).
         * @pre opts is an array (to allow them to be iterated using `[]` syntax).
         * @pre opts != NULL.
         * @post constructed OptionsView with options and a number of options.
         */
        OptionsView(OptionType* opts, int len);

        /**
         * Displays the options (options and exit).
         * @post options (options and exit) printed to `cout`.
         */
        OptionsView* display();

        /**
         * Gets a valid option.
         * Asks the user for input using `cout` and get their chosen option via `cin`.
         * @param message (optional) a message to print to request input. Defaults to "" (empty string).
         * @return the index of the selected option in options.
         */
        int getOption(string message = "");

        /**
         * Returns all of the options.
         * @return options.
         */
        OptionType* getOptions();
};

template <class OptionType>
OptionsView<OptionType>::OptionsView(OptionType* opts, int len) {
    options = opts;
    numberOfOptions = len;
}

template <class OptionType>
OptionsView<OptionType>* OptionsView<OptionType>::display() {
    // Output the addresses of all of the places to cout.
    for (int i = 0; i < numberOfOptions; i += 1) {
        cout << "\t" << i + 1 << ". " << options[i] << LF;
    }

    // Output the Exit option to cout.
    cout << "\t" << numberOfOptions + 1 << ". Exit" << LF << LF;
    return this;
}

template <class OptionType>
int OptionsView<OptionType>::getOption(string message) {
    int selected = -1;
    string input;

    // Keep getting the user to enter an option until it is within the valid range.
    do {
        // Ask the user for input.
        if (message == "") {
            cout << "<\tPlease select an option (1-" << numberOfOptions + 1 << "): ";
        } else {
            cout << "<\t" << message << ": ";
        }

        // Using getLine and stringstream to insure that the input was of type int.
        getline(cin, input);
        stringstream myStream(input);
        myStream >> selected;
        
    } while (selected < 1 || selected > numberOfOptions + 1);

    return (selected - 1);
}

template <class OptionType>
OptionType* OptionsView<OptionType>::getOptions() {
    return options;
}

#endif
