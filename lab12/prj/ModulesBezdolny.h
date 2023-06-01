#ifndef MODULESBEZDOLNY_H_INCLUDED
#define MODULESBEZDOLNY_H_INCLUDED

#include <cmath>

class ClassLab12_Bezdolny{
public:
    ClassLab12_Bezdolny(){}
    ClassLab12_Bezdolny(float radius);
    void setRadius(float radius);
    float getRadius();
    float getVolumeBall();
private:
    float radius = 0.0;
};

ClassLab12_Bezdolny::ClassLab12_Bezdolny(float radius){
    this->radius = radius;
}

void ClassLab12_Bezdolny::setRadius(float radius){
    this->radius = radius;
}

float ClassLab12_Bezdolny::getRadius(){
    return radius;
}

float ClassLab12_Bezdolny::getVolumeBall(){
    return (4 * M_PI * pow(radius, 3))/3;
}

#endif // MODULESBEZDOLNY_H_INCLUDED