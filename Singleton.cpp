// g++ -std=c++11 Singleton.cpp -o Singleton

#include <iostream>

template <class T>
class Singleton {

public:
    static T * get_instance() 
    {
        if (p_instance==nullptr)
            p_instance = new T;
            
        return p_instance;
    }

    ~Singleton()
    {
        if (p_instance!=nullptr)
        {
            delete p_instance;
            p_instance = nullptr;
        }
    }
protected:
    static T * p_instance;

};
template<class T> T* Singleton<T>::p_instance=nullptr;


int main()
{
    Singleton<int> S;
    
    (*Singleton<int>::get_instance())=10;
    std::cout <<"Instance value: "<<(*Singleton<int>::get_instance())<<"\n";
    
}

