#include <string>
#include <iostream>

class NamePrinter{

public:
    std::string name = "Felix";
    static void print_name(){
        // here we use the this pointer
        // inside an static member funtion 
        std::cout << this->name << std::endl;
    }
};

int main(void) {
   // create an object
   NamePrinter p;
   p.print_name();
   return 0;
}