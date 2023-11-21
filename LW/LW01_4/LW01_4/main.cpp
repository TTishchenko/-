/*
 MIT License
 
 Copyright (c) 2019 МГТУ им. Н.Э. Баумана, кафедра ИУ-6, Михаил Фетисов,
 
 Программа-заготовка для лабораторной работы
 */

#include <iostream>
#include <string>
#include <map>
#include <memory>

using namespace std;

class IOutput{
public:
    virtual ~IOutput() = default;
    virtual string getOutputString() const = 0;
};

class WarriorVS : public IOutput{
public:
    WarriorVS() = delete;
    WarriorVS & operator = (const WarriorVS & p) = delete;
    
    WarriorVS(int group, int power, int protection, int health, int skill, int deviation, int battle_type)
    : _group(group), _power(power), _protection(protection), _health(health), _skill(skill), _deviation(deviation), _battle_type(battle_type){}
    
    int getGroup() const { return _group;}
    int getPower() const { return _power; }
    int getProtection() const { return _protection; }
    int getHealth() const { return _health; }
    int getSkill() const { return _skill;}
    int getDeviation() const { return _deviation;}
    int getBattleType() const { return _battle_type;}
    
    virtual string getOutputString() const override{
        return to_string(_group) + " " + to_string(_power) + " " + to_string(_protection) + " " + to_string(_health) + " " + to_string(_skill) + " " + to_string(_deviation) + " " + to_string(_battle_type);
    }
    
private:
    int _group;
    int _power;
    int _protection;
    int _health;
    int _skill;
    int _deviation;
    int _battle_type;
};

int main(int , char **){
    map<string,unique_ptr<IOutput>> wvs;
    
    wvs["Юнга"s]     = make_unique<WarriorVS>(2, 2, 2, 5, 3, 2, 1);
    wvs["Капитан"s]    = make_unique<WarriorVS>(1, 10, 9, 10, 10, 10, 2);
    wvs["Лоцман"s]     = make_unique<WarriorVS>(3, 9, 9, 8, 9, 7, 2);
    wvs["Матрос"s]     = make_unique<WarriorVS>(1, 5, 5, 5, 5, 5, 1);
    
    for(const auto & [k,o] : wvs)
        cout << "\"" << k << "\": " << o->getOutputString() << endl;
    
    return 0;
}
