# PTE-543---Fall-2022
# C++ Well Interestion Program
## Program Description
This program reads the coordinates of a reservoir and its respective wells from a file. Then it checks for the point of intersection of each well with the reservoir specifying the grid cell that each well intersects. 
## Program Pre-requisites
Before using this program, ensure that you have:

- A C++ development environment installed on your computer.
- Basic knowledge of C++ programming.
- File containing all the necessary data about the reservoir and wells.
## Data File
- The file must be in a certain format for the program to work.
- The file must contain the reservoir built from grid cells. Each grid cell has an ID number.
- A file must contain a minimum of one grid cell
- Each Cell must contain only 8 points with x, y, and z values.
- If the user attempts to enter more than 8 points for a single grid cell the program will display a Warning.
- The coordinates of a well are represented using a vertical or horizontal line.
- The well must consist of a minimum of 3+ points.
- The well can contain as many points as desired.
- Each point representing the well must contain an x, y, and z coord.
- Keywords in the file must remain untouched for the proper execution of the code.

  ## File Format
 Keyword	Significance
//Grid Reservoir	Initiates the creation of the reservoir from grid cells.
//Number of cells	Specifies how many grid cells  the reservoir is made of.
//BEG GRID	Specifies for the program to start reading the coordinates of each grid cell.
//END GRID	Specifies for the program to stop reading coordinates of the grid cells.
//Well	Initiates the creation of the wells.
//Number of Wells	Specifies how many wells are available to be created
//Number of points in each well	Specifies a constant number of points that each well is made up of.
//BEG WELL	Specifies for the program to start reading the coordinates of each well.
//END WELL	Specifies for the program to stop reading the coordinates of the wells.
