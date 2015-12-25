/**
 * This class provides some functions to help
 * on the tests of the implemented algorithms.
 * */

#ifndef _TEST_HELPER_
#define _TEST_HELPER_

#include <cstdlib>
#include <ctime>

class TestHelper {
	public:
		static void populateArrayIntegers(int * & V, int maxValue, int l, int h, bool allowNegative) {
			srand(std::time(0));
			for (int i = l; i <= h; ++i) {
				int r = std::rand() % maxValue;
				int s = std::rand() % 2;
				V[i] = r * (s && allowNegative ? -1 : 1);
			}
		}
};

#endif
