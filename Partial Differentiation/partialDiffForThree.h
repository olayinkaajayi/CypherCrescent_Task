#ifndef PARTIALDIFFFORTHREE_H_INCLUDED
#define PARTIALDIFFFORTHREE_H_INCLUDED

#include <iostream>
#include <cmath>

using namespace std;

//************partialDiff*******************
class partialDiff
{
private:
    static const double h= 0.00001;//mesh size
    double neg1,neg2,pos1,pos2;

public:
    int cnt;//keeps track of how many times a function is called
    double holdK[100];//hold integer constants in the function f
    char holdSym[50];//hold the operations in the function f
    unsigned int holdChoice[50];//hold the choices of indx in the function f


    double f(double,double,double,partialDiff&);
    double X(double,double,double,partialDiff&);
    double Y(double,double,double,partialDiff&);
    double Z(double,double,double,partialDiff&);



};
//************partialDiff****************


//**********function f**********************
double partialDiff::f(double x,double y,double z,partialDiff& objFunc)
{
    int ind_num=-1, ind_ch=-1, ind_choi=-1;//keeps track of array index for numbers,symbols & choice
    if(objFunc.cnt==0)
    {
        cout <<"\n\nPROCEED TO ENTER THE COEFFICIENTS OF THE FUNCTION AS THEY APPEAR BELOW:\n";
    }

    double sum=0; //of terms of function
    double prod=1;//product of terms in functn
    double k[5];//k represents the coefficients of the terms;
    double evaluated;//to hold expression temporarily;
    int counter= 0;//control variable
    char sym='+';//represents variable for operation
    char lastChoice=sym, newChoice='*',forDot='x';
    int dummy= 1;//just a dummy variable
    while ((sym=='+')||(sym=='*'))
    {
        //allows requesting of symbol start after first iteration
        if(counter>0)
        {
            //gives out values already stored
            if(objFunc.cnt>0)
            {

                sym= objFunc.holdSym[++ind_ch];
            }
            else
            {
                cout <<"ENTER THE NEXT OPERATOR * or +\nOPERATOR (ENTER '.' TO END INPUT FOR FUNCTION): ";
                cin >>sym;

                forDot= sym;
                //THIS STATEMENT IS TO ALLOW FOR THE ZERO EXPRESSION
                if(sym=='.')
                {
                    sym= '+';
                }


                objFunc.holdSym[++ind_ch]= sym;//stores values to be used in further calling of function f
            }
            newChoice=sym;//control variable

            //terminates the loop when a different symbol is encountered
            if ((sym!='+')&&(sym!='*'))
            {
                break;
            }
        }


        unsigned int indx;

edit: //gives out values already stored
        if(objFunc.cnt>0)
        {

            indx= objFunc.holdChoice[++ind_choi];
        }
        else
        {
            if(forDot=='.')
            {
                indx=1;
            }
            else
            {
                cout <<"\n1)ALGEBRAIC 2)COS 3)SIN 4)TAN 5)EXP\n";
                cout <<"ENTER CHOICE: ";
                cin >>indx;
            }


            objFunc.holdChoice[++ind_choi]= indx;//stores values to be used in further calling of function f
        }

        switch(indx)
        {
        case 1:


            //gives out values already stored
            if(objFunc.cnt>0)
            {
                for(int i=0; i<4; i++)
                {

                    k[i]= objFunc.holdK[++ind_num];
                }

            }
            else
            {
                if(forDot=='.')
                {
                    k[0]=0;
                    k[1]=0;
                    k[2]=0;
                    k[3]=0;
                }
                else
                {
                    cout <<"\nk1.X^(k2).Y^(k3).Z^(k4)";
                    cout <<"\nENTER k1, k2, k3 respectively: ";
                    cin >> k[0]>>k[1]>>k[2]>>k[3];
                }

                //stores values to be used in further calling of function f
                for(int i=0; i<4; i++)
                {

                    objFunc.holdK[++ind_num]= k[i];
                }

            }


            evaluated= k[0]*pow(x,k[1])*pow(y,k[2])*pow(z,k[3]);
            break;



        case 2:

            //gives out values already stored
            if(objFunc.cnt>0)
            {
                for(int i=0; i<5; i++)
                {

                    k[i]= objFunc.holdK[++ind_num];
                }

            }
            else
            {
                cout <<"\nk1.cos[k2.X^(k3).Y^(k4).Z^(k5)]";
                cout <<"\nENTER k1, k2, k3, k4, k5 rspectively: ";
                cin >> k[0]>>k[1]>>k[2]>>k[3]>>k[4];
                //stores values to be used in further calling of function f
                for(int i=0; i<5; i++)
                {

                    objFunc.holdK[++ind_num]= k[i];
                }
            }
            evaluated= k[0]*cos(k[1]*pow(x,k[2])*pow(y,k[3])*pow(z,k[4]));
            break;



        case 3:

            //gives out values already stored
            if(objFunc.cnt>0)
            {
                for(int i=0; i<5; i++)
                {

                    k[i]= objFunc.holdK[++ind_num];
                }

            }
            else
            {
                cout <<"\nk1.sin[k2.X^(k3).Y^(k4).Z^(k5)]";
                cout <<"\nENTER k1, k2, k3, k4, k5 rspectively: ";
                cin >> k[0]>>k[1]>>k[2]>>k[3]>>k[4];
                //stores values to be used in further calling of function f
                for(int i=0; i<5; i++)
                {

                    objFunc.holdK[++ind_num]= k[i];
                }
            }

            evaluated= k[0]*sin(k[1]*pow(x,k[2])*pow(y,k[3])*pow(z,k[4]));
            break;



        case 4:

            //gives out values already stored
            if(objFunc.cnt>0)
            {
                for(int i=0; i<5; i++)
                {

                    k[i]= objFunc.holdK[++ind_num];
                }

            }
            else
            {
                cout <<"\nk1.tan[k2.X^(k3).Y^(k4).Z^(k5)]";
                cout <<"\nENTER k1, k2, k3, k4, k5 rspectively: ";
                cin >> k[0]>>k[1]>>k[2]>>k[3]>>k[4];
                //stores values to be used in further calling of function f
                for(int i=0; i<5; i++)
                {

                    objFunc.holdK[++ind_num]= k[i];
                }
            }

            evaluated= k[0]*tan(k[1]*pow(x,k[2])*pow(y,k[3])*pow(z,k[4]));
            break;



        case 5:
            //gives out values already stored
            if(objFunc.cnt>0)
            {
                for(int i=0; i<5; i++)
                {

                    k[i]= objFunc.holdK[++ind_num];
                }

            }
            else
            {
                cout <<"\nk1.exp[k2.X^(k3).Y^(k4).Z^(k5)]";
                cout <<"\nENTER k1, k2, k3, k4, k5 rspectively: ";
                cin >> k[0]>>k[1]>>k[2]>>k[3]>>k[4];
                //stores values to be used in further calling of function f
                for(int i=0; i<5; i++)
                {

                    objFunc.holdK[++ind_num]= k[i];
                }
            }

            evaluated= k[0]*exp(k[1]*pow(x,k[2])*pow(y,k[3])*pow(z,k[4]));
            break;



        default:
            cout <<"\nWRONG INPUT!";
            goto edit;

        }//end switch


//**********************************
//Begining from here, this section is meant to allow for adding up the "evaluated" expressions above
        if(sym=='*')
        {
            prod *=evaluated;
        }
        if(sym=='+')
        {
            if(lastChoice=='*' && newChoice=='+')
            {
                sum +=(prod + evaluated);
            }
            else
            {
                if(prod==dummy)
                    sum +=evaluated;
                else
                {
                    sum +=prod;
                    prod= dummy;
                }
            }

        }
//*********************************
        ++counter;//control variable
        lastChoice=sym;
        if(forDot=='.')
        {
            objFunc.holdSym[++ind_ch]= '.';
            break;
        }


    }//end while

    ++objFunc.cnt;

    return sum;

}//***********end of function f***********


//***********Derivative wrt X***********
double partialDiff::X(double x,double y,double z, partialDiff& fun)
{

    neg1= x - 1*h;
    neg2= x - 2*h;
    pos1= x + 1*h;
    pos2= x + 2*h;
//formula for numerical differentiation
    return (f(neg2,y,z,fun) - 8*f(neg1,y,z,fun) + 8*f(pos1,y,z,fun) - f(pos2,y,z,fun))/(12*h);

}
//***********Derivative wrt X***********


//***********Derivative wrt Y***********
double partialDiff::Y(double x,double y,double z,partialDiff& fun)
{

    neg1= y - 1*h;
    neg2= y - 2*h;
    pos1= y + 1*h;
    pos2= y + 2*h;
//formula for numerical differentiation
    return (f(x,neg2,z,fun) - 8*f(x,neg1,z,fun) + 8*f(x,pos1,z,fun) - f(x,pos2,z,fun))/(12*h);

}
//***********Derivative wrt Y**********


//***********Derivative wrt Z***********
double partialDiff::Z(double x,double y,double z, partialDiff& fun)
{

    neg1= z - 1*h;
    neg2= z - 2*h;
    pos1= z + 1*h;
    pos2= z + 2*h;
//formula for numerical differentiation
    return (f(x,y,neg2,fun) - 8*f(x,y,neg1,fun) + 8*f(x,y,pos1,fun) - f(x,y,pos2,fun))/(12*h);

}
//***********Derivative wrt Z***********




#endif // PARTIALDIFFFORTHREE_H_INCLUDED
