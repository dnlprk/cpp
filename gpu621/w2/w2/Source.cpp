// Workshop 2 - Calculate PI by integrating 1/(1+x^2)
 // w2.serial.cpp

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <omp.h>

#define PAD 8
#define NUM_THREADS 8
using namespace std::chrono;

// report system time
//
void reportTime(const char* msg, steady_clock::duration span) {
	auto ms = duration_cast<milliseconds>(span);
	std::cout << msg << " - took - " <<
		ms.count() << " milliseconds" << std::endl;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << argv[0] << ": invalid number of arguments\n";
		std::cerr << "Usage: " << argv[0] << "  no_of_slices\n";
		return 1;
	}
	int n = std::atoi(argv[1]);
	steady_clock::time_point ts, te;

	// calculate pi by integrating the area under 1/(1 + x^2) in n steps 
	ts = steady_clock::now();
	int nthreads;
	double x, pi = 0, sum[NUM_THREADS];
	double stepSize = 1.0 / (double)n;


	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
	{
		int i, id, nthrds;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (id == 0) nthreads = nthrds;
		for (i = id; i < n; i = i + nthreads) {
			x = ((double)i + 0.5) * stepSize;
			sum[id] += 4.0 / (1.0 + x * x);
		}
	}
	for (size_t i = 0; i < nthreads; i++)
		pi += sum[i] * stepSize;

	te = steady_clock::now();

	std::cout << "n = " << n <<
		std::fixed << std::setprecision(15) <<
		"\n pi(exact) = " << 3.141592653589793 <<
		"\n pi(calcd) = " << pi << std::endl;

	reportTime("Integration", te - ts);
	// terminate
	char c;
	std::cout << "Press Enter key to exit ... ";
	std::cin.get(c);
}