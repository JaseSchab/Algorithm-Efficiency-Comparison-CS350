#include <iostream>
#include <vector>
#include <random>
#include "time.h"
#include <chrono>
#include <string>

using namespace std::chrono;

template <class t>
std::vector<t> bogosort(std::vector<t> array)
{
    //newarray stores the randomized array
    std::vector<t> newarray;
    newarray.resize(array.size());

    //run until sorted
    while(true)
    {
        //repopulate array with randomized values from original array

        //temporary value to use for loop
        int temp = array.size();

        //for all values in original array, pick one at random, erase it from array, then push it onto newarray
        for (int i = 0; i < temp; i++)
        {
            int randint = rand() % array.size();
            newarray[i] = array[randint];
            array.erase(array.begin() + randint);
        }

        //now need to check if its sorted

        //default to true
        bool sorted = true;

        //if a decrease is detected, array is not sorted and must loop
        for (int i = 0; i < (newarray.size() - 1); i++)
        {
            if (newarray[i] > newarray[i + 1])
            {
                sorted = false;
            }
        }

        //if newarray is sorted, break out and return
        if (sorted == true)
        {
            break;
        }

        //at this point, array is confirmed unsorted and we must reset things

        //repopulate array using preserve
        for (int i = 0; i < newarray.size(); i++)
        {
            array.push_back(newarray[i]);
        }
    }
    //return sorted array
    return newarray;
}

