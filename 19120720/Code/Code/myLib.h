#include<iostream>
#include<cmath>
#include<ctime>
#include<fstream>
#include<algorithm>
#include <chrono>
#include<iomanip>


using namespace std;

template<class T>
void HoanVi(T& a, T& b);

void GenerateRandomData(int a[], int n);

void GenerateSortedData(int a[], int n);

void GenerateReverseData(int a[], int n);

void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);

void printArray(int a[], int n);

void selectionSort(int arr[], int n);

void mergeSort(int arr[], int left, int right);

void merge(int arr[], int left, int m, int right);

void heapify(int arr[], int n, int i);

void heapSort(int arr[], int n);

void quickSort(int arr[], int low, int high);

void bubbleSort(int arr[], int n);

void insertionSort(int arr[], int n);

int binarySearch(int a[], int item, int low, int high);

void binaryInsertionSort(int a[], int n);

void createArray(int*& a, int n);

void destroyArray(int*& a);