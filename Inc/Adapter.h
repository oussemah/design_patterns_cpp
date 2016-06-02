
#include <cstdio>
#include <iostream>

// Interface needed adapting
class AdaptationNeeder
{
    protected:
        std::string m_initial_value;

    public:
        AdaptationNeeder();
        void func_need_adaptation(const char* str);
        std::string GetInitialValue();
};

// Interface to which we want to adapt the first one (target interface)
class AdaptationTarget
{
    protected:
        int m_initial_val;

    public:
        AdaptationTarget(int initial_value);
        virtual void func_i_want_to_use(std::string string) = 0;
        int GetInitialValue();

        AdaptationTarget() { }; // Needed for double heritage fulfillement
};

// Adapter Class
class Adapter : public AdaptationNeeder, public AdaptationTarget
{
    public:
        Adapter(int initial_value);
        Adapter(AdaptationNeeder&);
        void func_i_want_to_use(std::string str);
        int GetInitialValue();
};
