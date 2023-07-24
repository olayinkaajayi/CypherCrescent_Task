#include "partialDiffForThree.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    while(true)
    {
        partialDiff var;
        var.cnt=0;
        cout <<"\n\nENTER THE POINT WHERE THE DERIVATIVE OF THE FUNCTION IS TO BE COMPUTED (x,y,z): ";
        double varX,varY,varZ;
        cin >>varX >>varY >>varZ;
        double result1= var.X(varX,varY,varZ,var),result2= var.Y(varX,varY,varZ,var),result3= var.Z(varX,varY,varZ,var);
        cout <<"\n\nTHE DERIVATIVE WRT X IS " <<result1 <<endl;
        cout <<"THE DERIVATIVE WRT Y IS " <<result2 <<endl;
        cout <<"THE DERIVATIVE WRT Z IS " <<result3 <<endl;
    }

    //TO PREVENT THE PROGRAM FROM SELF-TERMINATING
    cout <<"\n\nENTER 'X' TO TERMINATE PROGRAM: ";
    char x= 'x';
    cin >>x;
    return 0;


}

