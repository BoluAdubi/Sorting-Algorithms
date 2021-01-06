/* -----------------------------------------------------------------------------
 *
 * File Name:  sorts.h
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 8
 * Description:  Sorts Lab
 * Date: 11/08/2020
 *
 ---------------------------------------------------------------------------- */

#ifndef SORTS_H
#define SORTS_H

template <typename T>
class sorts
{
        private:

                /**
       * @pre None
       * @post merges two sorted arrays into one
           * @param a1, pointer to the beginning of the array
           * @param a2, pointer to the middle of the array
           * @param size1, size of the first "half" of the array
           * @param size2, size of the second "half" of the array
       * @throw None
       **/
                static void merge(T* a1, T* a2, int size1, int size2);

                /**
       * @pre None
       * @post recursively sorts the array using quicksort
           * @param arr[], the array being sorted
           * @param first, the first index in the array
           * @param last, the last index in the array
           * @param median, the median of first, middle, and last
       * @throw None
       **/
                static void quickSortRec(T arr[], int first, int last, bool median);

                /**
       * @pre None
       * @post finds the median and sets it as the pivot
           * @param arr[], the array being sorted
           * @param first, the first index in the array
           * @param last, the last index in the array
       * @throw None
       **/
                static void setMedianPivot(T arr[], int first, int last);

                /**
       * @pre None
       * @post partitions array
           * @param arr[], the array being sorted
           * @param first, the first index in the array
           * @param last, the last index in the array
           * @param median, the median of first, middle, and last
       * @throw None
       **/
                static int partition(T arr[], int first, int last, bool median);

        public:

                /**
       * @pre None
       * @post sorts array using bubblesort
           * @param arr[], the array being sorted
           * @param size, the size of the array
       * @throw None
       **/
                static void bubbleSort(T arr[], int size);

                /**
       * @pre None
       * @post sorts array using selectionsort
           * @param arr[], the array being sorted
           * @param size, the size of the array
       * @throw None
       **/
                static void selectionSort(T arr[], int size);

                /**
       * @pre None
       * @post sorts array using insertionsort
           * @param arr[], the array being sorted
           * @param size, the size of the array
       * @throw None
       **/
                static void insertionSort(T arr[], int size);

                /**
       * @pre None
       * @post sorts array using mergesort
           * @param arr[], the array being sorted
           * @param size, the size of the array
       * @throw None
       **/
                static void mergeSort(T arr[], int size);

                /**
       * @pre None
       * @post sorts array using the last value as the pivot
           * @param arr[], the array being sorted
           * @param size, the size of the array
       * @throw None
       **/
                static void quickSort(T arr[], int size);

                /**
       * @pre None
       * @post sorts array using the median of the first, middle, and last value as the pivot
           * @param arr[], the array being sorted
           * @param size, the size of the array
       * @throw None
       **/
                static void quickSortWithMedian(T arr[], int size);

                /**
       * @pre None
       * @post returns true if array is sorted, false otherwise
           * @param arr[], the array being sorted
           * @param size, the size of the array
       * @throw None
       **/
                static bool isSorted(T arr[], int size);
};

#include "sorts.cpp"
#endif