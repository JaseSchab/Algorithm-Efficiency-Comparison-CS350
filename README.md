# An-In-Depth-Comparison-of-Efficiency-of-Various-Sorting-Algorithms
**Introduction:**

Currently, there are many proven methods of sorting a group of items programmatically. However, calculating their efficiency has mostly been reserved to theoretical runtime or space. We believe there must be more metrics and methods available that can be used  to measure the efficiency of a sorting algorithm in a more specific manner. With the new information, more insights can be made into the algorithms themselves and more informed and practical decisions can be made for which algorithm is best for which circumstances.

**Method:**

We implemented and tested four sorting algorithms:
Quick Sort,
Merge Sort,
Bubble Sort,
and Bogo Sort. 
With these algorithms we ran them through multiple test using these data types
Integers,
Floats,
Characters,
and Strings.

**Solution:**
By combining runtime measurements with memory analysis, we provide a more complete comparison of algorithm efficiency. This allows us to determine not only which algorithms are faster, but also which takes the least amount of memory under practical conditions.

## Project Overview
Our Teams Project test and rank sorting algorithms by having each one code our algorithm and run it through a test of increasing size to record both time and memory usage to determine which algorithm is best.
Our test consisted of us scaling them for the diffrent data types in this order 100, 1000, 10000, and 1000000. With the use of valgrind we were able to not only record the time each test took but the amount of memory used to run said test.
## Team Contributions

- **Jase**
  - Implemented Merge Sort & Collected its Data for Time and Memory
  - Assisted with discussion and analysis

- **Ray**
  -  Programmed and tested bubble sort
  -  Wrote System Design/Methodology

- **Chloe**
  - Implemented Bogo Sort & Collected its Data for Time and Memory
  - Wrote Background and conclusion portion of paper

- **Doc**
  -  Created test files and quicksort code, and tested algorithm
  -  Wrote Abstract, Introduction, Findings/Test info, editing of overall info

## Testing

### Test Setup
- Data was randomly generated for each run to ensure consistent input conditions  
- Input sizes ranged from:
  - 100 → 1,000,000 for merge sort, quicksort, and bubble sort  
  - 3 → 7 for bogosort due to runtime limitations  
- Each test was executed **10 times**
- Results were averaged to reduce variability  
- Runtime was measured using the C++ `std::chrono` library  
- Memory usage was measured using **Valgrind’s Massif tool**

---

### Test Results

- **Quick Sort**
  - Fastest overall across most data types and sizes  
  - Low memory usage due to in-place sorting  

- **Merge Sort**
  - Consistent and efficient runtime  
  - Higher memory usage due to temporary array allocations  

- **Bubble Sort**
  - Significantly slower at larger input sizes (O(n²))  
  - Minimal additional memory usage  

- **Bogo Sort**
  - Only feasible for very small datasets  
  - Runtime increases factorially and becomes impractical quickly  
  - Memory usage appears constant due to small input sizes  

---

### Key Observations
- Runtime increases with input size as expected from theoretical complexity  
- String data consistently took longer to sort due to higher comparison cost  
- Merge sort shows clear memory overhead compared to quicksort  
- Bogosort highlights extreme inefficiency and serves as a baseline comparison

## Summary of Included Files

### File Overview

- **TestMainMemJase.cpp**
  - Run this for Merge Sort Testing

- **quicksort.h**
  - Run this for Quick Sort Testing

- **BubbleMem.cpp**
  - Run this for Bubble Sort Testing

- **bogosort.cpp**
  - Run this for Bogo Sort Testing
 
- **TestMainMem.cpp**
  - This was the template we all used to add our code to so it can run the test
---

## Pipeline and Execution

### Runtime Testing Pipeline
1. Generate random dataset for selected data type  
2. Run sorting algorithm on dataset  
3. Measure execution time using `std::chrono`  
4. Repeat test 10 times  
5. Calculate average, minimum, and maximum runtime  
6. Output results for comparison  

---

### Memory Testing Pipeline
1. Generate random dataset for selected data type  
2. Execute program using Valgrind Massif  
3. Record peak heap memory (`mem_heap_B`)  
4. Repeat test 10 times  
5. Extract peak values and compute average  
6. Store results for analysis  
