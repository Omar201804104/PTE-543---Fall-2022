#ifndef GRIDRES_H
#define GRIDRES_H
#include "GridCell.h"
#include"Well.h"
#include <vector>


class GridRes
{
    public:
        GridRes();
        virtual ~GridRes();
        void addCell(GridCell myCell);
        void createRes();
        void dispCells();
        void createWell();
        void dispWells();
        void getIntersect();

    protected:

    private:
        int m_id;
        std::vector <GridCell> m_myCells;
        std::vector<Well>m_myWells;

};

#endif // GRIDRES_H
