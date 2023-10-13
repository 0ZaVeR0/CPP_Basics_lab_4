#include <iostream>
using namespace std;

float* init1d(int n) {
	float* m = new float[n];
	return m;
}

int** init2d(int n, int m) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	return matrix;
}

void fillrand2d(int** matrix, int n,int min, int max) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = min + (rand() % (max - min + 1));
		}
	}
}

void fillrand1d(float* m, int n, int min, int max) {
	float* m1d;
	for (m1d = m; m1d < (n + m); m1d++) {
		*m1d = (min + (rand() % (max - min + 1))) / 10.;
	}
}

void print2d(int** matrix, int n) {
	/*
		start adress **
		end adress **
		start value *
		end value *
	*/ 
	int** end_adress = matrix + n;
	int* end_value;
	for (int** start_adress = matrix; start_adress < end_adress; start_adress++){
		end_value = *start_adress + n; 
		for (int* start_value = *start_adress; start_value < end_value; start_value++) {
			cout << *start_value << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void print1d(float* m, int n) {
	float* m1d;
	for (m1d = m; m1d < (n + m); m1d++) {
		cout << *m1d << " ";
	}
}

void task1(int** matrix,float* m,int n) {
	float* m1d = m;
	int** end_adress = matrix + n;
	for (int i = 0; i < n; i++, m1d++) {
		*m1d = 0;
		for (int** start_adress = matrix; start_adress < end_adress; start_adress++) {
			*m1d += *(*start_adress + i);
		}
	}
	for (float* m1d = m; m1d < (m + n); m1d++) {
		*m1d /= (float)n;
	}
}

void task2(int** matrix, int n, int* max, int* min) {
	int c_max = *max;
	int c_min = *min;

	int** end_adress = matrix + n;
	int* end_value;
	int shift = 0;

	for (int** start_adress = matrix; start_adress < end_adress; start_adress++, shift++) {
		end_value = *start_adress + n;
		for (int* start_value = *start_adress + shift; start_value < end_value; start_value++) {
			if (abs(*start_value) > c_max) {
				c_max = abs(*start_value);
				*max = *start_value;
			}
			if (abs(*start_value) < c_min) {
				c_min = abs(*start_value);
				*min = *start_value;
			}
			cout << *start_value << " ";
		}
		cout << "\n";
	}
}

void main() {
	bool running = true;
	while (running) {
		srand(time(0));
		int abs_max = -9999999999;
		int abs_min = 9999999999;

		int n = 7;
		float* m;
		int** matrix;

		m = init1d(n);
		matrix = init2d(n, n);

		int task_number;
		cout << "\n";
		cin >> task_number;

		switch (task_number)
		{
		case(1):
			fillrand2d(matrix, n, 0, 100);
			print2d(matrix, n);
			task1(matrix, m, n);
			print1d(m, n);
			break;

		case(2):
			fillrand2d(matrix, n, -100, 100);
			print2d(matrix, n);
			task2(matrix, n, &abs_max, &abs_min);
			cout << "\n" << abs_max << " " << abs_min;
			break;

		case(101):
			running = false;
			break;

		default:
			break;
		}
	}
}