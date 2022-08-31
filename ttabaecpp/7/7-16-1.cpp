#include <iostream>
#include <string>
using namespace std;

double findAverage(int count, ...)
{
    double sum = 0;
    va_list list;
    va_start(list, count);
    for (int arg = 0 ; arg < count ; ++arg)
        sum += va_arg(list, int);

    va_end(list);
    return (sum / count);
}

int main(int argc, char *argv[])
{
    cout << findAverage(1, 1, 1, 3, "hello", 'c') << endl;
    cout << findAverage(1, 1, 2, 1) << endl;
    cout << findAverage(5, 5, 5, 5) << endl;
    return (0);
}