#include "GridRes.h"
#include "GridCell.h"
#include "Point.h"
#include"Well.h"
#include <fstream>
#include <iostream>
#include <vector>

GridRes::GridRes():m_id(0), m_myCells(0),m_myWells(0)
{

}
void GridRes::addCell(GridCell myCell)
{
    m_myCells.push_back(myCell);
}

void GridRes::createRes() /*function that creates the reservoir*/       /*Function that reads from the file and looks for a specific keyword to start reading the Cell coord*/
{
    std::ifstream openFile("gridData.ptelau");                          /*Cell points are represented by 8 lines each line must contain 3 values representing x, y, and z*/

    if (openFile)                                                       /*Each line(the coords) is(are) stored in a point which is then stored in a list of points*/
    {
        /*std::cout<<"The file was opened successfully."<<std::endl;*/  /*Depending on the keyword for the number of Cells a Cell object is created*/
    }
                                                                        /*The list of points is passed to the created Cell object*/
    else
    {                                                                   /*Each cell object is stored in a list of Cells for the created Reservoir*/
        std::cout<<"The file was not able to open."<<std::endl;
    }
    std::string line;
    double cellNum(0);
    double value(0);
    int counter(0);
    while(getline(openFile,line))
    {
        if (line =="//BEG GRID")
        {
            while (getline(openFile,line))
            {
                if (line == "//END GRID")
                {
                    if (counter % 8 !=0)/*Validating grid cell input*/
                    {
                        std::cout<<"Invalid number of points for forming a cell"<<std::endl;
                        break;
                    }
                    else
                    {
                        openFile.close();
                        std::ifstream openFile("gridData.ptelau");
                        while (getline(openFile,line))
                        {
                            if (line=="//Number of cells")
                            {
                                openFile>>cellNum;
                            }
                            if (line=="//BEG GRID")
                            {
                                for (int cell=1; cell<=cellNum; cell++)
                                {
                                    std::vector<Point> myPoints;
                                    for (int i=1; i<=8; i++)
                                    {
                                        double Table[3];
                                        for (int j=0; j<=2; j++)
                                        {
                                            openFile>>value;
                                            Table[j]= value;
                                        }
                                        Point myPoint(Table[0],Table[1],Table[2]);
                                        myPoints.push_back(myPoint);
                                    }
                                    GridCell myCell(cell,myPoints);
                                    m_myCells.push_back(myCell);/*adds Cells to the list*/
                                }
                            }
                        }
                    }

                }
                counter++;
            }
        }
    }
openFile.close();
}

void GridRes::dispCells() /*displays on the console the coords of each Point forming each Cell of the Reservoir*/
{
    for (int i =0;i<m_myCells.size();i++)
    {
        m_myCells[i].dispCellId();
        m_myCells[i].dispCellPoints();
        std::cout<<std::endl;
    }

}

void GridRes::createWell() /*function that creates the well objects*/          /*Function that reads from the file and looks for a specific keyword to start reading the Well coord*/
{
    std::ifstream openFile("gridData.ptelau");                                 /*Well points can be represented by any number of lines containing 3 values representing x, y, and z*/
    if (openFile)
    {                                                                          /*Each line(the coords) is(are) stored in a point which is then stored in a list of points*/
        /*std::cout<<"The file was opened successfully."<<std::endl;*/
    }                                                                          /*Depending on the keyword for the number of Wells a Well object is created*/
    else
    {                                                                          /*The list of points is passed to the created Well object*/
        std::cout<<"The file was not able to open."<<std::endl;
    }                                                                          /*Each Well object is stored in a list of Wells for the created Reservoir*/
    std::string line;
    double value;
    double wellNum;
    double pointNum;
    while (getline(openFile,line))
    {
        if (line == "//Number of wells")
        {
            openFile>>value;
            wellNum=value;
        }
        if (line == "//Number of points in each well")
        {
            openFile>>value;
            pointNum=value;
        }
        if (line == "//BEG WELL")
        {
            for (int well=1; well<=wellNum;well++)
            {
                std::vector<Point> myWellPoints;
                for (int i=1; i<=pointNum; i++)
                {
                    double Table[3];
                    for (int j=0; j<=2; j++)
                    {
                        openFile>>value;
                        Table[j]= value;
                    }

                    Point myPoint(Table[0],Table[1],Table[2]);
                    myWellPoints.push_back(myPoint);

                }
            Well myWell(well,myWellPoints);
            m_myWells.push_back(myWell);/*adds Wells to the list*/
            }
        }
    }
    openFile.close();
}

void GridRes::dispWells()
{
    for (int i =0;i<m_myWells.size();i++)
    {
        m_myWells[i].dispWellId();
        m_myWells[i].dispWellPoints();
        std::cout<<std::endl;
    }
}




void GridRes::getIntersect()
{
    for (int i=0;i<m_myWells.size();i++) /*isolating every well to check*/
    {
        std::vector <Point> tempWellPoints;
        int counter(0);

        for (int j =0;j<m_myCells.size();j++) /*isolating every grid cell to check*/
        {
            int x(0);
            for (int t=0;t<m_myWells[i].getWellPoints().size();t++) /*isolating every well point to check if it's in the grid cell*/
            {
                Point testPoint = m_myWells[i].getWellPoints()[t];
                if (testPoint.Getx() >= m_myCells[j].getMinX() && testPoint.Getx() <= m_myCells[j].getMaxX()&& testPoint.Gety()>=m_myCells[j].getMinY() && testPoint.Gety()<=m_myCells[j].getMaxY() && testPoint.Getz()<=m_myCells[j].getMinZ() && testPoint.Getz()>=m_myCells[j].getMaxZ())
                {
                    std::cout<<"The Well with ID: "<<m_myWells[i].getWellId()<<" intersects Cell with ID: "<<m_myCells[j].getCellId()<<std::endl;
                    counter++;
                    break;
                }
            }
            if (counter=0)
            {
                std::cout<<"The Well does not intersect Cell with ID: "<<m_myCells[j].getCellId()<<std::endl;
            }
        }
    }
}



GridRes::~GridRes()
{
    //dtor
}
