#pragma once

#include<iostream>
#include<algorithm>

using namespace std;

void buildMinHeap(int arr[], int n);

void buildMaxHeap(int arr[], int n);

void MinHeap(int a[], int n, int i);

void swap(int& a, int& b);

void MaxHeap(int a[], int n, int i);

void deleteMax(int a[], int n);

void deleteMin(int a[], int n);