#include "list/list.hpp"
using namespace Eula;
int main() {
    List<int> a;
    for(int i=0;i<15;i++)a.push_front(i);
    List<int> b=a;
    b.show();
    return 0;
}
