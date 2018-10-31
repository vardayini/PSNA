//Practical #3: Newton Raphson Method

#include<iostream>				                                       //Header Files
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;


float coef[20];
int deg;
float DOA;

float fd1(float a);
float fd2(float a);
float f(float a);

int main()
{
	cout<<"Enter the Degree of the Polynomial";
	cin>>deg;

	for(int i=deg;i>-1;i--)			                                //taking the input
	{
		cout<<"Enter Coefficient of x^"<<i<<" :";
		cin>>coef[i];
	}
	cout<<"Enter the degree of Approximation :";
	cin>>DOA;


	float x;
	here:
	cout<<"Enter Value of x0 :";
	cin>>x;

	if((f(x)*fd2(x))>=(fd1(x)*fd1(x)))                           //Checking the Convergence Criteria
	{
		cout<<"Value of x0 not appropriate. Please Reenter";
		goto here;
	}
	int i=0,flg=0;
	float x1;
    cout << left << setw(15) << setfill(' ')<<"i";
	cout << left << setw(15) << setfill(' ')<<"x(i)";
	cout << left << setw(15) << setfill(' ')<<"f(xi)";
	cout << left << setw(15) << setfill(' ')<<"fd(xi)";
	cout << left << setw(15) << setfill(' ')<<"x(i+1)";
	cout<<endl;


	while(flg==0)
	{

		if(f(x1)==0)			                                 //Checking if the value of the function is equal to zero
		{
			flg=1;
		}

		else if(fabs(f(x1))<DOA)	                             //Checking if the Value of the function is within the degree of Approximation
		{
			flg=1;
		}

		x1=(x-(f(x)/fd1(x)));		                            //Calculating the new Value of x

    cout << left << setw(15) << setfill(' ')<<i;
	cout << left << setw(15) << setfill(' ')<<x;
	cout << left << setw(15) << setfill(' ')<<f(x);
	cout << left << setw(15) << setfill(' ')<<fd1(x);
    cout << left << setw(15) << setfill(' ')<<x1;
	cout<<endl;
		i++;
		x=x1;

	}
	cout<<"\n\nThe root obtained is : "<<x<<endl;               //Displaying root obtained
	cout<<"Value of Function is : "<<f(x)<<endl;

	return 0;
}
float fd1(float a)				                                    //Function to calculate the first derivative of the dunction
{
	float fa=0;
	for(int i=1;i<=deg;i++)
	{
		fa+=coef[i]*pow(a,i-1)*i;
	}
	return fa;
}

float fd2(float a)				                                    //Function to calculate the double derivative of the function
{
	float fa=0;
	for(int i=2;i<=deg;i++)
	{
		fa+=coef[i]*pow(a,i-2)*i*(i-1);
	}
	return fa;
}


float f(float a)				                                     //Function to evaluate the polynomial
{
	float fa=0;
	for(int i=0;i<=deg;i++)
	{
		fa+=coef[i]*pow(a,i);
	}
	return fa;
}
