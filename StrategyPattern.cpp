//  compile: g++ -std=c++11 StrategyPattern.cpp -o StrategyPattern

#include <iostream>
#include <vector>

class IBehavior {
public:
    virtual void run () = 0;
};

class Client 
{

IBehavior & behavior;

public:

    Client (IBehavior & b_): behavior(b_)
    {
    }

    void execute () 
    {
        behavior.run();
    }
};

class Sleep : public IBehavior
{
    void run () override 
    {
        std::cout <<"Sleeping...\n";
    }
};

class Work : public IBehavior
{
    void run () override
    {
        std::cout <<"Working...\n";
    }
};


int main()
{
    Work    work;
    Sleep   sleep;
    
    std::vector<Client*> v_clients;//{new Client(work), new Client(sleep)};
    
    v_clients.push_back(new Client(work));
    v_clients.push_back(new Client(sleep));
    
    for (auto & c: v_clients)
        c->execute();
    
}
