/* Hide the complexity of [a] complex librar[y|ies] behind a simple interface
 */

class LibClass1
{
    public:
        bool foo();
        void bar();
};

class LibClass2
{
    public:
        bool foo();
        void bar();
        void intermediate();
};

class Facade
{
    public:
        void easyFoo();
};
