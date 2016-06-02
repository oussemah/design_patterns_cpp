#include "Singleton.h"

#include <iostream>

Singleton* Singleton::instance = 0;

Singleton::Singleton()
{
    std::cout << "Instance created" << std::endl;
}

Singleton* Singleton::GetInstance()
{
    if (Singleton::instance == 0)
    {
        instance = new Singleton();
    }
    return Singleton::instance;
}

void Singleton::Description()
{
    std::cout << "I am the only instance of Singleton class" << std::endl;
}

extern "C" void test_singleton()
{
    Singleton* object = Singleton::GetInstance();
    object->Description();
    Singleton second_instance = *object; /* Does not work if we put Copy Constructor as private */

    delete object;
}
