#include <set>

class Observer
{
    public:
        virtual void Notify() = 0;
};

class Observable
{
    private:
        static Observable* instance;
        std::set<Observer*> observers;

        Observable();

    public:
        static Observable* GetInstance();
        void addObserver(Observer*);
        void removeObserver(Observer*);

        void NotifyObservers();
};
