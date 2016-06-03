#include "Decorator.h"

#include <iostream>

ObjectInterface::ObjectInterface()
{
}

SimpleObject::SimpleObject(int id)
{
    m_id = id;
    std::cout << "Simple Object Created" << std::endl;
}

void SimpleObject::foo()
{
     std::cout << "My ID is :" << m_id << std::endl;
}

DecoratorObject::DecoratorObject()
{
    m_obj = 0;
    m_name = "";
    std::cout << "Decorator Object Created" << std::endl;
}

void DecoratorObject::SetSimpleObject(SimpleObject* obj)
{
    if (m_obj != 0)
    {
        delete m_obj;
    }
    m_obj = obj;
}

void DecoratorObject::foo()
{
    m_obj->foo();
    std::cout << m_name << std::endl;
}

void DecoratorObject::bar(std::string name)
{
    m_name = name;
}

extern "C" void test_decorator()
{
    SimpleObject* simple = new SimpleObject(0);
    DecoratorObject* augmented = new DecoratorObject();
    augmented->SetSimpleObject(simple);
    augmented->bar("augmented");
    augmented->foo();
}
