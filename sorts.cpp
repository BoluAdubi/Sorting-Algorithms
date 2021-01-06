/* -----------------------------------------------------------------------------
 *
 * File Name:  sorts.cpp
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 8
 * Description:  Sorts Lab
 * Date: 11/08/2020
 *
 ---------------------------------------------------------------------------- */

template <typename T>
void sorts<T>::bubbleSort(T arr[], int size)
{
	int temp = 0;
	
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

template <typename T>
void sorts<T>::selectionSort(T arr[], int size)
{	
	int temp = 0;
	int minIndex = 0;
	
	for(int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		
		// find min value in unsorted array
		for(int j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}	
		
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}	
}

template <typename T>
void sorts<T>::insertionSort(T arr[], int size)
{	
	int prevIndex = 0;
	int current = 0; 
	
    for (int i = 0; i < size; i++) 
    {  
        current = arr[i];  
        prevIndex = i - 1;  
  
        
        while (prevIndex >= 0 && arr[prevIndex] > current) 
        {  
            arr[prevIndex + 1] = arr[prevIndex];  
            prevIndex = prevIndex - 1;  
        }  
        arr[prevIndex + 1] = current;  
    }  
}
	
template <typename T>
void sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{	
	int sumSize = size1 + size2;
	int count1 = 0;
	int count2 = 0;
	int index = 0;
	int bufferArr[sumSize];
	
	while(count1 < size1 && count2 < size2)
	{
		if(*a1 <= *a2)
		{
			bufferArr[index] = *a1;
			a1 = a1 + 1;
			index++;
			count1++;
		}
		else
		{
			bufferArr[index] = *a2;
			a2 = a2 + 1;
			index++;
			count2++;
		}
	}
	
	
	// copy remaining values into buffer
	while(count1 < size1)
	{
		bufferArr[index] = *a1;
		a1 = a1 + 1;
		index++;
		count1++;
	}
	
	while(count2 < size2)
	{
		bufferArr[index] = *a2;
		a2 = a2 + 1;
		index++;
		count2++;
	}
	
	// copy values from buffer back into original
	a1 = a1 - count1;
	
	for(int i = 0; i < sumSize; i++)
	{
		*a1 = bufferArr[i];
		a1 = a1 + 1;
	}
}	

template <typename T>
void sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{	
	if (first < last)
    {
        int pivotIndex = partition(arr, first, last, median);
		quickSortRec(arr, first, pivotIndex - 1, median);
		quickSortRec(arr, pivotIndex + 1, last, median);
    }
}	

template <typename T>
void sorts<T>::setMedianPivot(T arr[], int first, int last)
{	
	int middle = (first+last)/2;
    int median;
    if ((arr[first] <= arr[middle] && arr[last] >= arr[middle]) || (arr[first] >= arr[middle] && arr[last] <= arr[middle]))
    {
        median = middle;
    }
    else if ((arr[middle] <= arr[first] && arr[last] >= arr[first]) || (arr[middle] >= arr[first] && arr[last] <= arr[first]))
    {
        median = first;
    }
    else
    {
        median = last;
    }
    T temp = arr[median];
    arr[median] = arr[last];
    arr[last] = temp;
}

template <typename T>
int sorts<T>::partition(T arr[], int first, int last, bool median)
{	
	if(median)
	{
		setMedianPivot(arr, first, last);
	}
	
	T pivot = arr[last];
    int storeIndex = first;
	
    for (int i = first; i < last; i++)
    {
        if (arr[i] <= pivot)
        {
            T temp = arr[i];
            arr[i] = arr[storeIndex];
            arr[storeIndex] = temp;
            storeIndex ++;
        }
    }
    T temp = arr[last];
    arr[last] = arr[storeIndex];
    arr[storeIndex] = temp;
    return storeIndex;
}

template <typename T>
void sorts<T>::mergeSort(T arr[], int size)
{	
	if(size > 1)
	{
		// "break the array in half"
		int mid = size/2;
		int leftSize = mid;
		int rightSize = size - mid;
		T* leftArr = arr;
		T* rightArr = (arr + mid);
		
		mergeSort(leftArr, leftSize);
		mergeSort(rightArr, rightSize);
		
		merge(leftArr, rightArr, leftSize, rightSize);
	}
}

template <typename T>
void sorts<T>::quickSort(T arr[], int size)
{	
	quickSortRec(arr, 0, size - 1, false);
}

template <typename T>
void sorts<T>::quickSortWithMedian(T arr[], int size)
{	
	quickSortRec(arr, 0 , size - 1, true);
}

template <typename T>
bool sorts<T>::isSorted(T arr[], int size)
{	
	for(int i = 0; i < size-1; i++)
{
		if(arr[i] > arr[i+1]){
			return false;
		}
	}
	return true;
}
