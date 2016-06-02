#include "Adapter.h"

#include <cstdlib>

// Interface needed adapting
AdaptationNeeder::AdaptationNeeder()
{
    m_initial_value = std::string("0");
}

void AdaptationNeeder::func_need_adaptation(const char* str)
{
    m_initial_value = std::string(str);
}

std::string AdaptationNeeder::GetInitialValue()
{
    return  m_initial_value;
}

// Interface to which we want to adapt the first one (target interface)
AdaptationTarget::AdaptationTarget(int initial_value)
{
    m_initial_val = initial_value;
}

int AdaptationTarget::GetInitialValue()
{
    return m_initial_val;
}

// Adapter Class
Adapter::Adapter(int initial_value) : AdaptationNeeder()
{
    m_initial_val = initial_value;
}

Adapter::Adapter(AdaptationNeeder& obj)
{
    m_initial_val = atoi(obj.GetInitialValue().c_str());
}

void Adapter::func_i_want_to_use(std::string str)
{
    func_need_adaptation(str.c_str());
}

int Adapter::GetInitialValue()
{
    return atoi(m_initial_value.c_str());
}

void foo(AdaptationTarget* newObj)
{
    std::cout << "Function using new generation of objects : " << newObj->GetInitialValue() << std::endl;
}

extern "C" void test_adapter()
{
    AdaptationNeeder oldObj;
    Adapter adaptationObject(oldObj);
    adaptationObject.func_i_want_to_use(std::string("12"));
    foo(&adaptationObject);
}
