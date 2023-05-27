* [Testing](#Testing)
	* [Time to access data in different arrays](#Time-to-access-data-in-different-arrays)
	* [Time to assign zero to a variable](#Time-to-assign-zero-to-a-variable)
	* [Time to calculate the power of 2](#Time-to-calculate-the-power-of-2)
	* [Functions to get execution time](#Functions-to-get-execution-time)

# Testing

During the development of this program were made performance/time tests with the C programming language denoted below:

### [Time to access data in different arrays](/tests/timetest.c)
There were eight cases of accesses which the program analyzed:
* Declaration of array:
	* Static (S)
	* Dynamic (D)
* Type of access:
	* Read (R)
	* Write (W)
* Method of access:
	* Integer index (I)
	* Pointer (P)

**Results**: Dynamic with pointer costs less time.

### [Time to assign zero to a variable](/tests/setzerotest.c)
Setting zero to a variable using assignment operator and XOR logical operator.

**Results**: XOR costs less time (update: using O1 or O2 XOR is better, using O3 or Ofast the performance is the same).

### [Time to calculate the power of 2](/tests/powerof2test.c)
Time to get a power of 2 using the math function pow, bitwise operation (shifting) and by multiplying.

**Results**: bitwise operation and by multiplying costs almost the same time, however shifting costs only one instruction instead of a while with 3 instructions (condition, multiplication and incrementing) per loop.

### [Functions to get execution time](/tests/timeexecutiontest.c)
Checking functions gettimeofday() and clock() to measure time execution.

**Results**: gettimeofday shows wrong output in some executions as well as this function is considered deprecated and the function clock() does the same as the other one with the same precision of microsseconds.

## [References](/tests/ref.txt)