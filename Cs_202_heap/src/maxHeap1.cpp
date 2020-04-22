#include "maxHeap1.h"


int maxHeap1::getLeftChildIndex( const int nodeIndex) const {
    return (2 * nodeIndex) + 1;
}

int maxHeap1::getRightChildIndex( const int nodeIndex) const {
    return (2 * nodeIndex) + 2;
}

int getParentIndex( int nodeIndex) const{
    return (nodeIndex - 1) / 2;
}

void maxHeap1::heapRebuild(int subTreeRootIndex){
    int child = getLeftChildIndex(ROOT_INDEX );	// index of root's left child, if any
	if ( child < itemCount) {
		// root is not a leaf so that it has a left child
		int rightChild = getRightChildIndex(ROOT_INDEX); 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < itemCount) && (items[rightChild] > items[child]) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[ROOT_INDEX] < items[child]) {
			int temp = items[ROOT_INDEX];
			items[ROOT_INDEX] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
        }

    }
}

void maxHeap1::heapCreate(){
    for ( int index = itemCount / 2; index >= 0; index--)
        heapRebuild(index);
}

maxHeap1::maxHeap( const int someArray[], const int arraySize){
    if(arraySize >= MAX_CAPACITY || (arraySize*2) >= MAX_CAPACITY){
        // Allocate the array
        items = new int[MAX_CAPACITY];
        maxItems = MAX_CAPACITY;
        itemCount = MAX_CAPACITY;
    }else{
        // Allocate the array
        items = new int[2 * arraySize];
        maxItems = 2 * arraySize;
        itemCount = arraySize;
    }

     //if(arraySize > MAX_CAPACITY){}
    // Copy given values into the array
    for ( int i = 0; i < itemCount; i++)
     items[i] = someArray[i];
    // Reorganize the array into a heap
     heapCreate();
}
