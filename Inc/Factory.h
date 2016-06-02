#include <iostream>

class Mobile {
    public:
        Mobile(std::string model);
        virtual std::string Specs() = 0;

    protected:
        std::string m_model;
};

class LowEndMobile : public Mobile
{
    public:
        LowEndMobile(std::string model);
        std::string Specs();
};

class HighEndMobile : public Mobile
{
    public:
        HighEndMobile(std::string model);
        std::string Specs();
};

class MobileFactory
{
    public:
        static Mobile* GetMobile(std::string model);
};
