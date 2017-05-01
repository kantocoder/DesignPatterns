// g++ -std=c++11 Decorator.cpp -o Decorator

#include <iostream>

class Widget 
{
public:
    virtual void draw() = 0;
};


class Window : public Widget 
{

public:
    void draw()
    {   std::cout <<"Drawing window\n";    }
};

class Decorator : public Widget 
{
public:

    Decorator (Widget * widget_) : widget (widget_) {}

    void draw() 
    {
        widget->draw();
    }

protected:
    Widget * widget;

};

class FrameDecorator : public Decorator 
{
public:
    FrameDecorator (Widget * widget_) : Decorator (widget_)
    {}

    void draw ()
    {
        Decorator::draw();
        std::cout << "Draw Frame\n";
    }
};

class ScrollBarDecorator : public Decorator 
{
public:
    ScrollBarDecorator (Widget * widget_) : Decorator (widget_)
    {}

    void draw ()
    {
        Decorator::draw();
        std::cout << "Draw ScrollBar\n";
    }
};

template <typename T>
class StaticDecorator : public T
{
public:
    StaticDecorator(Widget * widget_) : T(widget_)
    {}
    
    void draw()
    {
        T::draw();
        std::cout<<"Drawing: "<<__PRETTY_FUNCTION__<<std::endl;
    }
};


int main()
{
    Widget * wid = new StaticDecorator<Decorator>(new FrameDecorator(new ScrollBarDecorator(new Window())));
    
    wid->draw();
}
