/**
 * @file Exercice2_2.cpp
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

class Matrice
{
       
    private : 
        int lines;
        int colomns;
        int **matrice;

    public :

        Matrice( int lines, int columns)
        {
            this->lines = lines;
            this->colomns = columns;

            matrice = new int*[lines];
            for (int i = 0; i < lines; i++)
            {
                matrice[i] =  new int[colomns];
            }
            
            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < colomns; j++)
                {
                    matrice[i][j] = 1 + rand() % (10+ 1 - 1);
                }
                
            }
            
        }

        ~Matrice(){

            for (int i = 0; i < lines; i++)
            {
                delete[] matrice[i];
            }
            
            delete[] matrice;

        }



        Matrice operator*(const Matrice& other) const
        {
            if (colomns != other.lines) {
                cerr << "Matrices are not compatible for multiplication." << endl;
                exit(1);
            }

            int resLines = lines;
            int resColumns = other.colomns;

            Matrice resultatMatrice(resLines,resColumns);

            thread **threads = new thread*[resLines];
            for (int i = 0; i < lines; i++)
            {
                threads[i] = new thread[resColumns];
            }
            

            for (int i = 0; i < resLines; i++)
            {
                
                for (int j = 0; j < resColumns; j++)
                {
                    threads[i][j] = thread(sum, this, &other, &resultatMatrice, i, j);
                }
            }

            for (int i = 0; i < resLines; i++)
            {
                for (int j = 0; j < resColumns; j++)
                {
                    threads[i][j].join();
                }
                delete[] threads[i];
            }
            delete[] threads;

            return resultatMatrice;
        }

        void printMatrice() const
        {
            for (int i = 0; i < lines; i++) 
            {
                for (int j = 0; j < colomns; j++) 
                {
                    cout << matrice[i][j] << ' ';
                }
                cout << endl;
            } 
        }

        static void sum(const Matrice *A, const Matrice *B, Matrice *C, int i, int j)
        {
            int som = 0;
            for (int k = 0; k < A->colomns; k++)
            {
                som += A->matrice[i][k] * B->matrice[k][j];
            }
            C->matrice[i][j] = som;
        }
    
};

int main(int ac, char** av)
{
    Matrice A(2,3);
    cout << "=> Matrice A " <<endl;
    A.printMatrice();

    Matrice B(3,2   );
    cout << "=> Matrice B " <<endl;
    B.printMatrice();

    Matrice C = A * B;
    cout << "=> Matrice C " <<endl;
    C.printMatrice();


    return 0;
}