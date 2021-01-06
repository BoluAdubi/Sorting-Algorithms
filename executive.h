/* -----------------------------------------------------------------------------
 *
 * File Name:  executive.h
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 8
 * Description:  Sorts Lab
 * Date: 11/08/2020
 *
 ---------------------------------------------------------------------------- */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <fstream>
#include <string>
#include "sorts.h"
#include "sortTimer.h"
#include "executive.h"

class executive
{
	private: 
		std::string m_sort;
		int m_lBound;
		int m_uBound;
		int m_increment;
		std::string m_fileName;
		bool m_assert;
	
	public:
		/** 
       * @pre None
       * @post Executive object is created
       * @param Input file name
       * @throw None
       **/
		executive(std::string sort, int lBound, int uBound, int increment, std::string fileName, bool assert);
		
		/** 
       * @pre None
       * @post runs the program
       * @param None
       * @throw None
       **/
		void run();
};

#endif