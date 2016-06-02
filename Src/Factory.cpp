#include "Factory.h"

#include <string>

Mobile::Mobile(std::string model) : m_model(model)
{
    std::cout << "New mobile created (" << m_model << ")" << std::endl;
}

LowEndMobile::LowEndMobile(std::string model) : Mobile(model)
{
}

std::string LowEndMobile::Specs()
{
    return std::string("lowend_").append(m_model);
}

HighEndMobile::HighEndMobile(std::string model) : Mobile(model)
{
}

std::string HighEndMobile::Specs()
{
    return std::string("highend_").append(m_model);
}

Mobile* MobileFactory::GetMobile(std::string model)
{
    if (model == std::string("2g"))
    {
        return new LowEndMobile(model);
    } else if (model == std::string("3g"))
    {
        return new HighEndMobile(model);
    }
    std::cout << "Unknown mobile model : " << model << std::endl;
    return 0;
}

extern "C" void test_factory()
{
    Mobile* mobile = MobileFactory::GetMobile(std::string("3g"));

    if (mobile != 0)
    {
        std::cout << "Mobile : " << mobile->Specs().c_str() << std::endl;
    }

    delete mobile;
}
