#include <iostream>
#include <vector>

using namespace std;

void    countDown(int count)
{
    cout << count << endl;
    if (count > 0)
        countDown(count - 1);
}
int main(void)
{
    countDown(5);
    return (0);
}