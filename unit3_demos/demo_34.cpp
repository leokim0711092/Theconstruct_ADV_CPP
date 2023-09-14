#include<iostream>

class IceTray{
    public:
    // member variable initialization
    std::string crab_shape = "Frozen";

};

int main(){

  // default constructor call
  IceTray orange_juice;
  std::cout << orange_juice.crab_shape << std::endl;
  return 0;
}