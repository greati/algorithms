/**
 * Given an array of integers, which is the subarray whose elements
 * produce the greatest sum?
 *
 * This solves the problem of maximum-subarray, through divide-and-conquer
 * approach, in Theta(n*log(n)).
 *
 * Author: Vitor Greati
 * Date: 12/25/2015
 * Inspired in: CLRS's Book
 * */

#include <iostream>
#include <limits.h>

using namespace std;

struct subarray {
	int begin, end, sum;
	subarray (int b, int e, int s) : begin {b}, end {e}, sum {s} {};
};

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

subarray find_maximum_subarray(int * A, int low, int high) {
	if (high == low)
		return {low, high, A[low]};
	else {
		int mid = low + (high - low) / 2;
		subarray maxleft = find_maximum_subarray(A, low, mid);
		subarray maxright = find_maximum_subarray(A, mid + 1, high);
		subarray maxcross = find_max_crossing_subarray(A, low, mid, high);
		if (maxleft.sum > maxright.sum && maxleft.sum > maxcross.sum)
			return maxleft;
		if (maxright.sum > maxleft.sum && maxright.sum > maxcross.sum)
			return maxright;
		else return maxcross;
	}
} 

int main(void) {

	int test[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

	subarray res = find_maximum_subarray(test, 0, sizeof(test)/sizeof(int) - 1);
	
	cout << "Maximum-subarray: [ "<< res.begin << " ; " << res.end << " ] // sum = " <<res.sum << std::endl;

	return 0;
}
