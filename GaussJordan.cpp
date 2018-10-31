//practical #8: Gauss Jordan method
#include<stdlib.h>                                  //header files
#include<math.h>
#include<iostream>
#include<iomanip>

using namespace std;
void display (float a[20][20], int N);
int main()
{
    int i,j,k,n;
    float A[20][20],x[10];                          //declaring variables
    float temp;
    cout<<"\nEnter number of variables:";           //taking input
    cin>>n;
    cout<<"\nEnter the elements of augmented matrix row-wise:\n";
    for(i=1; i<=n; i++)
    {   cout<<"Enter the coefficient of the equation "<<i<<"and the constant \n";
        for(j=1; j<=(n+1); j++)
        {
            cout<<" A["<<i<<"]["<<j<<"]:";
            cin>>A[i][j];
        }
    }

    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j )
            {
                temp=A[i][j]/A[j][j];                //finding constant which when multiplied to the term and when that term subtracted makes it zero
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-temp*A[j][k];
                }
                display(A,n);
                cout<<endl;
                cout<<endl;
                cout<<endl;
            }
        }
    }
    cout<<"\nThe solution is:\n";
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];                      //turning it into an identity matrix;
        cout<<"\n x"<<i<<"="<<x[i]<<endl;
    }
    return(0);
}
void display(float arr[20][20],int N)                //Function to Display
{

    for(int i=0; i<N; i++)
    {

        for(int j=0; j<(N+1); j++)
            cout << left << setw(20) << setfill(' ')<<arr[i][j]<<" ";
        cout<<endl;
    }
}
