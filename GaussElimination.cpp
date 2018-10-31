//Practical #7: Gauss Elimination method
#include<stdlib.h>                                  //header files
#include<math.h>
#include<iostream>
#include<iomanip>
using namespace std;

void display (float a[20][20], int N);              //declaring arrays to store the matrix and answer after every step
void swap(int &a, int &b);
int main()
{

	float ans[10]= {0};
	float a[20][20];
	int N,i,j;
	cout<<"\nEnter number of variables:";           //taking input
    cin>>N;
    cout<<"\nEnter the elements of augmented matrix row-wise:\n";
    for(i=0; i<N; i++)
    {   cout<<"Enter the coefficient of the equation "<<i<<"and the constant \n";
        for(j=0; j<(N+1); j++)
        {
            cout<<" A["<<i<<"]["<<j<<"]:";
            cin>>a[i][j];
        }
    }

	display(a,N);
	cout<<endl;
	int k;



    for(k=0; k<(N-1); k++)
    {

        int I=0;
        float max=0;
        float coef=0;
                                                    //finding the index of the maximum absolute value
            for(int i=k; i<N; i++)
            {
                if(fabs(a[i][k])>max)
                {
                    max=fabs(a[i][k]);
                    I=i;
                }
            }
                                                    //swapping rows with the pivot row
        if(I!=k)
        {
            for(int j=0; j<(N+1); j++)
                swap(a[k][j], a[I][j]);
            display(a,N);
            cout<<endl;
        }
                                                    //making the column below the pivot zero
        for(i=(k+1); i<N; i++)
        {
            coef = (a[i][k]/a[k][k]);
            cout<<coef<<endl;
            for(int j=0; j<(N+1); j++)
                a[i][j]=(a[i][j]-coef*a[k][j]);
        }

        display(a,N);
        cout<<endl;
    }


    for(i=(N-1); i>=0; i--)                         //back substitution to find the solution of the equation
	{
		float temp=0;
		for(j=(N-1); j>i; j--)
		{
			temp+= ans[j]*a[i][j];
		}
		cout<<endl;
		ans[i]=(a[i][N]-temp)/a[i][i];
	}
	for(i=0; i<N; i++)
		cout<<"x"<<(i+1)<<": "<<ans[i]<<endl;


return 0;
}

void swap(int &a, int&b)                                   //Function to swap
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void display(float arr[20][20],int N)                      //Function to Display
{

    for(int i=0; i<N; i++)
    {

        for(int j=0; j<(N+1); j++)
                cout << left << setw(20) << setfill(' ')<<arr[i][j]<<" ";
        cout<<endl;
    }
}

