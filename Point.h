#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(double x, double y, double z);
        virtual ~Point();

        double Getx();
        void Setx(double x);
        double Gety();
        void Sety(double y);
        double Getz();
        void Setz(double z);
        double addPoint();
        void dispCoordinates();

    protected:

    private:
        double m_x;
        double m_y;
        double m_z;
       /* std::string m_fileName;*/
};

#endif // POINT_H
