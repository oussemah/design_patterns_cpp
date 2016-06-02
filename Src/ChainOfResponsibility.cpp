#include "ChainOfResponsibility.h"

#include <iostream>

// Command Class
ErrorReport::ErrorReport(ErrorState state)
{
    m_state = state;
}

ErrorState ErrorReport::GetState()
{
    return m_state;
}

void ErrorReport::SetState(ErrorState state)
{
    m_state = state;
}

// General base class for all processing objects
Error::Error(ErrorState aState)
{
    m_state = aState;
    m_successor = 0;
}

void Error::SetSuccessor (Error* error)
{
    m_successor = error;
}

extern "C" void test_chain_of_responsibility()
{
    // Processing class for state ANALYZE
    class AnalyzeError : public Error
    {
        public:
            AnalyzeError() : Error(ANALYZE) { };
            void ProcessError(ErrorReport& report)
            {
                if (report.GetState() == ANALYZE )
                {
                    std::cout << "AnalyzeError::Handled the command to analyze the error" << std::endl;
                    m_state = ANALYZE;
                } else if (m_successor != 0){
                    std::cout << "AnalyzeError::Passing to my successor" << std::endl;
                    m_successor->ProcessError(report);
                } else {
                    std::cout << "AnalyzeError::No successor --> No action required" << std::endl;
                }
            }
    };
    class FixError : public Error
    {
        public:
            FixError() : Error(FIX) { };
            void ProcessError(ErrorReport& report)
            {
                if (report.GetState() == FIX)
                {
                    std::cout << "FixError::Handled the command to fix the error" << std::endl;
                    m_state = FIX;
                } else if (m_successor != 0) {
                    std::cout << "FixError::Passing to my successor" << std::endl;
                    m_successor->ProcessError(report);
                } else {
                    std::cout << "FixError::No successor --> No action required" << std::endl;
                }
            }
    };

    // Create instances for processing objects
    AnalyzeError* analyzeError = new AnalyzeError();
    FixError*     fixError     = new FixError();

    // Create the chain of responsibility
    analyzeError->SetSuccessor(fixError);

    // Issue commands
    ErrorReport* errorReport = new ErrorReport(ANALYZE);
    analyzeError->ProcessError(*errorReport);

    errorReport->SetState(FIX);
    analyzeError->ProcessError(*errorReport);

    // Cleanup
    delete errorReport;
    delete fixError;
    delete analyzeError;
}
