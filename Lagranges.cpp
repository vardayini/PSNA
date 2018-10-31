//Practical 6: Lagranges

#include<iostream>							                //header files
#include<stdio.h>
#include<math.h>
using namespace std;

int fact(int X);
int main()
{
	float X;
	float Y=0.0;
	int pairs, i, j;

	cout<<"Enter the number of pairs of 'x' and 'y'\n";		//taking input of pairs of x and y
	cin>>pairs;
	float y[pairs],x[pairs];

	cout<<"Enter the values of 'x' and corresponding values of 'y'\n";
	for(i=0;i<pairs;i++)
	{
		cout<<"x"<<i<<":";
		cin>>x[i];
		cout<<"\ty"<<i<<":";
		cin>>y[i];
		cout<<endl;
	}
	for(i=0;i<pairs;i++)						            //Printing the table
	{
		cout<<"x"<<i<<":";
		cout<<x[i];
		cout<<"\ty"<<i<<":";
		cout<<y[i];
		cout<<endl;
	}
	cout<<"Enter the value of x for which you want to find the value of y\n";
	cin>>X;

	for(i=0;i<pairs;i++)
	{
		float t1=1;
		float t2=1;

		for(j=0;j<pairs;j++)
		{							                           //calculating t1=(X-X1)(X-X2)(X-X3)...& t2=(X0-X1)(X0-X2)(X0-X3)

		 	if(j==i)					                        //to skip terms like X0-X0 in the denominator we continue the loop
				continue;
			else
		 	{
		 		t2=t2*(x[i]-x[j]);
		 		t1=t1*(X-x[j]);
		 	}

		}
		Y=Y+(t1*y[i]/t2);					                    //Calculating Y= t01/t02*Y0 +t11/t12*Y1+....
	}
	cout<<"The value of Y at x="<<X<<" is "<<Y<<endl;
	return 0;
}
