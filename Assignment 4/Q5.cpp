// Write a program to implement a stack using
// a) Two queues

#include <iostream>
#include <queue>
using namespace std;
class mystack
{
    queue<int> q1, q2;
    public:
    void push(int n)
    {
        q1.push(n);
    }
    int peek()
    {
        if (!isEmpty())
        {
            while (q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int ans = q1.front();
            q1.pop();
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
            q1.push(ans);
            return ans;
        }
        return -1;
    }
    void pop()
    {
        if (!isEmpty())
        {
            while (q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    bool isEmpty()
    {
        return q1.empty();
    }

};
 int main()
{
    mystack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.peek() << endl;
    st.pop();
    cout << "top: " <<st.peek() << endl;
    st.pop();
    cout << "top: " << st.peek() << endl;
    st.pop();
    cout << "top: " << st.peek() << endl;
    return 0;
}

// (b) One Queue.

#include <iostream>
#include <queue>
using namespace std;
class mystack
{
    queue<int> q1;

public:
    void push(int n)
    {
        q1.push(n);
    }
    int top()
    {
        if (!q1.empty())
        {
            int size=q1.size();
            for(int i=0;i<size-1;i++)
            {
                q1.push(q1.front());
                q1.pop();
            }
            int ans = q1.front();
            q1.push(q1.front());
            q1.pop();
            return ans;
        }
        return -1;
    }
    void pop()
    {
        if(!q1.empty())
        {
            int size=q1.size();
        for(int i=0;i<size-1;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }
        q1.pop();
    }
};
int main()
{
    mystack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top: " << st.top() << endl;
    return 0;
}
