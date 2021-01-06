/* -----------------------------------------------------------------------------
 *
 * File Name:  sortTimer.h
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 8
 * Description:  Sorts Lab
 * Date: 11/08/2020
 *
 ---------------------------------------------------------------------------- */

#ifndef SORTTIMER_H
#define SORTTIMER_H

#include <time.h>

template <typename T>
class sortTimer
{
	public:
		/** 
       * @pre None
       * @post returns time taken to perform function
       * @param sort, the function being passed in
	   * @param arr[], the array being sorted
	   * @param size, the size of the array
       * @throw None
       **/
		double timeSort(void sort(T arr[], int size), T arr[], int size);
};

#include "sortTimer.cpp"
#endif