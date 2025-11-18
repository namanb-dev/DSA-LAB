// Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int size;
    queue <int> ques,inter;
    cout<<"enter number of elements: ";
    cin>>size;
    for(int i=1;i<=size;i++)
    {
        cout<<"enter element number "<<i<<" : ";
        int num;
        cin>>num;
        ques.push(num);
        cout<<endl;
    }
    for(int i=1;i<=(size+1)/2;i++)
    {
        inter.push(ques.front());
        ques.pop();
    }
    while(!ques.empty())
    {
        inter.push(inter.front());
        inter.pop();
        inter.push(ques.front());
        ques.pop();
    }
    if(size%2==1)
    {
        inter.push(inter.front());
        inter.pop();                
    }
    while(!inter.empty())
    {
        cout<<inter.front()<<" ";
        inter.pop();
    }
    return 0;
}
