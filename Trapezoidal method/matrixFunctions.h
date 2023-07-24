#ifndef MATRIXFUNCTIONS_H_INCLUDED
#define MATRIXFUNCTIONS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <iomanip>
#include "partialDiffFunctions.h"
using namespace std;
double product[matSize][1];//product of jacobian matrix and set of function

//*************matrix*******************
class matrix
{

private:
    double element[matSize][matSize];
public:
    double inJac[matSize][matSize];
    double jacMat[matSize][matSize];//jacobian matrix
    void entr()
    {
        cout <<"\nPROCEED TO ENTER THE ELEMENTS OF THE MATRIX\n";
        for(int i=0; i<matSize; i++)
        {
            for(int j=0; j<matSize; j++)
            {
                cout <<"entry[" <<i+1 <<"," <<j+1 <<"]: ";
                cin >>element[i][j];
            }
        }
    }
//YET TO BE EDITED********
    //computes the inverse of the jacobian matrix
    void inverse()
    {
        double row[matSize][matSize];
        for(int m=0; m<matSize; m++)
        {
            for(int n=0; n<matSize; n++)
            {
                row[m][n]= jacMat[m][n];
            }
        }


//Calculation starts here

        double determinant= row[0][0]*row[1][1] - row[0][1]*row[1][0];

        inJac[0][0]= row[1][1]/determinant;
        inJac[0][1]=-row[0][1]/determinant;
        inJac[1][0]=-row[1][0]/determinant;
        inJac[1][1]= row[0][0]/determinant;
//This is the end of the calculation

    }


    void jacobian(partialDiff& func1, partialDiff& func2, double a, double b)
    {
        //Derivative wrt X,Y and Z for func1
        jacMat[0][0]= func1.X(a,b,func1);
        jacMat[0][1]= func1.Y(a,b,func1);

        //Derivative wrt X,Y and Z for func2
        jacMat[1][0]= func2.X(a,b,func2);
        jacMat[1][1]= func2.Y(a,b,func2);

    }


};
//****************matrix********************


//************multiply********************

void multiply(const double A[matSize][matSize], const double B[matSize][1])
{
    int rowA=matSize,colA=matSize,rowB=matSize,colB=1;

    for(int i=0; i<rowA; i++)
    {
        for(int j=0; j<colB; j++)
        {
            double sum= 0;
            for(int m=0; m<colA; m++)
            {
                sum += (A[i][m]*B[m][j]);
            }
            product[i][j]= sum;
        }
    }


}
//************multiply********************


#endif // MATRIXFUNCTIONS_H_INCLUDED
