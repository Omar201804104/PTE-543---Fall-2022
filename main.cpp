#include <iostream>
#include "Point.h"
#include "GridCell.h"
#include "GridRes.h"
#include "Well.h"
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    GridRes shaleRes;
    shaleRes.createRes();
    shaleRes.createWell();
    shaleRes.dispCells();
    shaleRes.dispWells();
    shaleRes.getIntersect();

    return 0;
}
