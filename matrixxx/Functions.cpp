#include "Matrix.h"
#include <iostream>
#include <ctime>
int** init(int size1, int size2)
{
	int **matrix = new int* [size1];
	for (int i = 0; i < size1; i++)
	{
		matrix[i] = new int[size2];
	}
	return matrix;
}

void filling(int** &matrix, int s1, int s2)
{
    int random;
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            random = rand() % 10 + 1;
            matrix[i][j] = random;
        }
    }
}

void wMatrix(int** matrix1, int** matrix2, int s11, int s12, int s21, int s22, int ** matrix3, int x)
{
    std::cout << "������ �������:" << '\n';
    for (int i = 0; i < s11; i++)
    {
        for (int j = 0; j < s12; j++)
        {
            std::cout << "[" << matrix1[i][j] << "]" << '\t';
        }
        std::cout << '\n';
    }
    std::cout << "������ �������:" << '\n';
    for (int i = 0; i < s21; i++)
    {
        for (int j = 0; j < s22; j++)
        {
            std::cout << "[" << matrix2[i][j] << "]" << '\t';
        }
        std::cout << '\n';
    }
    if (x != 0) 
    {
        std::cout << "������ �������:" << '\n';
        for (int i = 0; i < s11; i++)
        {
            for (int j = 0; j < s22; j++)
            {
                std::cout << "[" << matrix3[i][j] << "]" << '\t';
            }
            std::cout << '\n';
        }
    }
}

int** sum(int** matrix1, int** matrix2, int s11, int s12, int s21, int s22, int& k)
{
    int** matrixR = new int* [s11];
    for (int i = 0; i < s11; i++)
    {
        matrixR[i] = new int[s22];
    }
    for (int i = 0; i < s11; i++)
    {
        for (int j = 0; j < s22; j++)
        {
            matrixR[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    k++;
    return matrixR;
}

int** multip(int** matrix1, int** matrix2, int s11, int s12, int s21, int s22, int &k)
{
    if (s12 == s21)
    {
        int** matrixR = new int* [s11];
        for (int i = 0; i < s11; i++)
        {
            matrixR[i] = new int[s22];
        }
        for (int i = 0; i < s11; i++)
        {
            for (int j = 0; j < s22; j++)
            {
                matrixR[i][j] = 0;
                for (int k = 0; k < s12; k++)
                {
                    matrixR[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        k++;
        return matrixR;
    }
    else std::cout << "������� ������� ������� ������ �����������" << '\n' << '\n';
}

void writer()
{
    std::cout << "������� 1 ��� ���������� ���������� ������:" << '\n';
    std::cout << "������� 2 ��� ������ ������:" << '\n';
    std::cout << "������� 3 ��� �������� ������:" << '\n';
    std::cout << "������� 4 ��� ��������� ������:" << '\n';
    std::cout << "������� 0 ��� ���������� ���������:" << '\n';
}
void size(int& x1, int& x2, int& x3, int& x4)
{
    std::cout << "������� ������� ������ �������: " << '\n';
    std::cin >> x1 >> x2;
    std::cout << "������� ������� ������ �������: " << '\n';
    std::cin >> x3 >> x4;
}
void wErr()
{
    std::cout << "������� ��������� �������\n";
}