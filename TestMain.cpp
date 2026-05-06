#include "LibrariesAndFunctionHeadsQsort.h"

//Function to obtain an array of 'size' size of random ints
vector<int> getInts(int size, unsigned seed)
{
	mt19937 rng(seed);
	uniform_int_distribution<int> dist(-1000000, 1000000);

	vector<int> ints(size);
	for (int i = 0; i < size; i++)
	{
		ints[i] = dist(rng);
	}

	return ints;
}

//Function to obtain an array of 'size' size of random floats
vector<float> getFloats(int size, unsigned seed)
{
	mt19937 rng(seed);
	uniform_real_distribution<float> dist(-1000000.0f, 1000000.0f);

	vector<float> floats(size);
	for (int i = 0; i < size; i++)
	{
		floats[i] = dist(rng);
	}

	return floats;
}

//Function to obtain an array of 'size' size of random chars
vector<char> getChars(int size, unsigned seed)
{
	mt19937 rng(seed);
	uniform_int_distribution<int> dist('a', 'z');

	vector<char> chars(size);
	for (int i = 0; i < size; i++)
	{
		chars[i] = static_cast<char>(dist(rng));
	}

	return chars;
}

//Function to make a string of random characters to return to the getStrings function
string makeString(int size, unsigned seed)
{
	mt19937 rng(seed);
	uniform_int_distribution<int> dist('a', 'z');

	string returnString;

	for (int i = 0; i < size; i++)
	{
		returnString.push_back(static_cast<char>(dist(rng)));
	}

	return returnString;
}

//Function to obtain a vector of random strings
vector<string> getStrings(int size, unsigned seed)
{
	mt19937 rng(seed);

	vector<string> strings(size);
	for (int i = 0; i < size; i++)
	{
		strings[i] = makeString(12, seed+i);
	}

	return strings;
}

//Main function for test program
int main(int argc, char* argv[])
{
	//For loop for 3 different sizes
	for (int size = 100; size <= 1000000; size *= 10)
	{
		//Creation of various testing type vectors
		vector<int> intVector = getInts(size, 1);
		vector<float> floatVector = getFloats(size, 1);
		vector <char> charVector = getChars(size, 1);
		vector<string> stringVector = getStrings(size, 1);
		float intTime = 0;
		float floatTime = 0;
		float charTime = 0;
		float stringTime = 0;

		//Print out current testing size
		cout << "Testing Data Size: " << size << endl;

		//For loop iterating over 10 different trials to get an average runtime
		for (int i = 0; i < 10; i++)
		{
			//Either change this function name, or change the name of your sorting function
			auto start = steady_clock::now();
			quickSort(intVector, 0, size - 1);
			auto end = steady_clock::now();
			auto elapse = duration_cast<milliseconds>(end - start);
			intTime += duration<float, milli>(end - start).count();
		}


		for (int i = 0; i < 10; i++)
		{
			//Either change this function name, or change the name of your sorting function
			auto start = steady_clock::now();
			quickSort(intVector, 0, size - 1);
			auto end = steady_clock::now();
			auto elapse = duration_cast<milliseconds>(end - start);
			floatTime += duration<float, milli>(end - start).count();
		}

		for (int i = 0; i < 10; i++)
		{
			//Either change this function name, or change the name of your sorting function
			auto start = steady_clock::now();
			quickSort(intVector, 0, size - 1);
			auto end = steady_clock::now();
			auto elapse = duration_cast<milliseconds>(end - start);
			charTime += duration<float, milli>(end - start).count();
		}

		for (int i = 0; i < 10; i++)
		{
			//Either change this function name, or change the name of your sorting function
			auto start = steady_clock::now();
			quickSort(intVector, 0, size - 1);
			auto end = steady_clock::now();
			auto elapse = duration_cast<milliseconds>(end - start);
			stringTime += duration<float, milli>(end - start).count();
		}

		//Dividing by 10 to obtain averages
		stringTime /= 10;
		charTime /= 10;
		floatTime /= 10;
		intTime /= 10;

		//Printout of runtimes
		cout << "Average Times:" << endl;
		cout << "Int: " << intTime << "ms" << endl;
		cout << "Float: " << floatTime << "ms" << endl;
		cout << "Char: " << charTime << "ms" << endl;
		cout << "String: " << stringTime << "ms" << endl;
	}
}