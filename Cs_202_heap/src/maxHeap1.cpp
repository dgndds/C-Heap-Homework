#include "maxHeap1.h"
#include <cmath>
#include <fstream>
#include <iostream>

//using namespace std;

maxHeap1::maxHeap1(){
        // Allocate the array
        items = new int[MAX_CAPACITY];
        maxItems = 0;
        itemCount = 0;

        data = new const int*[itemCount];

        for ( int i = 0; i < itemCount; i++)
            items[i] = 0;

        for ( int i = 0; i < itemCount; i++)
            data[i] = new int[4];

        heapCreate();

        heapEmpty = true;
}

int maxHeap1::getLeftChildIndex( const int nodeIndex) const {
    return (2 * nodeIndex) + 1;
}

int maxHeap1::getRightChildIndex( const int nodeIndex) const {
    return (2 * nodeIndex) + 2;
}

int maxHeap1::getParentIndex( int nodeIndex) const{
    return (nodeIndex - 1) / 2;
}

bool maxHeap1::isLeaf( int nodeIndex) const{
    if(nodeIndex < MAX_CAPACITY && nodeIndex >= 0 && (nodeIndex >= (floor(double(itemCount/2))))){
        return true;
    }

    return false;
}

bool maxHeap1::isEmpty() const{
    return itemCount == 0;
}

int maxHeap1::getNumberOfNodes() const{
    return itemCount;
}

int maxHeap1::getHeight() const{
    return ceil(log2(itemCount + 1)) - 1;
}

//void maxHeap1::heapRebuild(int subTreeRootIndex){
//    int child = getLeftChildIndex(subTreeRootIndex);	// index of root's left child, if any
//	if ( child < itemCount) {
//		// root is not a leaf so that it has a left child
//		int rightChild = getRightChildIndex(subTreeRootIndex); 	// index of a right child, if any
//		// If root has right child, find larger child
//		if ( (rightChild < itemCount) && (items[rightChild] > items[child]) )
//			child = rightChild; 	// index of larger child
//
//		// If root’s item is smaller than larger child, swap values
//		if ( items[subTreeRootIndex] < items[child]) {
//			int temp = items[subTreeRootIndex];
//			items[subTreeRootIndex] = items[child];
//			items[child] = temp;
//
//			// transform the new subtree into a heap
//			heapRebuild(child);
//        }
//
//    }
//}
void maxHeap1::heapRebuild(int subTreeRootIndex){
    int child = getLeftChildIndex(subTreeRootIndex);	// index of root's left child, if any
	if ( child < itemCount) {
		// root is not a leaf so that it has a left child
		int rightChild = getRightChildIndex(subTreeRootIndex); 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < itemCount) && (data[rightChild][1] > data[child][1]) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( data[subTreeRootIndex][1] < data[child][1]) {
			const int* temp = data[subTreeRootIndex];
			data[subTreeRootIndex] = data[child];
			data[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
        }

    }
}

void maxHeap1::heapCreate(){
    for ( int index = itemCount / 2; index >= 0; index--)
        heapRebuild(index);
}

//maxHeap1::maxHeap1( const int someArray[], const int arraySize){
//    if(arraySize >= MAX_CAPACITY || (arraySize*2) >= MAX_CAPACITY){
//        // Allocate the array
//        items = new int[MAX_CAPACITY];
//        maxItems = MAX_CAPACITY;
//        itemCount = MAX_CAPACITY;
//    }else{
//        // Allocate the array
//        items = new int[2 * arraySize];
//        maxItems = 2 * arraySize;
//        itemCount = arraySize;
//    }
//
//     //if(arraySize > MAX_CAPACITY){}
//    // Copy given values into the array
//    for ( int i = 0; i < itemCount; i++)
//     items[i] = someArray[i];
//    // Reorganize the array into a heap
//     heapCreate();
//
//     heapEmpty = false;
//}

maxHeap1::maxHeap1( const int** someArray, const int arraySize){
    data = someArray;

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
     items[i] = someArray[i][1];
    // Reorganize the array into a heap
     heapCreate();


     heapEmpty = false;
}

//bool maxHeap1::add( const int& newData){
//    if (itemCount >= MAX_CAPACITY){
//        cout << "Cannot add " << newData << " to heap because heap is full" << endl;
//        return false;
//    }
//
//	// Place the new item at the end of the heap
//	items[itemCount] = newData;
//
//	// Trickle new item up to its proper position
//	int place = itemCount;
//	int parent = (place - 1)/2;
//	while ( (place > 0) && (items[place] > items[parent]) ) {
//		int temp = items[parent];
//		items[parent] = items[place];
//		items[place] = temp;
//
//		place = parent;
//		parent = (place - 1)/2;
//	}
//
// 	itemCount++;
//
//    cout << "Data " << newData << " added to heap successfully." << endl;
//    heapEmpty = false;
// 	return true;
//}
bool maxHeap1::add( const int* newData){
    if (itemCount >= MAX_CAPACITY){
       // cout << "Cannot add " << newData[0] << " to heap because heap is full" << endl;
        return false;
    }

	// Place the new item at the end of the heap
	data[itemCount] = newData;

	// Trickle new item up to its proper position
	int place = itemCount;
	int parent = (place - 1)/2;
	while ( (place > 0) && (data[place][1] > data[parent][1]) ) {
		const int* temp = data[parent];
		data[parent] = data[place];
		data[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}

 	itemCount++;

    //cout << "Data " << newData[0] << " added to heap successfully." << endl;
    heapEmpty = false;
 	return true;
}

void maxHeap1::print(){
    for(int i = 0; i < itemCount; i++)
        cout << "Data " << i << ": " << data[i][0] << endl;
}

//bool maxHeap1::remove(){
//    if (isEmpty()){
//        cout << "Could not remove root because heap is empty" << endl;
//        return false;
//    }
//	else {
//		//int rootItem = items[0];
//		items[0] = items[--itemCount];
//		heapRebuild(0);
//		cout << "Remove successful" << endl;
//        return true;
//	}
//}
bool maxHeap1::remove(int& removedItem){
    if (isEmpty()){
        cout << "Could not remove root because heap is empty" << endl;
        return false;
    }
	else {
		removedItem = data[0][0];
		data[0] = data[--itemCount];
		heapRebuild(0);
		//cout << "Remove successful" << endl;
        return true;
	}
}

