/**
 * @file Exercice1.cpp
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

void f()
{
    cout<<"Hello Word"<<endl;
}

int main(int ac, char** av)
{
    thread t1(f);
    thread t2(f);

    t1.join();
    t2.join();

    return 0;
}