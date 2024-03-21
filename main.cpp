#include "DoubleLIst/DoubleList.h"
using namespace Eula;
int main() {
    DouList<int> a;
    a.push_back(1);
    for(int i=0;i<5;i++)a.push_front(i);
    for(auto c:a)cout<<c<<endl;
    return 0;
}
