#include<iostream>

class Father {
public:
    virtual void run()
    {
        std::cout << "Father is running" << std::endl;
    }
};

class Son : public Father {
public:
    void run()
    {
        std::cout << "Son is running" << std::endl;
    }

};

int main()
{
    Father father;
    Son son;

    father.run();
    son.run();

    return 0;
}