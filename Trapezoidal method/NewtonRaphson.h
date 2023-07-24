#ifndef NEWTONRAPHSON_H_INCLUDED
#define NEWTONRAPHSON_H_INCLUDED

#include "partialDiffFunctions.h"
#include "matrixFunctions.h"
#include <iostream>
#include <cmath>

using namespace std;

//********NewtonRaph Start***************
void NewtonRaph(partialDiff& f1, partialDiff& f2,double x,double y,double& ansX,double& ansY)
{

    double bigX[matSize][1];

    matrix forJacobian;
//*************loop****************
    while(true)
    {
        bigX[0][0]=x, bigX[1][0]=y;

        double bigF[matSize][1];

        bigF[0][0]=  f1.f(x,y,f1);

        bigF[1][0]=  f2.f(x,y,f2);


        forJacobian.jacobian(f1,f2,x,y);
        forJacobian.inverse();
        multiply(forJacobian.inJac,bigF);

        for(int i=0; i<matSize; i++)
        {
            bigX[i][0] -=product[i][0];
        }


//********check if condition is satisfied***
        x= bigX[0][0];
        y= bigX[1][0];
        bigF[0][0]=f1.f(x,y,f1);
        bigF[1][0]=f2.f(x,y,f2);


        long checker1= fabs(bigF[0][0]*pow(10,5));//ENUSRES THE FUNCTION IS 0 TO 9 DECIMAL PLACES
        long checker2= fabs(bigF[1][0]*pow(10,5));//ENUSRES THE FUNCTION IS 0 TO 9 DECIMAL PLACES

        if((checker1==0) && (checker2==0))
        {
            break;
        }

//********check if condition is satisfied***
    }//end loop

    ansX= bigX[0][0];
    ansY= bigX[1][0];

}
//********NewtonRaph End*****************

#endif // NEWTONRAPHSON_H_INCLUDED
