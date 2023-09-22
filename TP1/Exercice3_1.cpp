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
        T[i] = 1 + rand() % (50+ 1 - 1);
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

    cout << "Sum of tab : "<< res << endl;
}



int main(int ac, char** av)
{

    initTab();

    sumTab();

}