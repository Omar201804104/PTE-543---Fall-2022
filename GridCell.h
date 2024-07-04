#ifndef GRIDCELL_H
#define GRIDCELL_H
#include "Point.h"
#include <vector>
#include <string>


class GridCell
{
    public:
        GridCell();
        GridCell(unsigned int id,std::vector <Point> x);

        virtual ~GridCell();

        unsigned int getCellId();
        void setCellId(unsigned int val);
        void dispCellId();
        void dispCellPoints();
        void addPoint(Point myPoint);
        std::vector<Point> getCellPoints();
        double getMinX();
        double getMinY();
        double getMinZ();
        double getMaxX();
        double getMaxY();
        double getMaxZ();

    protected:

    private:
        unsigned int m_id;
        std::vector<Point> m_myPoints;


};

#endif // GRIDCELL_H
