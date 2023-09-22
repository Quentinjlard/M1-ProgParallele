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
        unique_lock<mutex> lock(mtx);
        while (courant % 2 != 0)
        {
            lock.unlock();
            this_thread::yield();
            lock.lock();
        }

        cout << "Thread Paire : " << courant << endl;
        courant++;
    }
}

void TImpaire()
{
    for (int i = 1; i <= MAX; i += 2)
    {
        unique_lock<mutex> lock(mtx);
        while (courant % 2 != 1)
        {
            lock.unlock();
            this_thread::yield();
            lock.lock();
        }

        cout << "Thread Impaire : " << courant << endl;
        courant++;
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
