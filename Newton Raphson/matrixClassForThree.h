#ifndef MATRIXCLASSFORTHREE_H_INCLUDED
#define MATRIXCLASSFORTHREE_H_INCLUDED

#include "partialDiffForThree.h"
#include <iostream>
#include <cmath>

using namespace std;

double product[3][1];//product of jacobian matrix and set of function

//*************matrix*******************
class matrix
{

private:
    double element[3][3];
public:
    double inJac[3][3];
    double jacMat[3][3];//jacobian matrix
    void entr()
    {
        cout <<"\nPROCEED TO ENTER THE ELEMENTS OF THE MATRIX\n";
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout <<"entry[" <<i+1 <<"," <<j+1 <<"]: ";
                cin >>element[i][j];
            }
        }
    }

    //computes the inverse of the jacobian matrix
    void inverse()
    {
        double row[3][6];
        for(int m=0; m<=2; m++)
        {
            for(int n=0; n<=2; n++)
            {
                row[m][n]= jacMat[m][n];
            }
        }


        for(int m=1; m<=3; m++)
        {
            for(int n=4; n<=6; n++)
            {
                int x=(2*m)+(3*n);
                switch(x)
                {
                case 14:
                    row[m-1][n-1]= 1;
                    break;
                case 19:
                    row[m-1][n-1]= 1;
                    break;
                case 24:
                    row[m-1][n-1]= 1;
                    break;
                default:
                    row[m-1][n-1]= 0;
                    break;
                }
            }

        }



//This loop does d calculation

        double subrow[3][6], asst, pvt;
        int k;
        for(int m=0; m<=2; m++)
        {
            for(int n=1; n<=2; n++)
            {
                k=(m+n)%3;
                pvt= row[m][m];
                asst=row[k][m];

                for(int x=0; x<=5; x++)
                {
                    subrow[m][x]= row[m][x];

                    subrow[m][x]*=(asst/pvt);

                    row[k][x]-= subrow[m][x];

                    subrow[m][x]= row[m][x];

                }
            }
        }



        for(int m=0; m<=2; m++)
        {
            for(int n=0; n<=2; n++)
            {
                inJac[m][n]= row[m][n+3]/row[m][m];
            }
        }
//This is the end of the calculation
    }


    void jacobian(partialDiff& func1, partialDiff& func2, partialDiff& func3, double a, double b, double c)
    {
        //Derivative wrt X,Y and Z for func1
        jacMat[0][0]= func1.X(a,b,c,func1);
        jacMat[0][1]= func1.Y(a,b,c,func1);
        jacMat[0][2]= func1.Z(a,b,c,func1);
        //Derivative wrt X,Y and Z for func2
        jacMat[1][0]= func2.X(a,b,c,func2);
        jacMat[1][1]= func2.Y(a,b,c,func2);
        jacMat[1][2]= func2.Z(a,b,c,func2);
        //Derivative wrt X,Y and Z for func3
        jacMat[2][0]= func3.X(a,b,c,func3);
        jacMat[2][1]= func3.Y(a,b,c,func3);
        jacMat[2][2]= func3.Z(a,b,c,func3);

    }


};
//****************matrix********************


//************multiply********************

void multiply(const double A[3][3], const double B[3][1])
{
    int rowA=3,colA=3,rowB=3,colB=1;

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


//************print********************
void Print(int num_col, double x[3][3])
{
    cout <<"\n\n"<<endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<num_col; j++)
        {
            cout <<" " <<x[i][j];
        }
        cout <<endl;
    }
}
//************print********************

//************print bigX********************
void Print(int num_col, double x[3][1])
{
    cout <<"\n(";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<num_col; j++)
        {
            if(i!=2)
                cout <<" " <<x[i][j] <<" ,";
            else
                cout <<" " <<x[i][j];
        }

    }
    cout <<")";
}
//************print bigX********************




#endif // MATRIXCLASSFORTHREE_H_INCLUDED
