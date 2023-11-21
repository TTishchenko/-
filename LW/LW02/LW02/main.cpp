//
//  main.cpp
//  LW02
//
//  Created by Tatiana on 11.12.2019.
//  Copyright © 2019 Tatiana. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <memory>

using namespace std;

class IOutput {
public:
    virtual void draw() = 0;
};

class WarriorVS: public IOutput {
    int _group, _power, _protection, _health, _skill, _deviation, _battle_type;
    string str;
    
public:
    WarriorVS(string s, int g, int p, int pr, int h, int sk, int d, int b) {
        str = s;
        _group = g;
        _power = p;
        _protection = pr;
        _health = h;
        _skill = sk;
        _deviation = d;
        _battle_type = b;
    }
    
    virtual void draw() override
    {
        cout << str << ": " << _group << ", " << _power << ", " << _protection << ", " << _health << _skill << ", " << _deviation << ", " << _battle_type << ", " << endl;
    }
};

class Decorator: public IOutput
{
    IOutput *wid;
    
public:
    Decorator(IOutput *w) : wid(w) {}
    
    virtual void draw() override
    {
        wid->draw();
    }
};

class SpecialDecorator: public Decorator
{
public:
    SpecialDecorator(IOutput *w): Decorator(w){}
    
    virtual void draw() override
    {
        Decorator::draw();
        
        cout << "   Редкая коллекция" << endl;
    }
};

class ConnectDecorator: public Decorator
{
public:
    ConnectDecorator(IOutput *w): Decorator(w){}
    
    virtual void draw() override
    {
        Decorator::draw();
        
        cout << "   Вместе с Лоцаном и Матросами увеличивается защита и сила удара" << endl;
    }
};

int main()
{
    IOutput *aWidget = new ConnectDecorator(new SpecialDecorator(new WarriorVS("Капитан", 1, 4, 8, 7, 9, 4, 2)));
    aWidget->draw();
}
