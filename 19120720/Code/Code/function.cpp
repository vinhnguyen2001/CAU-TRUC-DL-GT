#include"myLib.h"



template <class T>
void HoanVi(T& a, T& b)
{
    T x = a;
    a = b;
    b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        HoanVi(a[r1], a[r2]);
    }
}

void GenerateData(int a[], int n, int dataType)
{
    switch (dataType)
    {
    case 0:	// ngẫu nhiên
        GenerateRandomData(a, n);
        break;
    case 1:	// có thứ tự
        GenerateSortedData(a, n);
        break;
    case 2:	// có thứ tự ngược
        GenerateReverseData(a, n);
        break;
    case 3:	// gần như có thứ tự
        GenerateNearlySortedData(a, n);
        break;
    default:
        cout << "Error: unknown data type!\n";
    }
}

void printArray(int a[], int n) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n)
{
    int i = 0, j = 0;
    int min_idx = 0;

    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (; i < n - 1; i++)
    {
        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        HoanVi(arr[min_idx], arr[i]);
    }
}


void mergeSort(int arr[], int left, int right) {
    // thuan toan merge sort
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);

}

void merge(int arr[], int left, int m, int right) {

    int size1 = m + 1 - left;
    int size2 = right - m;

    int* TEM1 = new (std::nothrow) int[size1];
    if (!TEM1) {
        cout << "\nHeap Overflow!";
        return;
    }
    int* TEM2 = new (std::nothrow) int[size2];
    if (!TEM2) {
        cout << "\nHeap Overflow!";
        return;
    }

    for (int i = 0; i < size1; i++) {
        TEM1[i] = arr[left + i];
    }
    for (int j = 0; j < size2; j++) {
        TEM2[j] = arr[m + j + 1];
    }

    int i = 0, j = 0;
    int t = left;
    // sap xep phan tu cua hai mang phu theo thu tu vao mang chinh
    while (i < size1 && j < size2) {

        if (TEM1[i] <= TEM2[j]) {
            arr[t] = TEM1[i];
            i++, t++;
        }
        else {
            arr[t] = TEM2[j];
            j++, t++;
        }
    }

    // neu mang phu con phan tu thi copy toan bo phan tu sang mang chinh
    while (i < size1) {
        arr[t] = TEM1[i];
        i++, t++;
    }
    while (j < size2) {
        arr[t] = TEM2[j];
        j++, t++;
    }

    if (TEM1) {
        delete[] TEM1;
        TEM1 = nullptr;
    }
    if (TEM2) {
        delete[] TEM2;
        TEM2 = nullptr;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        HoanVi(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // tao mot max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        // dua phan tu lon nhat ra cuoi mang
        HoanVi(arr[0], arr[i]);

        //sap xep lai max heap voi so phan tu la i + 1
        heapify(arr, i, 0);
    }
}

void quickSort(int Data[], int left, int right)
{
    // Thuan toan quick sort  
    if (left <= right)
    {
        int key = Data[(left + right) / 2];
        int i = left;
        int j = right;

        while (i <= j)
        {
            while (Data[i] < key)
                i++;
            while (Data[j] > key)
                j--;

            if (i <= j)
            {
                swap(Data[i], Data[j]);
                i++;
                j--;
            }
        }

        if (left < j)
            quickSort(Data, left, j);
        if (right > i)
            quickSort(Data, i, right);
    }
}
void bubbleSort(int arr[], int n)
{ // thuat toan bubble Sort
    int i, j;
    bool flag = false;
    for (i = 0; i < n - 1; i++)
    {
        flag = false;
        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                HoanVi(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{// thuat toan insertion sort.
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        // 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int binarySearch(int a[], int item, int low, int high)
{  // tim kiem nhi phan
    if (high <= low) {

        return (item > a[low]) ? (low + 1) : low;
    }

    int mid = low + (high - low) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid]) {
        return binarySearch(a, item, mid + 1, high);
    }
    return binarySearch(a, item, low, mid - 1);
}


void binaryInsertionSort(int a[], int n)
{ // thuat toan binary insertion sort
    int i, loc, j, k = 0, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        loc = binarySearch(a, selected, 0, j);
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}


void createArray(int*& a, int n) {
    // tao mot mang dong
    a = new (std::nothrow) int[n];
    if (!a) {
        cout << "\nHeap overflow! ";
        return;
    }
}

void destroyArray(int*& a) {
    //huy mot mang dong
    if (a) {
        delete[]a;
        a = nullptr;
    }
}
