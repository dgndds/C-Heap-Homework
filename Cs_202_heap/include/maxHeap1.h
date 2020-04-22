#ifndef MAXHEAP1_H
#define MAXHEAP1_H


class maxHeap1
{
    public:
    maxHeap();
    maxHeap( const int someArray[], const int arraySize); // Done
    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    int peekTop() const;
    bool add( const int& newData);
    bool remove();
    void clear();

    private:
        static const int ROOT_INDEX = 0;
        static const int MAX_CAPACITY = 2000;
        int* items;
        int itemCount;
        int maxItems;
        int getLeftChildIndex( const int nodeIndex) const; // Done
        int getRightChildIndex( int nodeIndex) const; // Done
        int getParentIndex( int nodeIndex) const; // Done
        bool isLeaf( int nodeIndex) const;
        void heapRebuild( int subTreeRootIndex); // Done
        void heapCreate(); // Done
};

#endif // MAXHEAP1_H
