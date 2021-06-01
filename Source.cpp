#include <iostream>
#include <iomanip>

void fill(int** Mas, int ySize, int xSize)
{
    int proizv = xSize * ySize;
    int Y = 0, X = 0, cnt = 1;
    while (ySize > 0)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < ((xSize < ySize) ? ySize : xSize); x++)
            {
                if (y == 0 && x < xSize - X && cnt <= proizv)
                    Mas[y + Y][x + X] = cnt++;
                if (y == 1 && x < ySize - Y && x != 0 && cnt <= proizv)
                    Mas[x + Y][xSize - 1] = cnt++;
                if (y == 2 && x < xSize - X && x != 0 && cnt <= proizv)
                    Mas[ySize - 1][xSize - (x + 1)] = cnt++;
                if (y == 3 && x < ySize - (Y + 1) && x != 0 && cnt <= proizv)
                    Mas[ySize - (x + 1)][Y] = cnt++;
            }
        }
        ySize--;
        xSize--;
        Y++;
        X++;
    }
}

int n, m;
int main()
{
    setlocale(LC_ALL, "ru");
    do {
        system("cls");
        std::cout << "Input X: ";
        std::cin >> n;
        std::cout << "Input Y: ";
        std::cin >> m;
    } while (n < 1 || m < 1);
    std::cout << std::endl;
    system("cls");

    int** arr = new int* [n];
    for (unsigned short i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    
    fill(arr, n, m);

    std::cout << "matrix: " << std::endl;
    for (unsigned short i = 0; i < n; i++)
    {
        for (unsigned short j = 0; j < m; j++)
        {
            std::cout << std::setw(5)<< arr[i][j];
        }
        std::cout << std::endl;
    }

    for (unsigned short i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}