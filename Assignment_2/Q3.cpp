// Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1
// distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array
// (a) Linear time
// (b) Using binary search.

// (a) Linear time
#include <iostream>
using namespace std;

int main() {
    int size, i, missing = - 1;
    cout<<"size: ";
    cin>>size;

    int *arr = new int[size];
    cout<<"Elements: ";
    for( i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    for(i=0; i<size; i++)
    {
        if(arr[i] + 1 != arr[i+1])
        {
            missing = arr[i] + 1;
            break;
        }
    }

    if(missing == -1)
    {
        cout<<"There's no missing integer."<<endl;
    }
    else
    {
        cout<<"The missing integer is: "<<missing<<endl;
    }

    return 0;
}


// (b) Binary search
#include <iostream>
using namespace std;

int main() {
    int size,i, missing;
    cout<<"size: ";
    cin>>size;

    int *arr = new int[size];
    cout<<"Elements: ";
    for(i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    int mid, low = 0, high = size - 1;

    for(i = 0 ;i<size; i++)
    {
        mid = (low + high)/2;

        if(arr[mid] == mid + 1)
        {
            low = mid + 1;
        }
        else
        {
            missing = mid + 1;
            high = mid - 1;
        }
    }

    cout<<"missing element is: "<<missing<<endl;

    delete[] arr;

    
    return 0;
}
