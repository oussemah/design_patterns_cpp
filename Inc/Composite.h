/*
 * Composite design pattern handles the use-case where we want
 * a group of objects to be treated in the same way as a single object
 */
#include <list>
#include <iostream>

class ObjectInterface
{
    public:
        virtual void foo() = 0;
        virtual std::string bar() = 0;
};

class CompositeInterface
{
    public:
        void foo();
        std::string bar();
        void addChild(ObjectInterface* child);
        void removeChild(ObjectInterface* child);
        ObjectInterface* getChild(int idx);

    private:
        std::list<ObjectInterface*> m_CompositeObjs;
};
