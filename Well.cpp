#include "Well.h"
#include "Point.h"
#include "GridCell.h"
#include <vector>
#include <fstream>
#include <iostream>

Well::Well():m_id(0)
{

}
Well::Well(unsigned int id, std::vector<Point> wellPoints)
{
    m_id=id;
    m_wellPoints=wellPoints;

}
unsigned int Well:: getWellId()
{
    return m_id;
}
void Well::dispWellId()
{
    std::cout<<"Well ID:"<<m_id<<std::endl;
}

void Well::dispWellPoints()
{
    for (int i=0; i<m_wellPoints.size(); i++)
    {
        std::cout<<"("<<m_wellPoints[i].Getx()<<",";
        std::cout<<m_wellPoints[i].Gety()<<",";
        std::cout<<m_wellPoints[i].Getz()<<")"<<std::endl;
    }

}

std::vector<Point> Well::getWellPoints()
{
    return m_wellPoints;
}





Well::~Well()
{
    //dtor
}
