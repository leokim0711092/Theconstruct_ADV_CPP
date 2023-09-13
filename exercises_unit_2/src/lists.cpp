#include <list>
#include <ros/ros.h>

int main(int argc, char **argv) {

  std::list<std::string> laser{"range_max", "range_min", "angle_max", "angle_min"};
  std::list<std::string>::iterator lt;
  lt = laser.begin();
  advance(lt, 2);
  std::cout << *lt << std::endl;

  lt = laser.end();
  lt = next(lt, -3);
  std::cout << *lt << std::endl;

}