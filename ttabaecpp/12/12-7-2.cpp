#include <iostream>
using namespace std;


class IErrorLog
{
public:
    virtual bool reportError(const char * errorMessage) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char * errorMessage) override
    {
        cout << "writing error to a file" << endl;
        return (true);
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char * errorMessage) override
    {
        cout << "printing error to a console" << endl;
        return (true);
    }
};

void    doSomething(IErrorLog &log)
{
    log.reportError("runtime error!!");
}

int main(void)
{
    FileErrorLog file_log;
    ConsoleErrorLog console_log;
    doSomething(file_log);
    doSomething(console_log);
    cout << typeid(file_log).name() << " " << sizeof file_log << endl;
    cout << typeid(console_log).name() << " " << sizeof console_log << endl;
    IErrorLog &a0 = file_log;
    doSomething(a0);
    cout << &a0 << endl;
    cout << &file_log << endl;

    
    cout << "=======================" << endl;
    IErrorLog *a = new FileErrorLog;
     cout << typeid(a).name() << " " << sizeof a << endl;
    a->reportError("wg");
    doSomething(*a);
    return (0);
}