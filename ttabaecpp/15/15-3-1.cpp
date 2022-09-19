//#include "timer.h"
#include "AutoPtr2.h"
#include "Resource.h"

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000));
    return (res);
}

int main(void)
{
    using namespace std;
    //streambuf* orig_buf = cout.rdbuf();
    //cout.rdbuf(NULL); // disconnect cout from buffer
    //Timer timer;
    {
        AutoPtr<Resource> main_res;
        main_res = generateResource();
    }
    //cout.rdbuf(orig_buf);
    //cout << timer.elapsed() << endl;
    return (0);
}