/*void GridCell::createCell()
{
    std::ifstream openFile("gridData.ptelau");
    if (openFile)
    {
        std::cout<<"The file was opened successfully."<<std::endl;
    }
    else
    {
        std::cout<<"The file was not able to open."<<std::endl;
    }

    double value(0);
    std::string line;
    double cellNumb;

    while (getline(openFile,line))
    {
        if (line=="//Number of cells")
        {
            openFile>>cellNumb;

            if (line=="//BEG GRID")
            {
                {
                    for (int i=1; i<=8; i++)
                    {
                        double Table[3];
                        for (int j=0; j<=2; j++)
                        {
                            openFile>>value;
                            Table[j]= value;
                        }
                        Point myPoint(Table[0],Table[1],Table[2]);
                        m_myPoints.push_back(myPoint);
                    }

                }
            }
        }
    }
}
    /*double value(0);
    for (int i=1; i<=8; i++)
    {
        double Table[3];
        for (int j=0; j<=2; j++)
        {
            openFile>>value;
            Table[j]= value;
        }
        Point myPoint(Table[0],Table[1],Table[2]);
        m_myPoints.push_back(myPoint);
    }
}*/
