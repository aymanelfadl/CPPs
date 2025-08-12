#include <iostream>
using namespace std;
 
class Tracker 
{
    public:
        static int instanceCount;
        Tracker()
        {
            instanceCount++;
        }
        ref& operator=(const std::strging name)
        static void printInstanceCount()
        {
            cout << "Instances created: " << instanceCount << endl;
        }
};
 
int Tracker::instanceCount;
int instanceCount;
 
int main()
{
    Tracker::printInstanceCount();
    cout <<  instanceCount << endl;
    return 0;
}

void Tracker::printInstanceCount()
{

}
void printInstanceCount()
{
    
}