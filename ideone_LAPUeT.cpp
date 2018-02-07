#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 
 
struct thing
{
    int a;
    char b;
    bool operator<(const thing& rhs) const
    {
        return a > rhs.a;// small to greater
        return a < rhs.a;// greater to small
    }
};
 
 
int main()
{
    priority_queue<thing> q;
    thing stuff = {42, 'x'};
    q.push(stuff);
    q.push(thing{4242, 'y'}); // C++11 only
   // q.emplace(424242, 'z'); // C++11 only
    thing otherStuff = q.top();
    //stuff = q.top();
    cout << otherStuff.a << endl;
	return 0;
}
