///////////////////////////////////////////////////////////////////////////////
//
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            H02
// Title:            Homework 02 - HeapifyDebacle
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Completing Functions for a heap class
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

/**
 * Class Heap
 * 
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : bubble up the heap to put values in proper order 
 *                        by comparing the parents and children
 *          Left        : return index of the left child
 *          OnHeap      : verifies if an index is in the array
 *          Parent      : get the parent of indexes
 *          Right       : return the index of right child
 *          Swap        : swap values on the heap
 *          /// Fix These:
 *          SinkDown    : bubble down the heap values to place in proper order
 *          PickChild   : checks whether there is a child and returns smaller child
 *      public:
 *          Insert      : inserts values in heap 
 *          Print       : prints values on heap
 *          Remove      : removes value at the root of the heap
 */
class Heap {
private:
    int size; // size of the array
    int *H;   // array pointer
    int end;  // 1 past last item in array


    /**
   * BubbleUp
   * 
   * @description: 
   *    This puts one value into its proper
   *    place in the heap.
   * 
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
    void BubbleUp(int index) {
        // check parent is not of beginning of array
        if (Parent(index) >= 1) {
            // index is on array and value is less than parent
            while (index > 1 && H[index] < H[Parent(index)]) {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
    }

    /**
     * Left
     * @description:
     *      Calculates index of left child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of left child
     */
    int Left(int index) {
        return 2 * index;
    }

    /**
     * OnHeap
     * @description:
     *      Checks if an index is on the array (past the end).
     * 
     * @param  {int} index : index to check
     * @return {bool}      : 0 = off heap / 1 = on heap
     */
    bool OnHeap(int index) {
        return index < end;
    }

    /**
     * Parent
     * @description:
     *      Calculates parent of a given index.
     * 
     * @param  {int} index : index to check
     * @return {int}       : parent index
     */
    int Parent(int index) {
        return index / 2;
    }

    /**
     * Right
     * @description:
     *      Calculates index of right child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of right child
     */
    int Right(int index) {
        return 2 * index + 1;
    }

    /**
     * Swap
     * 
     * @description: 
     *      Swaps to values in the heap
     * 
     * @param  {int} i  : index in array
     * @param  {int} j  : index in array
     * @return          : void
     */
    void Swap(int i, int j) {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
    }

    ////////////////////////////
    //Fix These Methods
    ////////////////////////////

   
    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it proper location.
     * 
     * @param  {int} index  : index to start from in the array
     * @return              : void 
     */
    void SinkDown(int index) {
         
        while(PickChild(index) >= 1) {
            if(index > 1 && H[index] > H[PickChild(index)]){
                Swap(index, PickChild(index));
                index  = PickChild(index);
            }
        }
    }

    /**
     * PickChild
     * @description:
     *      If one child exists, return it.
     *      Otherwise, return the smaller of the two.
     * 
     * @param  {int} index  : index of parent in the array
     * @return              : index to child 
     */
    int PickChild(int index) {
        
        if (H[Left(index)] < H[Right(index)]) {
            return Left(index);
        } 
        else if (H[Right(index)] < H[Left(index)]) {
             return Right(index);
        }
        else {

            if (Right(index) >=end && Left(index) >= end) {    
                return end-1; 
            } 
            else { // There is a left child
                return Left(index);
            }
        } 
        
    }

public:
    /**
   * Heap constructor
   */
    Heap() {
        size = 100;
        H = new int[size];
        end = 1;
    }

    /**
   * Heap constructor
   * 
   * @param  {int} s : heap size 
   */
    Heap(int s) {
        size = s;
        H = new int[s];
        end = 1;
    }


    /**
     * 
     * @param  {int*} A   :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     */
    void Heapify(int *A, int size) {
        // do it!
           int i = size;

        for(int j = i; j>=1; j--){
            Insert(j);
        }
    }




    /**
   * Insert
   * 
   * @description:
   *        Add a value to the heap.
   * 
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void Insert(int x) {
        H[end] = x;
        BubbleUp(end);
        end++;
    }

    /**
     * For test our heap !!!  
     */
    void Print() {
        for (int i = 1; i <= end - 1; i++) {
               cout << H[i];
            if (i < end - 1) {
                cout << "->";
            }
        }
    }

    /**
     * Remove
     * @description:
     *      Removes item from top of heap
     * 
     * @return {int}  : top of heap
     */
    int Remove() {
        int temp = H[1];
        H[1] = H[end];
        --end;

        return temp;
    }
};

int main() {
    Heap H;
    //dynamically allocate space for an array

    int size = 10;
    int *A = new int[size];

    for(int i = size; i > size; i++){
        A[i] = i;
    }
    H.Heapify(A, size);



    // H.Insert(17);
    // H.Insert(11);

    // for (int i = 1; i <= 10; i++) {
    //     H.Insert(i);
    // }

    H.Print();
}