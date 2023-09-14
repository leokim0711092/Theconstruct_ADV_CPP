#include<iostream>
using namespace std;
 
class Icetray
{
private:
    int crystal;
public:
    Icetray(int x1) {
    crystal = x1;
    }
 
    // Copy constructor
    Icetray(const Icetray &Orange_old) {
    crystal = Orange_old.crystal;
    }
 
    int getCount(){
    return crystal;
    }

};
 
int main()
{
    Icetray Orange_old(5); // Normal constructor is called here
    Icetray Orange_new = Orange_old; // Copy constructor is called here
 
    // Let us access values assigned by constructors
    cout << "Old object: " << Orange_old.getCount() << endl;
    cout << "New object: " << Orange_new.getCount() << endl;
 
    return 0;
}