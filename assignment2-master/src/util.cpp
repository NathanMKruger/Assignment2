//	Nathan Kruger
//	Filled in for empty code
//
//  util.cpp
//
//  Implementation of Timing Tests
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include "util.h"
#include "search.h"
#include <random>
#include <iostream>

using namespace std;
using namespace std::chrono;

namespace csi281 {
    
    // Returns a new int array of *length* and filled
    // with numbers between *min* and *max*
    // Suggest using the facilities in STL <random>
	int* randomIntArray(const int length, const int min, const int max) {
		// YOUR CODE HERE
		int* randArray = new int[length];

		for (int i = 0; i < length + 1; i++)
		{
			default_random_engine randomGen;
			uniform_int_distribution<int> range(min, max);
			int randomNum = range(randomGen);
			randArray[length] = randomNum;
		}

		return randArray[];

		delete[] randArray;
	}
    // Finds the speed of linear versus binary search
    // in a random int array of *length* size
    // by running *numTests* and averaging them
    // Returns a pair indicating the average time it took
    // to do linear search and binary search in nanoseconds
    // Linear search should be first in the pair, and binary search
    // should be second
    // Suggest using the facilities in STL <chrono>
    pair<nanoseconds, nanoseconds> arraySearchSpeed(const int length, const int numTests) {
        // YOUR CODE HERE
		int searchArray[] = randomIntArray(length, 1, 1000);
		int keyNum = 286;
		double linearTotal = 0;
		double binaryTotal = 0;

		for (int i = 0; i < numTests + 1; i++)
		{
			auto start = duration_cast <nanoseconds> (system_clock::now().time_since_epoch()).count();
			for (int j = 0; j < length + 1; j++)
			{
				if (searchArray[j] == keyNum)
				{
					break;
				}
			}
			auto end = duration_cast <nanoseconds> (system_clock::now().time_since_epoch()).count();
			linearTotal += end;
		}
		double linearAvg = linearTotal / numTests;

		for (int k = 0; k < numTests + 1; k++)
		{
			auto start = duration_cast <nanoseconds> (system_clock::now().time_since_epoch()).count();
			sort(begin(searchArray), end(searchArray);
			int startSearch = 0;
			int endSearch = length - 1;
			while (startSearch <= endSearch)
			{
				int midSplit = startSearch + (endSearch - startSearch) / 2;
				if (keyNum < searchArray[midSplit])
				{
					endSearch = midSplit - 1;
				}
				else if (keyNum > searchArray[midSplit])
				{
					startSearch = midSplit + 1
				}
				else
				{
					break;
				}
			}
			auto end = duration_cast <nanoseconds> (system_clock::now().time_since_epoch()).count();
			binaryTotal += end;
		}
		double binaryAvg = binaryTotal / numTests;

		return make_pair(linearAvg, binaryAvg); //looked up how to return a pair:www.geeksforgeeks.org/returning-multiple-values-from-a-function-using-tuple-and-pair-in-c/
    }
}
