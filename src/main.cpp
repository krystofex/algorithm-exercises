#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int size = 150;
    if (size % 2 == 0)
        size++;

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
        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
            {
                char character = ' ';
                if (array[x][y] == 1)
                    character = 'O';
                //cout << array[x][y];
            }
            //cout << endl;
        }
        int pocetZakladu = 0;
        for (int x = 0; x < size; x++)
            for (int y = 0; y < size; y++)
                if (array[x][y] == 2)
                    pocetZakladu++;

        if (pocetZakladu == 0)
        {

            break;
        }
        int nahodnyZaklad = rand() % pocetZakladu;
        if (pocetZakladu == 1)
            nahodnyZaklad = 1;
        //cout << pocetZakladu << "|" << nahodnyZaklad << endl;
        int tmp = 0;
        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
            {
                int smer;
                if (array[x][y] == 2)
                    tmp++;

                if (tmp == nahodnyZaklad)
                {
                    smer = rand() % 4;
                    //cout << smer << endl;
                    if (smer == 0)
                        for (int i = 0; i < size; i++)
                        {
                            if (array[x][y + i] == 1)
                                break;
                            else
                                array[x][y + i] = 1;
                        }
                    else if (smer == 1)
                        for (int i = 0; i < size; i--)
                        {
                            if (array[x][y + i] == 1)
                                break;
                            else
                                array[x][y + i] = 1;
                        }
                    else if (smer == 2)
                        for (int i = 0; i < size; i++)
                        {
                            if (array[x + i][y] == 1)
                                break;
                            else
                                array[x + i][y] = 1;
                        }
                    else if (smer == 3)
                        for (int i = 0; i < size; i--)
                        {
                            if (array[x + i][y] == 1)
                                break;
                            else
                                array[x + i][y] = 1;
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
            char character = ' ';
            if (array[x][y] == 1)
                character = '#';
            cout << character;
        }
        cout
            << endl;
    }
    return 0;
}