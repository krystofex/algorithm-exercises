#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ofstream outputFile;
    int size = 10;
    srand(time(0));

    size = (size % 2 == 0) ? size + 1 : size;
    int array[size][size];

    for (int x = 0; x < size; x++) // generate walls and bases
        for (int y = 0; y < size; y++)
        {
            if ((x == 0 || x == size - 1) || (y == 0 || y == size - 1))
                array[x][y] = 1;
            else if (x % 2 == 0 && y % 2 == 0)
                array[x][y] = 2;
            else
                array[x][y] = 0;
        }

    while (true)
    {
        // get number of bases
        int numberOfBases = 0;
        for (int x = 0; x < size; x++)
            for (int y = 0; y < size; y++)
                if (array[x][y] == 2)
                    numberOfBases++;

        if (numberOfBases == 0) // exit when there are no bases left
            break;

        int randomBase = rand() % numberOfBases; // get random base

        int currentBase = 0;
        for (int x = 2; x < size; x += 2)
            for (int y = 2; y < size; y += 2)
            {
                if (currentBase == randomBase)
                {
                    int direction = rand() % 4; // get random direction
                    int i = 0;
                    while (true)
                    {
                        int tmpX = (direction < 2) ? x : x + i;
                        int tmpY = (direction > 1) ? y : y + i;

                        if (array[tmpX][tmpY] == 1)
                            break;

                        else
                            array[tmpX][tmpY] = 1;

                        i += (direction % 2 == 0) ? -1 : 1;
                    }
                }

                if (array[x][y] == 2)
                    currentBase++;
            }
    }

    // output maze to file
    outputFile.open("maze.txt");
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            cout << ((array[x][y] == 1) ? "#" : " ");
            outputFile << array[x][y];
        }
        outputFile << endl;
        cout << endl;
    }
    outputFile.close();

    outputFile.open("maze.json");

    outputFile
        << "[" << endl;
    for (int x = 0; x < size; x++)
    {
        outputFile << "  [";
        for (int y = 0; y < size; y++)
        {
            outputFile << array[x][y];
            if (y < size - 1)
                outputFile << ", ";
        }
        outputFile << "]";
        if (x < size - 1)
            outputFile << "," << endl;
    }
    outputFile << endl
               << "]";
    outputFile.close();

    return 0;
}