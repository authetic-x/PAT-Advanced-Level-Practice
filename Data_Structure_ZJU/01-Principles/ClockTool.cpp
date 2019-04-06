//
// Created by authetic on 2019/4/6.
//

#include <cstdio>
#include <time.h>

clock_t start, stop;

double duration;

int main() {
    start = clock();
    // MyFunction();
    stop = clock();

    duration = (double)(stop - start) / CLK_TCK;
    return 0;
}