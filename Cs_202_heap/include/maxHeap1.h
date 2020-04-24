#ifndef MAXHEAP1_H
#define MAXHEAP1_H
#include <string>

using namespace std;

class maxHeap1
{
    public:
    maxHeap1(); // Done
    maxHeap1( const int** someArray, const int arraySize); // Done
    bool isEmpty() const; // Done
    int getNumberOfNodes() const; // Done
    int getHeight() const; // Done
    //int peekTop() const;
    //bool add( const int& newData); // Done
    bool add( const int* newData); // Done
    bool remove(int& removedItem);
    //void clear();
    void print();


    private:
        static const int ROOT_INDEX = 0;
        static const int MAX_CAPACITY = 2000;
        int* items;
        const int** data;
        int itemCount;
        int maxItems;
        bool heapEmpty;
        int getLeftChildIndex( const int nodeIndex) const; // Done
        int getRightChildIndex( int nodeIndex) const; // Done
        int getParentIndex( int nodeIndex) const; // Done
        bool isLeaf( int nodeIndex) const; // Done
        void heapRebuild( int subTreeRootIndex); // Done
        void heapCreate(); // Done
};

#endif // MAXHEAP1_H
