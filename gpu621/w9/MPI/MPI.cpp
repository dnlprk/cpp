// Workshop 9 - Discretize the Elements of an Array
 // Chris Szalwinski
 // 2018/11/18
 // w9.mpi.c

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include <mpi.h>
#include <ctime>



// report processor time
//
void reportTime(const char* msg, int span) {
	printf("%s took %d milliseconds\n", msg, span);
}

// discretize data[n] into 0s and 1s
//
void discretize(float* data, int n) {
	for (int i = 0; i < n; i++)
		if (data[i] < 0.5f)
			data[i] = (pow(sin(data[i]), cos(data[i])) + pow(cos(data[i]), sin(data[i]))) / 2.0f;
		else
			data[i] = (pow(sin(data[i]), cos(data[i])) + pow(cos(data[i]), sin(data[i]))) / 2.0f;
}


int main(int argc, char** argv) {

	if (argc != 2) {
		fprintf(stderr, "%s : invalid number of arguments\n"
			"Usage: %s no_of_elements\n", argv[0], argv[0]);
		return 1;
	}
	// retrieve number of elements
	int n = atoi(argv[1]);
	clock_t start, end;

	// startup
	MPI_Status status;
	int rank, np;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &np);


	int nPerProcess = n / np;
	n = nPerProcess * np;
	int zeroes = 0;

	if (rank == 0) {
		// initialization
		start = clock();
		float* data = (float*)malloc(n * sizeof(float));
		float* result = (float*)malloc(n * sizeof(float));
		srand(time(0));
		for (int i = 0; i < n; i++)
			data[i] = (float)rand() / RAND_MAX;
		end = clock();
		reportTime("Initialization", (end - start) * 1000 / CLOCKS_PER_SEC);

		start = clock();
		// scatter the data to different processors
		MPI_Scatter(data, nPerProcess, MPI_FLOAT, MPI_IN_PLACE, 0, MPI_FLOAT, 0, MPI_COMM_WORLD);

		discretize(data, nPerProcess);
		// gather the results from the different processors
		MPI_Gather(data, nPerProcess, MPI_FLOAT, result, nPerProcess, MPI_FLOAT, 0, MPI_COMM_WORLD);

		end = clock();
		int time = end - start;
		int zeros = 0;
		reportTime("Conversion", time * 1000 / CLOCKS_PER_SEC);
		for (int i = 0; i < nPerProcess; i++)
			if (data[i] < 0.707f)
				zeros++;
		for (int i = nPerProcess; i < n; i++)
			if (result[i] < 0.707f)
				zeros++;
		zeroes = zeros;
		free(data);
		free(result);
		// accumulate times from the different processors

		int totalTime = time;
		for (int i = 1; i < np; i++) {
			MPI_Recv(&time, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			totalTime += time;
		}
		reportTime("Total All Processes", totalTime * 1000 / CLOCKS_PER_SEC);
		printf("%d = %d 0s + %d 1s\n", n, zeroes, n - zeroes);
	}
	else {
		float* data = (float*)malloc(nPerProcess * sizeof(float));
		clock_t start = clock();
		// receive scattered data for this process
		MPI_Scatter(NULL, nPerProcess, MPI_INT, data, nPerProcess, MPI_FLOAT, 0, MPI_COMM_WORLD);


		printf("Data received by process %d\n", rank);
		discretize(data, nPerProcess);
		// return converted data to scattering process
		MPI_Gather(data, nPerProcess, MPI_FLOAT, NULL, nPerProcess, MPI_INT, 0, MPI_COMM_WORLD);
		clock_t end = clock();
		int time = end - start;
		reportTime("Conversion", (clock() - start) * 1000 / CLOCKS_PER_SEC);
		// send process time to scattering process
		MPI_Send(&time, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		free(data);
	}
	MPI_Finalize();

	printf("%d = %d 0s + %d 1s\n", n, zeroes, n - zeroes);
}