#include <cassert>
#include <cmath>
#include <vector>

#ifndef _ADJ_H_
#define _ADJ_H_
#endif

int get_weight_func(vector<unsigned char>& image, int i, int j) {
	assert(i >= 0 && i * 4 + 3 < image.size());
	assert(j >= 0 && j * 4 + 3 < image.size());
	return max(abs(image[i*4]-image[j*4]), max(abs(image[i*4+1]-image[j*4+1]), abs(image[i*4+2]-image[j*4+2])));
}