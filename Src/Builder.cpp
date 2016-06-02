#include "Builder.h"

void ComplexObject::Describe()
{
    std::cout << m_name << ":" << std::endl;
    while ( !m_items.empty() )
    {
        std::cout << "\t" << m_items.front() << std::endl;
        m_items.pop();
    }
}

void ComplexObject::AddItem(std::string newItem)
{
    m_items.push(newItem);
}

void ComplexObject::SetName(std::string name)
{
    m_name = name;
}

ComplexObject::~ComplexObject()
{
    while ( !m_items.empty() )
    {
        m_items.pop();
    }
}

void ObjectBuilder::SetObjectName(std::string name)
{
    m_object->SetName(name);
}

void ObjectBuilder::SetObject(ComplexObject* obj)
{
    m_object = obj;
}

extern "C" void test_builder()
{
    class CarBuilder : public ObjectBuilder
    {
        public:
            void prepareCore()
            {
                m_object->AddItem("Diezel Motor");
                m_object->AddItem("Cut Frame");
                m_object->AddItem("Central Calculator");
                m_object->AddItem("4 Tires");
            }
            void prepareAccessories()
            {
                m_object->AddItem("Leather Driver Board");
                m_object->AddItem("Air Conditonner");
            }
    };
    class BikeBuilder : public ObjectBuilder
    {
        public:
            void prepareCore()
            {
                m_object->AddItem("Bike Frame");
                m_object->AddItem("2 Tires");
            }
            void prepareAccessories()
            {
                m_object->AddItem("Back light");
            }
    };

    ComplexObject* bmw_car = new ComplexObject();
    CarBuilder* BMW_Builder = new CarBuilder();
    BMW_Builder->SetObject(bmw_car);
    BMW_Builder->SetObjectName(std::string("BMW Car"));
    BMW_Builder->prepareCore();
    BMW_Builder->prepareAccessories();
    bmw_car->Describe();
    ComplexObject* bike = new ComplexObject();
    BikeBuilder* yamahaBuilder = new BikeBuilder();
    yamahaBuilder->SetObject(bike);
    yamahaBuilder->SetObjectName(std::string("Yamaha Bike"));
    yamahaBuilder->prepareCore();
    yamahaBuilder->prepareAccessories();
    bike->Describe();
    delete BMW_Builder;
    delete yamahaBuilder;
    delete bmw_car;
    delete bike;
}
