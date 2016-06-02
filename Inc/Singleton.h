
class Singleton
{
    public:
        static Singleton* GetInstance();
        void Description();

    private:
        static Singleton* instance;
        Singleton();
        //Singleton(Singleton&); /* To prohibit getting instances outside of GetInstance() */
};
