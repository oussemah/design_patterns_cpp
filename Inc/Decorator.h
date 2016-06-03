/*
 * Decorator design pattern is useful when we want to add capabilities
 * to an object without subclassing the concrete object or affecting other
 * objects from same class
 */
#include <iostream>

class ObjectInterface
{
    public:
        ObjectInterface();
        virtual void foo() = 0;
};

class SimpleObject : public ObjectInterface
{
    public:
        SimpleObject(int id);
        void foo();

    private:
        int m_id;
};

/* We want to have another type of objects that have bar() capability */
class DecoratorObject : public ObjectInterface
{
    public:
        DecoratorObject();
        void foo();
        void SetSimpleObject(SimpleObject* object);
        void bar(std::string name);

    private:
        SimpleObject* m_obj;
        std::string m_name;
};
