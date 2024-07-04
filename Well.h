#ifndef WELL_H
#define WELL_H
#include "Point.h"
#include <vector>


class Well
{
    public:
        Well();
        Well(unsigned int id,std::vector<Point> wellPoints);
        virtual ~Well();
        void createWell();
        void dispWellId();
        void dispWellPoints();
        std::vector<Point> getWellPoints();
        unsigned int getWellId();

    protected:

    private:
        unsigned int m_id;
        std::vector <Point> m_wellPoints;
};

#endif // WELL_H
