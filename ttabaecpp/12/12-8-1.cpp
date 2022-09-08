#include <iostream>
using namespace std;

class PoweredDevice
{
public:
    int m_i;
    PoweredDevice() {
        cout << "default powerdevice " << endl;
    }
    PoweredDevice(int power)
    {
        cout << "powerdevice: "  << power << endl;
    }
};

class Scanner : virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        :PoweredDevice(power)
    {
        cout << "scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power)
    {
        cout << "printer: " << printer << '\n';
    }
};

class Copier : virtual public Printer, virtual public Scanner
{
public:
    Copier(int scanner, int printer, int power)
        : Printer(printer, power) , Scanner(scanner, power) //, PoweredDevice(power)
    {
    }
};

int main(void)
{
    Copier copy(1,2,3);
    //cout << (&copy).Scanner << endl;
    //Scanner::PoweredDevice::m_i
    cout << &copy.Scanner::PoweredDevice::m_i << endl;
    cout << &copy.Printer::PoweredDevice::m_i << endl;
    return (0);
}