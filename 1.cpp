#include <iostream>
using namespace std;

int binarysearch(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // if x is large ignore left half
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        // if x is smaller ignore the right half
        else
            high = mid - 1;
    }
    // if we reach there the element was not present
    return -1;
}
int main()
{
    vector<int> arr = {2, 3, 4, 10, 40};
    int x=10;
    int result = binarysearch(arr, x);
    if (result == -1)
        cout << "the element was not present";
    else
        cout << "Element is present at index: " << result << endl;
    return 0;
}