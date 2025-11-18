// Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
// b c Sample O/P: a -1 b b

#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main()
{
    string st="aabc",ans="";

    int count['z'-'a'+1]={0};
    queue <char>q;
    for(int i=0;i<st.length();i++)
    {
        count[st[i]-'a']++;
        q.push(st[i]);
    }
    while(!q.empty())
    {
        if(count[q.front()-'a']>1)
        {
            count[q.front()-'a']--;
            ans+="-1";
            q.pop();
        }
        else
        {
            ans+=q.front();
            q.pop();
        }
    }
    cout<<ans;
    return 0;
}
