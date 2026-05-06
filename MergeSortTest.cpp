#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <string>

using namespace std;
using namespace chrono;

// Merge helper function
template <typename T>
void merge(vector<T>& arr, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<T> leftHalf(leftSize);
    vector<T> rightHalf(rightSize);

    for (int i = 0; i < leftSize; i++)
    {
        leftHalf[i] = arr[left + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightHalf[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftHalf[i] <= rightHalf[j])
        {
            arr[k] = leftHalf[i];
            i++;
        }
        else
        {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        arr[k] = leftHalf[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(vector<T>& arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

template <typename T>
void quickSort(vector<T>& arr, int left, int right)
{
    mergeSort(arr, left, right);
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
    vector<string> strings(size);

    for (int i = 0; i < size; i++)
    {
        strings[i] = makeString(12, seed + i);
    }

    return strings;
}

int main()
{
    for (int size = 100; size <= 100000; size *= 10)
    {
        vector<int> intVector = getInts(size, 1);
        vector<float> floatVector = getFloats(size, 1);
        vector<char> charVector = getChars(size, 1);
        vector<string> stringVector = getStrings(size, 1);

        cout << "Testing Data Size: " << size << endl;

        cout << "Integer time" << endl;
        auto start = steady_clock::now();
        quickSort(intVector, 0, size - 1);
        auto end = steady_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Time: " << duration.count() << " ms." << endl;

        cout << "Float time" << endl;
        start = steady_clock::now();
        quickSort(floatVector, 0, size - 1);
        end = steady_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        cout << "Time: " << duration.count() << " ms." << endl;

        cout << "Char time" << endl;
        start = steady_clock::now();
        quickSort(charVector, 0, size - 1);
        end = steady_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        cout << "Time: " << duration.count() << " ms." << endl;

        cout << "String time" << endl;
        start = steady_clock::now();
        quickSort(stringVector, 0, size - 1);
        end = steady_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        cout << "Time: " << duration.count() << " ms." << endl;

        cout << endl;
    }

    return 0;
}
