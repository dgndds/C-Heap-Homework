#include <iostream>
#include "maxHeap1.h"

using namespace std;

int main()
{
    //std::cout << "Hello, World!" << std::endl;
    int foo [7] = { 5, 1, 2, 4, 6, 7, 8 };
    maxHeap1 heap = maxHeap1(foo,7);


    heap.print();

    //heap.add()

    cout << heap.isEmpty() << endl;
    return 0;
}
