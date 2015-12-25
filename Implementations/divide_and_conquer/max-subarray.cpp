/**
 * Given an array of integers, which is the subarray whose elements
 * produce the greatest sum?
 *
 *
 * Author: Vitor Greati
 * Date: 12/25/2015
 * Inspired in: CLRS's Book
 * */

#include <iostream>
#include <limits.h>
#include <chrono>
#include "TestHelper.h"

using namespace std;
using namespace std::chrono;

struct subarray {
	int begin, end, sum;
	subarray (int b, int e, int s) : begin {b}, end {e}, sum {s} {};
};

/* This solves the problem in quadract time Theta(n^2).
 * */

subarray find_maximum_subarray_quad (int * A, int low, int high) {
	int max_sum = INT_MIN;
	int i_max = -1;
	int j_max = -1;
	for (int i = low; i <= high; ++i) {
		int temp_sum = 0;
		for (int j = i; j <= high; ++j) {
			temp_sum += A[j];
			if (temp_sum >= max_sum) {
				max_sum = temp_sum;
				i_max = i;
				j_max = j;
			}
		}
	}
	return {i_max, j_max, max_sum};
}

/* This solves the problem of maximum-subarray, through divide-and-conquer
 * approach, in Theta(n*log(n)).
 *
 * */

subarray find_max_crossing_subarray (int * A, int low, int mid, int high) {
	int temp_sum = 0;
	int max_left = INT_MIN;
	int i_max_left = -1;
	for (int i = mid; i >= low; --i) {
		temp_sum += A[i];
		if (temp_sum >= max_left) {
			max_left = temp_sum;
			i_max_left = i;
		}	
	}
	
	temp_sum = 0;
	int max_right = INT_MIN;
	int j_max_right = -1;
	for (int j = mid + 1; j <= high; ++j) {
		temp_sum += A[j];
		if (temp_sum >= max_right) {
			max_right = temp_sum;
			j_max_right = j;
		}	
	}

	return {i_max_left, j_max_right, max_left + max_right};
}

subarray find_maximum_subarray_dq(int * A, int low, int high) {
	if (high == low)
		return {low, high, A[low]};
	else {
		int mid = low + (high - low) / 2;
		subarray maxleft = find_maximum_subarray_dq(A, low, mid);
		subarray maxright = find_maximum_subarray_dq(A, mid + 1, high);
		subarray maxcross = find_max_crossing_subarray(A, low, mid, high);
		if (maxleft.sum > maxright.sum && maxleft.sum > maxcross.sum)
			return maxleft;
		if (maxright.sum > maxleft.sum && maxright.sum > maxcross.sum)
			return maxright;
		else return maxcross;
	}
}

/* And this solves the problem in linear time! Theta(n)!
 * It's Kadane's algorithm!
 * */
subarray find_maximum_subarray_kadane(int * A, int l, int h) {
	int max_until_here = 0;
	int max_total = 0;
	int i_max = 0, j_max = 0;
	for (int i = l; i <= h; ++i) {
		max_until_here += A[i];
		if (max_until_here < 0) {
			max_until_here = 0;
			i_max = i;
			j_max = i;
		}
		if (max_until_here >= max_total) {
			max_total = max_until_here;
			j_max = i;
		}
	}
	return {i_max, j_max, max_total};
}

int main(void) {

	int size = 48;
	int * test = new int[size];
	
	TestHelper::populateArrayIntegers(test, 200, 0, size - 1, true);

	steady_clock::time_point t1 = steady_clock::now();	

	//subarray res = find_maximum_subarray_dq(test, 0, size - 1); 
	//subarray res = find_maximum_subarray_quad(test, 0, size - 1); 
	subarray res = find_maximum_subarray_kadane(test, 0, size - 1); 

	steady_clock::time_point t2 = steady_clock::now();	
	
	duration<double> total_duration = duration_cast<duration<double>> (t2-t1);	

	cout << "Maximum-subarray: [ "<< res.begin << " ; " << res.end << " ] // sum = " <<res.sum << std::endl;
	cout << "Duration: " << total_duration.count() << std::endl;

	return 0;
}
