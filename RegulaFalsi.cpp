//Practical 2: Regula Falsi Method
#include<iostream>
#include<stdio.h>
#include<math.h>							//Header files
#include<stdlib.h>
#include<iomanip>
using namespace std;

float coef[20];
int deg;
float DOA;

float f(float a)							//To evaluate the function f(a)
{
	float fa=0;
	for(int i=0;i<=deg;i++)
	{
		fa+=coef[i]*pow(a,i);
	}
	return fa;
}

int main()
{

	cout<<"Enter the Number of Coefficients";
	cin>>deg;
	for(int i=deg;i>-1;i--)
	{
		cout<<"Enter Coefficient of x^"<<i<<" :";			//Storing coefficients of the equation
		cin>>coef[i];
	}
	cout<<"Enter the degree of Approximation :";
	cin>>DOA;
	float a,b;
	here:
	cout<<"Enter Values for a and b :";
	cin>>a>>b;
	if(f(a)*f(b)>=0 || a>=b)
	{
		cout<<"Values of a and b are not appropriate. Please Reenter";	//Validation
		goto here;
	}
	int i=1,check=0;
	float c;
    cout << left << setw(15) << setfill(' ')<<"i";
	cout << left << setw(15) << setfill(' ')<<"a";
	cout << left << setw(15) << setfill(' ')<<"c";
	cout << left << setw(15) << setfill(' ')<<"b";
	cout << left << setw(15) << setfill(' ')<<"f(a)";
	cout << left << setw(15) << setfill(' ')<<"f(c)";
	cout << left << setw(15) << setfill(' ')<<"f(b)";
	cout<<endl;

	while(check==0)
	{       c=(a*f(b)-b*f(a))/(f(b)-f(a)); 					//putting the value of a and b in the formula
		if(f(c)==0)
		{
			check=1;						//Flag to check whether it finds the exact case


		}
		else if(fabs(f(c))<DOA)
		{
			check=1;

		}
		else if((f(c)*f(b))<0)
		{
			a=c;
		}
		else if((f(c)*f(a))<0)
		{
			b=c;
		}

        cout << left << setw(15) << setfill(' ')<<i;
        cout << left << setw(15) << setfill(' ')<<a;
        cout << left << setw(15) << setfill(' ')<<c;
        cout << left << setw(15) << setfill(' ')<<b;
        cout << left << setw(15) << setfill(' ')<<f(a);
        cout << left << setw(15) << setfill(' ')<<f(c);
        cout << left << setw(15) << setfill(' ')<<f(b);
        cout<<endl;                                                     	//Printing table and solution
		i++;


	}
	cout<<"The root is "<<c<<"\n";

	return 0;
}

