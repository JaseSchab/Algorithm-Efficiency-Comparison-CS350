#include "LibrariesAndFunctionHeads.h"
#include <sys/resource.h>
#include <fstream>

// Returns current peak RSS (resident set size) in kilobytes.
// On Linux, ru_maxrss is in KB. On macOS it is in bytes, so we divide by 1024.
long getMemoryKB()
{
	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
#ifdef __APPLE__
	return usage.ru_maxrss / 1024;
#else
	return usage.ru_maxrss;
#endif
}

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
	mt19937 rng(seed);

	vector<string> strings(size);
	for (int i = 0; i < size; i++)
	{
		strings[i] = makeString(12, seed + i);
	}

	return strings;
}

int main(int argc, char* argv[])
{
	// Usage: ./BubbleMem <type> <size_exponent>
	// type: int | float | char | string
	// size_exponent: 2=100, 3=1000, 4=10000, 5=100000, 6=1000000
	//
	// Example: ./BubbleMem int 4   -> sorts 10,000 ints

	if (argc != 3)
	{
		cerr << "Usage: " << argv[0] << " <type> <size_exponent>\n";
		cerr << "  type: int | float | char | string\n";
		cerr << "  size_exponent: 2=100  3=1000  4=10000  5=100000  6=1000000\n";
		return 1;
	}

	string type     = argv[1];
	int    exponent = stoi(argv[2]);

	// Convert exponent to actual size: 10^exponent
	int size = 1;
	for (int i = 0; i < exponent; i++) size *= 10;

	// Append all results to results.txt
	ofstream out("results.txt", ios::app);
	if (!out)
	{
		cerr << "Failed to open results.txt\n";
		return 1;
	}

	out << "  Size " << size << ":\n";

	if (type == "int")
	{
		vector<int> data = getInts(size, 1);

		long memBefore = getMemoryKB();
		auto start = high_resolution_clock::now();
		bubbleSort(data, 0, size - 1);
		auto end = high_resolution_clock::now();
		long memAfter = getMemoryKB();

		out << "    Sort time:   " << duration_cast<milliseconds>(end - start).count() << " ms\n";
		out << "    Memory used: " << (memAfter - memBefore) << " KB"
		    << "  (peak RSS: " << memAfter << " KB)\n";
	}
	else if (type == "float")
	{
		vector<float> data = getFloats(size, 1);

		long memBefore = getMemoryKB();
		auto start = high_resolution_clock::now();
		bubbleSort(data, 0, size - 1);
		auto end = high_resolution_clock::now();
		long memAfter = getMemoryKB();

		out << "    Sort time:   " << duration_cast<milliseconds>(end - start).count() << " ms\n";
		out << "    Memory used: " << (memAfter - memBefore) << " KB"
		    << "  (peak RSS: " << memAfter << " KB)\n";
	}
	else if (type == "char")
	{
		vector<char> data = getChars(size, 1);

		long memBefore = getMemoryKB();
		auto start = high_resolution_clock::now();
		bubbleSort(data, 0, size - 1);
		auto end = high_resolution_clock::now();
		long memAfter = getMemoryKB();

		out << "    Sort time:   " << duration_cast<milliseconds>(end - start).count() << " ms\n";
		out << "    Memory used: " << (memAfter - memBefore) << " KB"
		    << "  (peak RSS: " << memAfter << " KB)\n";
	}
	else if (type == "string")
	{
		vector<string> data = getStrings(size, 1);

		long memBefore = getMemoryKB();
		auto start = high_resolution_clock::now();
		bubbleSort(data, 0, size - 1);
		auto end = high_resolution_clock::now();
		long memAfter = getMemoryKB();

		out << "    Sort time:   " << duration_cast<milliseconds>(end - start).count() << " ms\n";
		out << "    Memory used: " << (memAfter - memBefore) << " KB"
		    << "  (peak RSS: " << memAfter << " KB)\n";
	}
	else
	{
		cerr << "Unknown type: " << type << "\n";
		cerr << "  Valid types: int | float | char | string\n";
		return 1;
	}

	return 0;
}
