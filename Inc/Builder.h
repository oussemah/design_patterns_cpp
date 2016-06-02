/*
 * Handle the building of a complex object
 * Separate the construction of an object from its representation
 */
#include <iostream>
#include <queue>

class ComplexObject
{
    public:
        ~ComplexObject();
        void AddItem(std::string newItem);
        void Describe();
        void SetName(std::string name);

    private:
        std::queue<std::string> m_items;
        std::string m_name;
};

class ObjectBuilder
{
    public:
        void SetObject(ComplexObject* obj);
        void SetObjectName(std::string);
        virtual void prepareCore() = 0;
        virtual void prepareAccessories() = 0;

    protected:
        ComplexObject* m_object;
};
