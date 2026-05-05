#include "LibrariesAndFunctionHeads.h"

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

vector<string> getStrings(int size, unsigned seed)
{
	vector<string> strings(size);
	for (int i = 0; i < size; i++)
	{
		strings[i] = makeString(12, seed + i);
	}

	return strings;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Usage: ./mergeMem <int|float|char|string> <size>" << endl;
		return 1;
	}

	string type = argv[1];
	int size = stoi(argv[2]);

	if (type == "int")
	{
		vector<int> intVector = getInts(size, 1);
		quickSort(intVector, 0, size - 1);
	}
	else if (type == "float")
	{
		vector<float> floatVector = getFloats(size, 1);
		quickSort(floatVector, 0, size - 1);
	}
	else if (type == "char")
	{
		vector<char> charVector = getChars(size, 1);
		quickSort(charVector, 0, size - 1);
	}
	else if (type == "string")
	{
		vector<string> stringVector = getStrings(size, 1);
		quickSort(stringVector, 0, size - 1);
	}
	else
	{
		cout << "Invalid type. Use int, float, char, or string." << endl;
		return 1;
	}

	return 0;
}