// g++ -std=c++11 Adapter.cpp -o Adapter
#include <iostream>

class ExecutiveInterface {
public:
    virtual ~ExecutiveInterface(){}
    virtual void execute() = 0;
};

template <typename T>
class ExecutiveAdapter : public ExecutiveInterface 
{
public:
    ExecutiveAdapter (T * object_, void (T::*method_)() )
    :   object (object_)
    ,   method (method_)
    {}
    
    ~ExecutiveAdapter()
    {   delete object; object=nullptr;  }
    
    void    execute () 
    {   (object->*method)();  }

protected:
    T * object;
    void (T::*method)();
};

class IncompatibleClass {

public:
    void run() {
        std::cout <<__PRETTY_FUNCTION__<<std::endl;
    }

};

int main()
{
    ExecutiveAdapter <IncompatibleClass> EA(new IncompatibleClass, &IncompatibleClass::run);
    
    EA.execute();

}
