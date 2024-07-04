#include "GridCell.h"
#include "Point.h"
#include <vector>
#include <fstream>
#include <iostream>

GridCell::GridCell():m_id(0),m_myPoints(0)
{


}
GridCell::GridCell(unsigned int id,std::vector<Point> gridCellPoints)
{
    m_id=id;
    m_myPoints= gridCellPoints;
}
void GridCell::dispCellId() /*display on console the Cell Id*/
{
    std::cout<<"Cell ID:"<<m_id<<std::endl;
}
void GridCell::setCellId(unsigned int id)/*set the cell Id*/
{
    m_id=id;
}
unsigned int GridCell::getCellId()/*get the Cell Id*/
{
    return m_id;
}
void GridCell::addPoint(Point myPoint) /*add a point to the Cell*/
{
    m_myPoints.push_back(myPoint);
}

void GridCell::dispCellPoints() /*display on console the coords of each point in the Cell*/
{
    for (int i=0;i<=7;i++)
    {
        std::cout<<"("<<m_myPoints[i].Getx()<<",";
        std::cout<<m_myPoints[i].Gety()<<",";
        std::cout<<m_myPoints[i].Getz()<<")"<<std::endl;
    }
}
std::vector<Point> GridCell::getCellPoints() /*returns the list of points of the specified Cell*/
{
    return m_myPoints;
}

double GridCell::getMinX()
{
    double xMin=m_myPoints[0].Getx();
    for (int i=1; i<m_myPoints.size(); i++) /*Get the minimum x-coord in a particular Cell*/
    {
        if (m_myPoints[i].Getx() < xMin)
        {
            xMin = m_myPoints[i].Getx();
        }
    }
    return xMin;
}
double GridCell::getMinY() /*Get the minimum y-coord in a particular Cell*/
{
    double yMin=m_myPoints[0].Gety();
    for (int i=1; i<m_myPoints.size(); i++)
    {
        if (m_myPoints[i].Gety() < yMin )
        {
            yMin = m_myPoints[i].Gety();
        }
    }
    return yMin;
}
double GridCell::getMinZ() /*Get the minimum z-coord in a particular Cell*/
{
    double zMin=m_myPoints[0].Getz();
    for (int i=1; i<m_myPoints.size(); i++)
    {
        if (m_myPoints[i].Getz() > zMin)
        {
            zMin = m_myPoints[i].Getz();
        }
    }
    return zMin;
}
double GridCell::getMaxX() /*Get the maximum x-coord in a particular Cell*/
{
    double xMax=m_myPoints[0].Getx();
    for (int i=1; i<m_myPoints.size(); i++)
    {
        if (m_myPoints[i].Getx() > xMax)
        {
            xMax = m_myPoints[i].Getx();
        }
    }
    return xMax;
}
double GridCell::getMaxY() /*Get the maximum y-coord in a particular Cell*/
{
    double yMax=m_myPoints[0].Gety();
    for (int i=1; i<m_myPoints.size(); i++)
    {
        if (m_myPoints[i].Gety() > yMax)
        {
            yMax = m_myPoints[i].Gety();
        }
    }
    return yMax;
}
double GridCell::getMaxZ() /*Get the maximum z-coord in a particular Cell*/
{
    double zMax=m_myPoints[0].Getz();
    for (int i=1; i<m_myPoints.size(); i++)
        if (m_myPoints[i].Getz() < zMax)
        {
            zMax = m_myPoints[i].Getz();
        }

    return zMax;
}

GridCell::~GridCell()
{
    //dtor
}
