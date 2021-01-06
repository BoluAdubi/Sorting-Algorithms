/* -----------------------------------------------------------------------------
 *
 * File Name:  sortTimer.cpp
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 8
 * Description:  Sorts Lab
 * Date: 11/08/2020
 *
 ---------------------------------------------------------------------------- */

template <typename T>
double sortTimer<T>::timeSort(void sort(T arr[], int size), T arr[], int size)
{
	clock_t t;
	
	t = clock(); // start timer
	
	sort(arr, size);
	
	t = clock() - t; // stop timer
	
	return((float)t / CLOCKS_PER_SEC);
}