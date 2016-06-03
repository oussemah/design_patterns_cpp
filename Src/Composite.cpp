#include "Composite.h"


void CompositeInterface::foo()
{
    for (std::list<ObjectInterface*>::iterator it = m_CompositeObjs.begin(); it != m_CompositeObjs.end(); it++)
    {
        (*it)->foo();
    }
}

std::string CompositeInterface::bar()
{
    std::string ret = "";
    for (std::list<ObjectInterface*>::iterator it = m_CompositeObjs.begin(); it != m_CompositeObjs.end(); it++)
    {
        ret += (*it)->bar();
    }
    return ret;
}

void CompositeInterface::addChild(ObjectInterface* child)
{
    m_CompositeObjs.push_back(child);
}

void CompositeInterface::removeChild(ObjectInterface* child)
{
    //Do we need to destory the child manually here ?
    m_CompositeObjs.remove(child);
}

ObjectInterface* CompositeInterface::getChild(int idx)
{
    int id = 0;
    std::list<ObjectInterface*>::iterator it = m_CompositeObjs.begin();

    while (id < idx && 
           it != m_CompositeObjs.end())
    {
        it++;
        id++;
    }
    if (id < idx)
    {
        return 0;
    }
    std::cout << "Found object at index " << idx << std::endl;
    return *(it);
}

extern "C" void test_composite()
{
    class Motor : public ObjectInterface
    {
        public:
            void foo()
            {
                std::cout << "Motor foo()" << std::endl;
            }
            std::string bar()
            {
                return std::string("Motor bar()");
            }
    };
    class Wire : public ObjectInterface
    {
        public:
            void foo()
            {
                std::cout << "Wire foo()" << std::endl;
            }
            std::string bar()
            {
                return std::string("Wire bar()");
            }
    };

    CompositeInterface *repository = new CompositeInterface();
    repository->addChild(new Motor());
    repository->addChild(new Wire());
    repository->foo();
    std::cout << repository->bar() << std::endl;
    delete (repository->getChild(1)); //Remove Motor
    delete (repository->getChild(0)); //Remove Wire
    delete repository;
}
