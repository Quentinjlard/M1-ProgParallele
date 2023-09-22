/**
 * @file Exercice4_1.cpp
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
#include <mutex>

using namespace std;

mutex m;

const int MAX = 1000;

void TPaire()
{
    for (int i = 0; i < MAX; i++)
    {
        if (i % 2 == 0)
        {
            cout << "Thread Paire : " << i << endl;
        }
    }
}

void TImpaire()
{
    for (int i = 0; i < MAX; i++)
    {
        if (i % 2 != 0)
        {
            cout << "Thread Impaire : " << i << endl;
        }
    }
}

int main()
{
    thread threadPaire(TPaire);
    thread threadImpaire(TImpaire);

    threadPaire.join();
    threadImpaire.join();

    return 0;
}
