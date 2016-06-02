
// Template Class
class Account {
    public:
        virtual void foo() = 0;
        virtual void bar() = 0;

        // Template Method
        void Initialize(int id);
};
