#include "Visitor.h"

#include <algorithm>

void DataInterface::accept(VisitorInterface* visitor)
{
    visitor->visit(this);
}

extern "C" void test_visitor()
{
    class DataObject : public DataInterface
    {
        private:
            std::string m_name;

        public:
            void SetData(std::string str)
            {
                m_name = str;
            }
            std::string Data()
            {
                return m_name;
            }
    };
    class Scrambler : public VisitorInterface
    {
        public:
            void visit(DataInterface* data)
            {
                std::string tmp = data->Data();
                std::reverse(tmp.begin(), tmp.end());
                data->SetData(tmp);
            }
    };

    DataObject data;
    data.SetData("Test");
    Scrambler visitor;
    data.accept(&visitor);
    std::cout << data.Data() << std::endl;
}
