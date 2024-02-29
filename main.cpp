#include <iostream>
#include "priority_queue/priority_queue.hpp"
using namespace std;
int main() {
    using namespace Eula::PriorityQueue;
    PriorityQueue<int>a;

    for(int i=0;i<10;i++)
    {
        int tem=i;
        a.push(tem);
    }
    for(auto c:a)cout<<c<<endl;

    return 0;
}
