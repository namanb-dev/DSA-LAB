// Space required to store any two-dimensional array is number oƒ rows × number oƒ
// columns. Assuming array is used to store elements of the following matrices,
// implement an efficient way that reduces the space requirement.
// (a) Diagonal Matrix.
// (b) Tri-diagonal Matrix.
// (c) Lower triangular Matrix.
// (d) Upper triangular Matrix.
// (e) Symmetric Matrix



#include <iostream>
using namespace std;

void diagonal()
{

    int arr[4];
    int i, j;
    cout<<"Enter the diagonal elements: ";
    for(i=0; i<4; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<4;i++)
    {
        for(j=0; j<4; j++)
        {
            if(i==j)
            {
                cout<<arr[i]<<' ';
            }
            
            else
            {
                cout<<'0'<<" ";
            }
        }
        cout<<endl;
    }
}

void Tri_diagnoal()
{
    int lower[3], main_diagonal[4], uper[3];
    int i,j;
    cout<<"Enter the lower diagnoal: ";
    for(i=0; i<3; i++)
    {
        cin>>lower[i-1];
    }
    cout<<"Enter the main diagnoal: ";
    for(i=0; i<4; i++)
    {
        cin>>main_diagonal[i];
    }
    cout<<"Enter the uper diagnoal: ";
    for(i=0; i<3; i++)
    {
        cin>>uper[i];
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(i==j)
            {
                cout<<main_diagonal[i]<<" ";
            }
            else
            {
                if((i-1)==j)
                {
                    cout<<lower[i-1]<<" ";
                }
                else
                {
                    if((i+1)==j)
                    {
                        cout<<uper[i]<<' ';
                    }
                    else
                    {
                        cout<<"0"<<" ";
                    }
                }
            }
        }
        cout<<endl;
    }
}

void lower_triangular()
{
    int main_diagonal[4], lower_diagonal[3], more_lower_diagonal[2], last_lower[1];
    int i,j;
    cout<<"Enter the main diagonal: ";
    for(i=0; i<4; i++)
    {
        cin>>main_diagonal[i];
    }
    cout<<"Enter the lower diagonal: ";
    for(i=0; i<3; i++)
    {
        cin>>lower_diagonal[i];
    }
    cout<<"Enter the more lower diagonal: ";
    for(i=0; i<2; i++)
    {
        cin>>more_lower_diagonal[i];
    }
    cout<<"Enter the last diagonal: ";
    for(i=0; i<1; i++)
    {
        cin>>last_lower[i];
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(i==j)
            {
                cout<<main_diagonal[i]<<' ';
            }
            else
            {
                if((i-1)==j)
                {
                    cout<<lower_diagonal[i-1]<<' ';
                }
                else
                {
                    if((i-2)==j)
                    {
                        cout<<more_lower_diagonal[i-2]<<" ";
                    }
                    else
                    {
                        if((i-3)==j)
                        {
                            cout<<last_lower[i-3]<<' ';
                        }
                        else
                        {
                            cout<<"0"<<" ";
                        }
                    }
                }
            }
        }
        cout<<endl;
    }

}

void upper_triangular()
{
    int main_diagonal[4], upper_diagonal[3], more_upper_diagonal[2], last_upper[1];
    int i, j;
    cout<<"Enter the main diagonal: ";
    for(i=0; i<4; i++)
    {
        cin>>main_diagonal[i];
    }
    cout<<"Enter the Upper diagonal: ";
    for(i=0; i<3; i++)
    {
        cin>>upper_diagonal[i];
    }
    cout<<"Enter the More upper diagonal: ";
    for(i=0; i<2; i++)
    {
        cin>>more_upper_diagonal[i];
    }
    cout<<"Enter the last upper diagonal: ";
    for(i=0; i<1; i++)
    {
        cin>>last_upper[i];
    }
    
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(i==j)
            {
                cout<<main_diagonal[i]<<" ";
            }
            else
            {
                if((i+1)==j)
                {
                    cout<<upper_diagonal[i+1]<<" ";
                }
                else
                {
                    if((i+2)==j)
                    {
                        cout<<more_upper_diagonal[i+2]<<" ";
                    }
                    else
                    {
                        if((i+3)==j)
                        {
                            cout<<last_upper[i+3]<<" ";
                        }
                        else
                        {
                            cout<<"0"<<" ";
                        }
                    }
                }
            }
        }
        cout<<endl;
    }
}

void symmetric()
{
    int main[16];
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            cout<<"Enter the element of matrix["<<i<<","<<j<<"]: ";
            cin>>main[j];
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            cout<<main[j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    // (a) Diagonal matrix
    // cout<<"Diagonal matrix "<<endl;
    // diagonal();

    cout<<endl;

    // (b) Tri-Diagnoal matrix
    // cout<<"tri-diagonal matrix "<<endl;
    // Tri_diagnoal();

    cout<<endl;

    // (c) Lower triangular Matrix
    // cout<<"lower triangular matrix: "<<endl;
    // lower_triangular();

    cout<<endl;

    // (d) Upper triangular Matrix
    // cout<<"Upper triangular matrix: "<<endl;
    // upper_triangular();

    cout<<endl;
    
    // (e) symmetric matrix
    // cout<<"symmetric matrix: ";
    // symmetric();

    return 0;
}
