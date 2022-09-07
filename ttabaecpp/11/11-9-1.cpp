#include <iostream>
using namespace std;

class USBDevice
{
private:
    long m_id;
public:
    USBDevice(long id)
        : m_id(id) {}
    long getId()
    {
        return (m_id);
    }
    void plugAndPlay() {}
};

class NetworkDevice
{
private:
    long m_id;
public:
    NetworkDevice(long id)
        : m_id(id) {

        }
    long getId()
    {
        return (m_id);
    }
    void networking() 
    {

    }
};

class USBNetwrokDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetwrokDevice(long usb_id, long net_id)
        : USBDevice(usb_id), NetworkDevice(net_id)
        {}
    
};

int main(void)
{
    USBNetwrokDevice ud(1,2);

    ud.USBDevice::getId(); // 다중 상속된 맴버 변수/함수 중 중복되는 이름은 클래스명 과 함께 구분하여 사용할 수 있다.
    return (0);
}