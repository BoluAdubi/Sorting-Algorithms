/* -----------------------------------------------------------------------------
 *
 * File Name:  executive.cpp
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 8
 * Description:  Sorts Lab
 * Date: 11/08/2020
 *
 ---------------------------------------------------------------------------- */

#include "executive.h"

executive::executive(std::string sort, int lBound, int uBound, int increment, std::string fileName, bool assert)
{
	m_sort = sort;
	m_lBound = lBound;
	m_uBound = uBound;
	m_increment = increment;
	m_fileName = fileName;
	m_assert = assert;
}

void executive::run()
{
	int count = m_lBound;
	
	std::ofstream outFile;
	outFile.open(m_fileName);
	
	srand(time(0));
	outFile << m_sort << "\n";
	
	while(count <= m_uBound)
	{
		// create and populate array with random values
		int* arr = new int[count];
		for(int i = 0; i < count; i++)
		{
			arr[i] = rand() % 100 + 1;
		}
		
		if(m_sort == "bubble")
		{
			double time = 0;
			sortTimer<int> myTimer;
			time = myTimer.timeSort(sorts<int>::bubbleSort, arr, count);
			
			outFile << count << ", " << time << "\n";
			
			count = count + m_increment;
		}
		else if(m_sort == "selection")
		{
			double time = 0;
			sortTimer<int> myTimer;
			time = myTimer.timeSort(sorts<int>::selectionSort, arr, count);
			
			outFile << count << ", " << time << "\n";
			
			count = count + m_increment;
		}
		else if(m_sort == "insertion")
		{
			double time = 0;
			sortTimer<int> myTimer;
			time = myTimer.timeSort(sorts<int>::insertionSort, arr, count);
			
			outFile << count << ", " << time << "\n";
			
			count = count + m_increment;
		}
		else if(m_sort == "merge")
		{
			double time = 0;
			sortTimer<int> myTimer;
			time = myTimer.timeSort(sorts<int>::mergeSort, arr, count);
			
			outFile << count << ", " << time << "\n";
			
			count = count + m_increment;
		}
		else if(m_sort == "quick")
		{
			double time = 0;
			sortTimer<int> myTimer;
			time = myTimer.timeSort(sorts<int>::quickSort, arr, count);
			
			outFile << count << ", " << time << "\n";
			
			count = count + m_increment;
		}
		else if(m_sort == "quickwithmedian")
		{
			double time = 0;
			sortTimer<int> myTimer;
			time = myTimer.timeSort(sorts<int>::quickSortWithMedian, arr, count);
			
			outFile << count << ", " << time << "\n";
			
			count = count + m_increment;
		}
		else
		{
			std::cout << "Invalid sort name provided!" << "\n";
		}
	}
	outFile.close();
}