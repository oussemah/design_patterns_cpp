#include "Observer.h"

#include <iostream>

Observable* Observable::instance = 0;

Observable::Observable()
{
    std::cout << "Observable created" << std::endl;
}

Observable* Observable::GetInstance()
{
    if (Observable::instance == 0)
    {
        Observable::instance = new Observable();
    }
    return Observable::instance;
}

void Observable::addObserver(Observer* obs)
{
    observers.insert(obs);
}

void Observable::removeObserver(Observer* obs)
{
    observers.erase(obs);
}

void Observable::NotifyObservers()
{
    std::set<Observer*>::iterator itr;
    for (itr = observers.begin();
         itr != observers.end();
         itr++)
    {
        (*itr)->Notify();
    }
}

extern "C" void test_observer()
{
    class EventWatcher : public Observer {
        void Notify() {
            std::cout << "I am aware of the event now!" << std::endl;
        }
    };
    Observable* observable = Observable::GetInstance();
    for (int i=0; i<3; i++)
    {
        observable->addObserver(new EventWatcher());
    }
    observable->NotifyObservers();

    delete observable; //EventWatcher are not yet cleaned here !!
}
