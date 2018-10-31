//Practical #4: Forward Interpolation
#include<iostream>								                        //header files
#include<stdio.h>
#include<math.h>
using namespace std;

int fact(int X);
int main()
{
	float p, x[20], y[20], X, Y;
	int pairs, i, j;
	cout<<"Enter the number of pairs of 'x' and 'y'\n";			         //taking input of pairs of x and y
	cin>>pairs;
	float y0[pairs][pairs];
		here:
	cout<<"Enter the values of 'x' and corresponding values of 'y'\n";
	for(i=0;i<pairs;i++)
		{
			cout<<"x"<<i<<":";
			cin>>x[i];
			if(i>1 && ((x[i]-x[i-1]!=x[i-1]-x[i-2]) || x[i]==x[i-1]))   //checking if its in range
			{
			    cout<<"the entered value of x is not at equal interval\n";
			    goto here;
			}

			cout<<"\ty"<<i<<":";
			cin>>y0[i][0];
			cout<<endl;
		}


	for(i=0;i<pairs;i++)
		{
			for(j=0;j<pairs-i-1;j++)
				{
					y0[j][i+1]=y0[j+1][i]-y0[j][i];		                //Generating the difference table
				}
		}
	float h=x[1]-x[0];
	HIT:
	cout<<"Enter x for which you want to find the value of y";		    //Validation
	cin>>X;
	if (X>x[pairs-1]||X<x[0])
	{
	    printf("Please reneter value of X\n");
	    goto HIT;
	}
	p=(X-x[0])/h;

	Y= y0[0][0];
	for(i=1;i<pairs-1;i++)
		{
			Y=Y+(p*y0[0][i])/fact(i);				                    //Evaluating Formula
			p=p*(p-i);
		}
	cout<<"X\tY\t";
	for(int j=1;j<pairs;j++)
		cout<<"d"<<j<<"y\t";
	cout<<endl;

	for(i=0;i<pairs;i++)
		{	cout<<x[i]<<"\t";
			for(j=0;j<pairs-i;j++)
			{
				cout<<y0[i][j]<<"\t";				//printing the table

			}
			cout<<endl;
		}
	cout<<"\n\nValue of Function at x = "<<X<<" is : "<<Y<<endl;

}
	int fact(int X)								//function to find the factorial
		{
			int fact=1;
			for(int i=2;i<=X;++i)
				{
					fact=fact*i;
				}
			return fact;
		}
