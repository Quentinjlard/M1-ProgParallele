/**
 * @file Exercice4_2.cpp
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

mutex mtx;
const int MAX = 1000;
int courant = 0;

void TPaire()
{
    for (int i = 0; i <= MAX; i += 2)
    {
        mtx.lock();
        while (courant % 2 != 0)
        {
            mtx.unlock();
            mtx.lock();
        }

        cout << "Thread Paire : " << courant << endl;
        courant++;
        mtx.unlock();
    }
}

void TImpaire()
{
    for (int i = 1; i <= MAX; i += 2)
    {
        mtx.lock();
        while (courant % 2 != 1)
        {
            mtx.unlock();
            mtx.lock();
        }

        cout << "Thread Impaire : " << courant << endl;
        courant++;
        mtx.unlock();
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
