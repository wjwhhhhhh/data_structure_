#include <iostream>
#include "priority_queue/priority_queue.hpp"
using namespace std;
int main() {
    using namespace Eula::PriorityQueue;
    PriorityQueue<int>a;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int tem;
        cin>>tem;
        a.push(tem);
    }
    for(int i=0;i<m;i++)
    {
        cout<<a.top()<<endl;
        a.pop();
    }

    return 0;
}
