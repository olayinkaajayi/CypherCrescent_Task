#include "partialDiffFunctions.h"
#include "matrixFunctions.h"
#include "NewtonRaphson.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//************MAIN********************
int main()
{
    ofstream myfile;
    myfile.open("value.xls");

    partialDiff DxDt, DyDt, Trap1, Trap2;
    DxDt.cnt=0;
    DyDt.cnt=0;
    Trap1.cnt=0;
    Trap2.cnt=0;
    cout <<"WELCOME...\nTHIS PROGRAM SOLVES A SYSTEM OF TWO NONLINEAR ODE.\nPLEASE FOLLOW THE INSTRUCTIONS GIVEN BELOW.\n\n";

    cout <<"PROVIDE THE GIVEN INITIAL CONDITIONS:\n";
    cout <<"X(0)= ";
    double x0;
    cin >>x0;
    cout <<"Y(0)= ";
    double y0;
    cin >>y0;
    cout <<"\nENTER THE INTERVAL OF INTEREST t$[a,b]\na: ";
    double lowBound, upBound;
    cin >>lowBound;
    cout <<"b: ";
    cin >>upBound;
    cout <<"\nGIVE THE DESIRED MESH SIZE: ";
    double meshSize=1;
    cin >>meshSize;

    cout <<"\nENTER THE FIRST EQUATION IN THE SYSTEM:\n";
    long runner=0;//loop counter

    while(lowBound<upBound)
    {

        DxDt.at_x0_y0= DxDt.f(x0,y0,DxDt);
        if(runner==0)
            cout <<"\nENTER THE SECOND EQUATION IN THE SYSTEM:\n";

        DyDt.at_x0_y0= DyDt.f(x0,y0,DyDt);


//initializing the Trap1 function
        //integer coefficients
        Trap1.holdK[0]= -2/meshSize;
        Trap1.holdK[1]= 1;
        Trap1.holdK[2]= 0;
        Trap1.holdK[3]= 2*x0/meshSize;
        Trap1.holdK[4]= 0;
        Trap1.holdK[5]= 0;
        Trap1.holdK[6]= DxDt.at_x0_y0;
        Trap1.holdK[7]= 0;
        Trap1.holdK[8]= 0;
        for(int i=9, j=0; i<100; i++,j++)
        {
            Trap1.holdK[i]= DxDt.holdK[j];
        }
        //choice values
        for(int i=0; i<3; i++)
        {
            Trap1.holdChoice[i]= 1;
        }

        for(int i=3, j=0; i<50; i++,j++)
        {
            Trap1.holdChoice[i]= DxDt.holdChoice[j];
        }
        //operations
        Trap1.holdSym[0]= '+';
        Trap1.holdSym[1]= '+';
        Trap1.holdSym[2]= '+';
        for(int i=3, j=0; i<50; i++,j++)
        {
            Trap1.holdSym[i]= DxDt.holdSym[j];
        }
        Trap1.cnt=1;//shows that Trap1 already has values
//End of initializing the Trap1 function

//initializing the Trap2 function
        //integer coefficients
        Trap2.holdK[0]= -2/meshSize;
        Trap2.holdK[1]= 0;
        Trap2.holdK[2]= 1;
        Trap2.holdK[3]= 2*y0/meshSize;
        Trap2.holdK[4]= 0;
        Trap2.holdK[5]= 0;
        Trap2.holdK[6]= DyDt.at_x0_y0;
        Trap2.holdK[7]= 0;
        Trap2.holdK[8]= 0;

        for(int i=9, j=0; i<100; i++,j++)
        {
            Trap2.holdK[i]= DyDt.holdK[j];
        }
        //choice values
        for(int i=0; i<3; i++)
        {
            Trap2.holdChoice[i]= 1;
        }

        for(int i=3, j=0; i<50; i++,j++)
        {
            Trap2.holdChoice[i]= DyDt.holdChoice[j];
        }
        //operations
        Trap2.holdSym[0]= '+';
        Trap2.holdSym[1]= '+';
        Trap2.holdSym[2]= '+';
        for(int i=3, j=0; i<50; i++,j++)
        {
            Trap2.holdSym[i]= DyDt.holdSym[j];
        }
        Trap2.cnt=1;//shows that Trap2 already has values
//End of initializing the Trap2

        double AnswerX=0, AnswerY=0;


        NewtonRaph(Trap1,Trap2,x0,y0,AnswerX, AnswerY);
        lowBound +=meshSize;

        myfile <<fixed <<showpoint;
        myfile <<setprecision(4) <<lowBound <<"\t"<<AnswerX <<"\n";// <<"\t" <<AnswerY <<endl;


        ++runner;
        //reinitializing
        x0= AnswerX;
        y0= AnswerY;
    }//end of while loop

    //TO PREVENT THE PROGRAM FROM SELF-TERMINATING
    cout <<"\n\nENTER 'X' TO TERMINATE PROGRAM: ";
    char x= 'x';
    cin >>x;

    myfile.close();

    return 0;
}


//************MAIN********************

