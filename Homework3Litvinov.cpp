#include "pch.h"
#include <iostream>
#include "time.h"

using namespace std;

void quickSort(int* A, int left, int right) {
	int leftBound = left;
	int rightBound = right;
	int pivotIndex = (left + right) / 2;
	int middleNumber = A[pivotIndex];
	int temp;

	do {
		while (A[leftBound] < middleNumber && leftBound <= right) {
			leftBound++;
		}
		while (A[rightBound] > middleNumber && rightBound >= left) {
			rightBound--;
		}
		if (leftBound <= rightBound) {
			temp = A[leftBound];
			A[leftBound] = A[rightBound];
			A[rightBound] = temp;
			leftBound++;
			rightBound--;
		}
	} while (leftBound <= rightBound);

	if (rightBound > left) {
		quickSort(A, left, rightBound);
	}
	if (right > leftBound) {
		quickSort(A, leftBound, right);
	}
}

int main(){
	
	//array initialization
	int n;
	cout << "Array length: ";
	cin >> n;
	int* arr = new int[n];
	int MAX_AVAILABLE_NUMBER = 100;
	srand(clock());
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % MAX_AVAILABLE_NUMBER + 1;
	}

	//sorting array
	quickSort(arr, 0, n - 1);

	//print array
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "" << endl;

	int counter = 1;
	int maxCounter = counter;
	int number = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1]) {
			counter++;
		}
		else {
			if (counter >= maxCounter) {
				maxCounter = counter;
				number = arr[i - 1];
			}
			counter = 1;
		}
	}
	cout << "The most frequent element of Array: " << number << ": " << maxCounter << " times" << endl;
    return 0;
}