#include <iostream>
#include <ctime>
#include "Matrix.h"
int main()
{
    setlocale(0, "");
    srand(time(0));
    bool flagSwitcher = true;
    char op;
    int sizeF1, sizeF2, sizeS1, sizeS2, counterOfUser = 0, counterOfExcp = 0;
    int** matrixFirst, ** matrixSecond, ** matrixResult;
    size(sizeF1, sizeF2, sizeS1, sizeS2);
    matrixFirst = init(sizeF1, sizeF2);
    matrixSecond = init(sizeS1, sizeS2);
    matrixResult = new int*[sizeF2];
    while (flagSwitcher)
    {
        writer();
        std::cin >> op;
        switch (op)
        {
        case '0': {flagSwitcher = false; break;}
        case '1':
        {
            counterOfUser++;
            filling(matrixFirst, sizeF1, sizeF2);
            filling(matrixSecond, sizeS1, sizeS2);
            break;
        }
        case '2':
        {
            if (counterOfUser != 0)
            {
                wMatrix(matrixFirst, matrixSecond, sizeF1, sizeF2, sizeS1, sizeS2, matrixResult, counterOfExcp);
            }
            else wErr();
            break;
        }
        case '3':
        {
            if (counterOfUser != 0)
            {
                if (sizeF1 == sizeS2 && sizeF2 == sizeS1) {
                    matrixResult = sum(matrixFirst, matrixSecond, sizeF1, sizeF2, sizeS1, sizeS2, counterOfExcp);
                }
                else std::cout << "Матрицы должны быть одного размера\n";
            }
            else wErr();
            break;
        }
        case '4':
        {
            if (counterOfUser != 0)
            {
                matrixResult = multip(matrixFirst, matrixSecond, sizeF1, sizeF2, sizeS1, sizeS2, counterOfExcp);
            }
            else wErr();
            break;
        }
        default: continue;
        }
    }
}