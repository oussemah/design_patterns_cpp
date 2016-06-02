
// STATES
enum ErrorState { ANALYZE=0, FIX, VERIFY, CLOSE };

// Command Class
class ErrorReport {
    private:
        ErrorState m_state;

    public:
        ErrorReport(ErrorState state);
        ErrorState GetState();
        void SetState(ErrorState state);
};

// General base class for all processing objects
class Error {
    protected:
        ErrorState m_state;
        Error*     m_successor;

    public:
        Error(ErrorState aState);
        void SetSuccessor (Error* error);

        virtual void ProcessError(ErrorReport& report) = 0;
};
