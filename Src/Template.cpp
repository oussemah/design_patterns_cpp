#include "Template.h"

#include <iostream>

void Account::Initialize(int id)
{
     foo();
     std::cout << "ID : " << id << std::endl;
     bar();
}

extern "C" void test_template()
{
    // Derived Class
    class ManagerAccount : public Account
    {
        void foo() { std::cout << "foo function" << std::endl; }
        void bar() { std::cout << "bar function" << std::endl; }
    };

    ManagerAccount manager;
    manager.Initialize(0);
}
