#include "Facade.h"

#include <iostream>

bool LibClass1::foo()
{
    std::cout << "foo 1" << std::endl;
    return false;
}

void LibClass1::bar()
{
    std::cout << "bar 1" << std::endl;
}

bool LibClass2::foo()
{
    std::cout << "foo 2" << std::endl;
    return true;
}

void LibClass2::bar()
{
    std::cout << "bar 2" << std::endl;
}

void LibClass2::intermediate()
{
    std::cout << "intermediate" << std::endl;
}

/* This method covers all the complexity of handling different scenarios
 * from lib classes */
void Facade::easyFoo()
{
    LibClass1 *obj1 = new LibClass1();
    if (obj1->foo())
    {
        obj1->bar();
    } else {
        LibClass2 *obj2 = new LibClass2();
        if (obj2->foo())
        {
            obj2->bar();
        } else {
            obj2->intermediate();
            obj2->bar();
        }
    }
}

extern "C" void test_facade()
{
    Facade* facadeObj = new Facade();
    facadeObj->easyFoo();
    delete facadeObj;
}
