/**
 * @file Exercice3_2.cpp
 * @author Juilliard Quentin (quentin.juilliard2@alumni.univ-avignon.fr)
 * @brief 
 * @version 0.1
 * @date 2023-09-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <thread>

using namespace std;

const int SIZE = 100;
int T[SIZE];

void printTab()
{
    cout << "Print tab : ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << T[i] << " ";
    }
    cout << endl;
}

void initTab()
{
    for (int i = 0; i < SIZE; i++)
    {
        T[i] = 1 + rand() % (50 + 1 - 1);
    }

    printTab();
}

void sumTab()
{
    int res = 0;

    for (int i = 0; i < SIZE; i++)
    {
        res += T[i];
    }

    cout << "Sum of tab : " << res << endl;
}

void sumThread(int start, int subdivision, int* tabResultat)
{
    int res = 0, stop = start + subdivision;

    for (int i = start; i < stop; i++)
    {
        res += T[i];
    }

    tabResultat[start / subdivision] = res;

    cout << "=> Start : " << start << " Stop : " << stop << "Sum of subdivision : " << res << endl;
}

int main(int ac, char** av)
{
    int subdivision = SIZE / 4, start;
    cout << "Subdivision : " << subdivision << endl;

    int tabResultat[4];

    initTab();

    thread threads[4];

    for (int i = 0; i < 4; i++)
    {
        start = i * subdivision;
        threads[i] = thread(sumThread, start, subdivision, tabResultat);
    }

    for (int i = 0; i < 4; i++)
    {
        threads[i].join();
    }

    int totalSum = 0;
    for (int i = 0; i < 4; i++)
    {
        totalSum += tabResultat[i];
    }

    cout << "Total Sum with Thread : " << totalSum << endl;

    sumTab();
}