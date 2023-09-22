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

mutex m1, m2;

const int MAX = 1000;
int courant = 0;

void TPaire()
{
    
    for (int courant = 0; courant < MAX; courant++)
    {
        m1.lock();
        if (courant % 2 == 0)
        {
            cout << "Thread Paire : " << courant << endl;
        }
        m1.unlock();
    }
    
}

void TImpaire()
{
    
    for (int courant = 0; courant < MAX; courant++)
    {
        m2.lock();
        if (courant % 2 != 0)
        {
            cout << "Thread Impaire : " << courant << endl;
        }
        m2.unlock();
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
