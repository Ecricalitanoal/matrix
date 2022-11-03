#include <iostream>
#include <ctime>
int main()
{
    setlocale(0, "");
    srand(time(0));
    bool flagSwitcher = true;
    char op;
    int sizeF1, sizeF2, sizeS1, sizeS2, sizeR1, sizeR2, counterOfUser, counterOfExcp;
    int random;
    int** matrixFirst, ** matrixSecond, ** matrixResult;
    counterOfExcp = 0;
    counterOfUser = 0;
    //size First matrix Second matrix Result matrix
    std::cout << "~~~Матрицы~~~" << '\n';
    std::cout << "Введите размеры первой матрицы: " << '\n';
    std::cin >> sizeF1 >> sizeF2;
    std::cout << "Введите размеры второй матрицы: " << '\n';
    std::cin >> sizeS1 >> sizeS2;
    matrixFirst = new int* [sizeF1];
    for (int i = 0; i < sizeF1; i++)
    {
        matrixFirst[i] = new int[sizeF2];
    }

    matrixSecond = new int* [sizeS1];
    for (int i = 0; i < sizeS1; i++)
    {
        matrixSecond[i] = new int[sizeS2];
    }

    matrixResult = new int* [sizeF1];

    while (flagSwitcher)
    {
        std::cout << "Введите 1 для случайного заполнения матриц:" << '\n';
        std::cout << "Введите 2 для вывода матриц:" << '\n';
        std::cout << "Введите 3 для сложения матриц:" << '\n';
        std::cout << "Введите 4 для умножения матриц:" << '\n';
        std::cout << "Введите 0 для завершения программы:" << '\n';
        std::cin >> op;
        switch (op)
        {
        case '0': {flagSwitcher = false; break; }
        case '1':
        {
            counterOfUser++;
            for (int i = 0; i < sizeF1; i++)
            {
                for (int j = 0; j < sizeF2; j++)
                {
                    random = rand() % 10 + 1;
                    matrixFirst[i][j] = random;
                }
            }
            for (int i = 0; i < sizeS1; i++)
            {
                for (int j = 0; j < sizeS2; j++)
                {
                    random = rand() % 10 + 1;
                    matrixSecond[i][j] = random;
                }
            }
            break;
        }
        case '2':
        {
            if (counterOfUser > 0) {
                std::cout << "Первая матрица:" << '\n';
                for (int i = 0; i < sizeF1; i++)
                {
                    for (int j = 0; j < sizeF2; j++)
                    {
                        std::cout << "[" << matrixFirst[i][j] << "]" << '\t';
                    }
                    std::cout << '\n';
                }
                std::cout << "Вторая матрица:" << '\n';
                for (int i = 0; i < sizeS1; i++)
                {
                    for (int j = 0; j < sizeS2; j++)
                    {
                        std::cout << "[" << matrixSecond[i][j] << "]" << '\t';
                    }
                    std::cout << '\n';
                }
                if (counterOfExcp > 0)
                {
                    std::cout << "Третья матрица:" << '\n';
                    for (int i = 0; i < sizeF1; i++)
                    {
                        for (int j = 0; j < sizeS2; j++)
                        {
                            std::cout << "[" << matrixResult[i][j] << "]" << '\t';
                        }
                        std::cout << '\n';
                    }
                }

            }
            else std::cout << "Сначала заполните матрицы" << '\n' << '\n';
            break;
        }
        case '3':
        {
            if (counterOfUser > 0) {
                if (sizeF1 == sizeS1 && sizeF2 == sizeS2)
                {
                    counterOfExcp++;
                    for (int i = 0; i < sizeF1; i++)
                    {
                        matrixResult[i] = new int[sizeS2];
                    }
                    for (int i = 0; i < sizeF1; i++)
                    {
                        for (int j = 0; j < sizeS2; j++)
                        {
                            matrixResult[i][j] = matrixFirst[i][j] + matrixSecond[i][j];
                        }
                    }
                }
                else std::cout << "Матрицы должны быть одно размера!" << '\n' << '\n';
            }
            else std::cout << "Сначала заполните матрицы" << '\n' << '\n';
            break;
        }
        case '4':
        {
            if (counterOfUser > 0) {
                if (sizeF2 == sizeS1)
                {
                    counterOfExcp++;
                    for (int i = 0; i < sizeF1; i++)
                    {
                        matrixResult[i] = new int[sizeS2];
                    }
                    for (int i = 0; i < sizeF1; i++)
                    {
                        for (int j = 0; j < sizeS2; j++)
                        {
                            matrixResult[i][j] = 0;
                            for (int k = 0; k < sizeF2; k++)
                            {
                                matrixResult[i][j] += matrixFirst[i][k] * matrixSecond[k][j];
                            }
                        }
                    }
                }
                else std::cout << "Матрицы данного размера нельзя перемножить" << '\n' << '\n';
            }
            else std::cout << "Сначала заполните матрицы" << '\n' << '\n';
            break;
        }
        default: continue;
        }
    }
}