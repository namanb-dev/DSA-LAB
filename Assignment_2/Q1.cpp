// Implement the Binary search algorithm regarded as a fast search algorithm with
// run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int Binary_Search(int arr[], int Target, int size )
{
    int mid,i;
    int low = 0;
    int high = size - 1;

    for(i=0; i<size; i++)
    {
        mid = (low + high)/2;

        if(arr[mid] == Target)
        {
            return mid;
        }
        else
        {
            if(arr[mid] < Target)
            {
                low = mid + 1; // search the right side
            }
            else
            {
                high = mid - 1; // search the left side
            }
        }
    }
    
    return -1;
}

int main() {
    int size;
    cout<<"size: ";
    cin>>size;

    int* arr = new int[size]; // dynamic allocation of array
    int i;
    cout<<"Enter the elements: ";
    for(i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    int Target;
    cout<<"Enter the target: ";
    cin>>Target;

    int result = Binary_Search(arr, Target, size);

    if (Target == -1)
    {
        return -1;
    }
    else
    {
        cout<<result<<endl;
    }
    return 0;
}
