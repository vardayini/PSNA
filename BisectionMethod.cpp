//Practical #1: Bisection Method
#include<iostream>						                            //header files
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

float coef[20];
int deg;
float DOA;
float f(float a);

int main()
{

	cout<<"Enter the Number of Coefficients";
	cin>>deg;
	for(int i=deg;i>-1;i--)					                        //storing the coefficients in an Array
	{
		cout<<"Enter Coefficient of x^"<<i<<" :";
		cin>>coef[i];
	}
	cout<<"Enter the degree of Approximation :";
	cin>>DOA;
	float a,b;
	ag:
	cout<<"Enter Values for a and b :";
	cin>>a>>b;
	if(f(a)*f(b)>=0 || a>=b)
	{
		cout<<"Values of a and b not appropriate. Please Reenter";	//Validation
		goto ag;
	}
	int i=1,check=0;
	float x1=(a+b)/2;
	cout << left << setw(15) << setfill(' ')<<"i";
	cout << left << setw(15) << setfill(' ')<<"a";
	cout << left << setw(15) << setfill(' ')<<"x";
	cout << left << setw(15) << setfill(' ')<<"b";
	cout << left << setw(15) << setfill(' ')<<"f(a)";
	cout << left << setw(15) << setfill(' ')<<"f(b)";
	cout<<endl;
	while(check==0)					                                //Printing table and finding the solution
	{
		if(f(x1)==0)
		{
			check=1;


		}
		else if(fabs(f(x1))<DOA)
		{
			check=1;

		}
		else if((f(x1)*f(b))<0)
		{
			a=x1;
		}
		else if((f(x1)*f(a))<0)
		{
			b=x1;
		}


        cout << left << setw(15) << setfill(' ')<<i;
        cout << left << setw(15) << setfill(' ')<<a;
        cout << left << setw(15) << setfill(' ')<<x1;
        cout << left << setw(15) << setfill(' ')<<b;
        cout << left << setw(15) << setfill(' ')<<f(a);
        cout << left << setw(15) << setfill(' ')<<f(x1);
        cout<<endl;

		i++;
		x1=(a+b)/2;

	}
	cout<<"The root is: "<<x1<<"\n";
	return 0;
}

float f(float a)						                            //to evaluate the value of the f(a)
{
	float fa=0;
	for(int i=0;i<=deg;i++)
	{
		fa+=coef[i]*pow(a,i);
	}
	return fa;
}
