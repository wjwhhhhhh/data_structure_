#include "list/list.hpp"
using namespace Eula;
int main() {
    List<int> a;
    for(int i=0;i<5;i++)a.push_front(i);
    a.show();
    List<int>b(a);
    b.show();
    return 0;
}
