/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 8
 * Description:  Sorts Lab
 * Date: 11/08/2020
 *
 ---------------------------------------------------------------------------- */
#include <string>
#include <iostream>
#include "executive.h"

int main(int argc, char* argv[])
{
	if(argc < 6)
	{
		std::cout << "Incorrect number of parameters!\n";
	}
	else
	{
		std::string sort = argv[1];
		int lBound = std::stoi(argv[2]);
		int uBound = std::stoi(argv[3]);
		int increment = std::stoi(argv[4]);
		std::string fileName = argv[5];
		bool assert = false;
		
		if(argc == 7)
		{
			//bool assert = true;
		}
		
		executive exec(sort, lBound, uBound, increment, fileName, assert);
		exec.run();
	}
	
	return(0);
}