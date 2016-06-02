#include <iostream>

class VisitorInterface;

class DataInterface
{
    public:
        virtual void accept(VisitorInterface* visitor);
        virtual void SetData(std::string str) = 0;
        virtual std::string Data() = 0;
};

class VisitorInterface
{
    public:
        virtual void visit(DataInterface* object) = 0;
};
