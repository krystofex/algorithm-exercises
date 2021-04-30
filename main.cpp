#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int size = 20;
    size = (size % 2 == 0) ? size + 1 : size;

    int array[size][size];

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if ((x == 0 || x == size - 1) || (y == 0 || y == size - 1))
                array[x][y] = 1;
            else if (x % 2 == 0 && y % 2 == 0)
                array[x][y] = 2;
            else
                array[x][y] = 0;
        }
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

        int randomBase = (numberOfBases == 1) ? 1 : rand() % numberOfBases; // get random base

        int currentBase = 0;
        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
            {
                if (array[x][y] == 2)
                    currentBase++;

                if (currentBase == randomBase)
                {
                    int direction = rand() % 4;
                    int i = 0;

                    while (true)
                    {
                        if (direction < 2)
                        {
                            if (array[x][y + i] == 1)
                                break;
                            else
                                array[x][y + i] = 1;
                        }

                        else
                        {
                            if (array[x + 1][y] == 1)
                                break;
                            else
                                array[x + 1][y] = 1;
                        }

                        i += (direction % 2 == 1) ? -1 : 1;
                    }
                    break;
                }
            }
        }
    }

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            char character = array[x][y] == 1 ? '#' : ' ';
            cout << character;
        }
        cout << endl;
    }
    return 0;
}