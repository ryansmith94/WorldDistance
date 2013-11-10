#ifndef OptionsView_H
#define OptionsView_H
#include <sstream>
#include <iostream>

template <class OptionType>
class OptionsView {
    protected:
        OptionType* options;
        int numberOfOptions;
    public:
        OptionsView(OptionType* opts, int len);
        virtual OptionsView* display();
        int getOption();
        OptionType* getOptions();
};

#endif
