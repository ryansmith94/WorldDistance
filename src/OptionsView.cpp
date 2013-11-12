#include "OptionsView.h"
#ifndef LF
#define LF (char)0x0A
#endif
using namespace std;

template <class OptionType>
OptionsView<OptionType>* OptionsView<OptionType>::display() {
    for (int i = 0; i < numberOfOptions; i += 1) {
        cout << "\t" << i + 1 << ". " << options[i] << LF;
    }
    cout << LF;
    return this;
}
