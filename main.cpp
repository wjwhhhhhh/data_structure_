#include "DoubleLIst/DoubleList.h"
using namespace Eula;
int main() {
    DouList<int> a;
    for(int i=0;i<5;i++)a.push_front(i);
    a.erase(a.find(3));
    a.show();
    return 0;
}
