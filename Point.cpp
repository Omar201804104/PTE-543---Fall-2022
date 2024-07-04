#include "Point.h"
#include <fstream>
#include <vector>
#include <iostream>


Point::Point()
{
   m_x=0;
   m_y=0;
   m_z=0;

    //ctor
}
Point::Point(double x,double y,double z)
{
    m_x=x;
    m_y=y;
    m_z=z;
}
double Point::Getx()
{
    return m_x;
}
void Point::Setx(double x)
{
    m_x=x;
}
double Point::Gety()
{
    return m_y;
}
void Point::Sety(double y)
{
    m_y=y;
}
double Point::Getz()
{
    return m_z;
}
void Point::Setz(double z)
{
    m_z=z;
}
double Point::addPoint()
{
    return m_x+m_y+m_z;
}
void Point::dispCoordinates()
{
    std::cout<<m_x<<std::endl;
    std::cout<<m_y<<std::endl;
    std::cout<<m_z<<std::endl;
    std::cout<<std::endl;
}

Point::~Point()
{
    //dtor
}
