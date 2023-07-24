#include "partialDiffForThree.h"
#include "matrixClassForThree.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout <<"\nWELCOME...\nTHIS PROGRAM FINDS THE ROOT FOR A SYSTEM OF NON-LINEAR EQUATIONS\n\n";

    cout <<"ENTER THE STARTING VECTOR(x,y,z): ";
    double x,y,z,bigX[3][1];
    cin >>x >>y >>z;
    cin.clear();
    cin.ignore(1,'\n');
    matrix forJacobian;
    partialDiff f1,f2,f3;
    f1.cnt=0;
    f2.cnt=0;
    f3.cnt=0;
//*************loop****************
    unsigned long jumper=0;//keeps count of how many iterations
    while(true)
    {
        bigX[0][0]=x, bigX[1][0]=y, bigX[2][0]=z;


        double bigF[3][1];
        if(jumper==0)
            cout <<"\n\nYOU ARE NOW TO INPUT THE FIRST, SECOND AND THIRD FUNCTION RESPECTIVELY:";
        if(jumper==0)
            cout <<"\n\nFIRST FUNCTION:\n";
        bigF[0][0]=  f1.f(x,y,z,f1);
        if(jumper==0)
            cout <<"\n\nSECOND FUNCTION:\n";
        bigF[1][0]=  f2.f(x,y,z,f2);
        if(jumper==0)
            cout <<"\n\nTHIRD FUNCTION:\n";
        bigF[2][0]=  f3.f(x,y,z,f3);
        if(jumper==0)
            cout <<"\n\nNOW YOU HAVE SUCCESSFULLY ENTERED THE FUNCTIONS CORRECTLY!!!\n\n";


        forJacobian.jacobian(f1,f2, f3, x, y,z);
        forJacobian.inverse();
        multiply(forJacobian.inJac,bigF);

        for(int i=0; i<3; i++)
        {
            bigX[i][0] -=product[i][0];
        }


//********check if condition is satisfied***
        x= bigX[0][0];
        y= bigX[1][0];
        z= bigX[2][0];
        bigF[0][0]=f1.f(x,y,z,f1);
        bigF[1][0]=f2.f(x,y,z,f2);
        bigF[2][0]=f3.f(x,y,z,f3);

        long checker1= fabs(bigF[0][0]*pow(10,5));
        long checker2= fabs(bigF[1][0]*pow(10,5));
        long checker3= fabs(bigF[2][0]*pow(10,5));

        if((checker1==0) && (checker2==0) && (checker3==0))
        {
            break;
        }
        ++jumper;

//********check if condition is satisfied***
    }//end loop

    cout <<"\n\nTHE SATISFACTORY SOLUTION IS: ";
    Print(1,bigX);

    //TO PREVENT THE PROGRAM FROM SELF-TERMINATING
    cout <<"\n\nENTER 'X' TO TERMINATE PROGRAM: ";
    char u= 'x';
    cin >>u;
    return 0;
}
