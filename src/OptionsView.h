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
        OptionsView* display();
        virtual int getOption();
        virtual OptionType* getOptions();
};

#endif
