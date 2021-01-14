#include"myLib.h"

void TEST(int selection, int n) {

	// DE CHUONG TRINH TINH DUOC THOI GIAN CHINH XAC HON NEN TRONG CHUONG TRINH NAY
   // THOI GIAN TINH SE LÀ MICROSECONDS

	ofstream fileOut("D:\\Result.txt", ios::out | ios::app);
	if (!fileOut) {
		cout << "\nCannot open file!";
		return;
	}
	string stra = "Truong hop 1: Du lieu dau vao duoc sap xep ngau nhien.";
	string strb = "Truong hop 2: Du lieu dau vao duoc sap xep gan nhu tang dan.";
	string strc = "Truong hop 3: Du lieu dau vao duoc sap xep tang dan.";
	string strd = "Truong hop 4: Du lieu dau vao duoc sap xep giam dan.";

	if (selection == 0) {
		switch (n) {

		case 3000:
		{
			fileOut << "\nN = 3000 phan tu" << endl;
			break;
		}
		case 10000:
		{
			fileOut << "\nN = 10000 phan tu" << endl;
			break;
		}
		case 30000:
		{
			fileOut << "\nN = 30000 phan tu" << endl;
			break;
		}
		case 100000:
		{
			fileOut << "\nN = 100000 phan tu" << endl;
			break;
		}
		case 300000: {
			fileOut << "\nN = 300000 phan tu" << endl;
		}
		}
	}

	switch (selection)
	{
	case 0:
	{
		fileOut << "\n" << stra << endl;
		break;
	}
	case 1:
	{
		fileOut << "\n" << strb << endl;
		break;
	}
	case 2:
	{
		fileOut << "\n" << strc << endl;
		break;
	}
	case 3:
	{
		fileOut << "\n" << strd << endl;
	}
	}

	int* a = nullptr;
	int* b = nullptr;
	int* c = nullptr;
	int* d = nullptr;
	int* e = nullptr;
	int* f = nullptr;
	int* g = nullptr;

	createArray(a, n);
	createArray(b, n);
	createArray(c, n);
	createArray(d, n);
	createArray(e, n);
	createArray(f, n);
	createArray(g, n);

	GenerateData(a, n, selection);
	GenerateData(b, n, selection);
	GenerateData(c, n, selection);
	GenerateData(d, n, selection);
	GenerateData(e, n, selection);
	GenerateData(f, n, selection);
	GenerateData(g, n, selection);

	//SelectionSort
	auto t1 = std::chrono::high_resolution_clock::now();

	selectionSort(a, n);

	auto t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	fileOut << "\nTime run of SeletectionSort " << (long long)duration << setprecision(5) << "  microseconds" << endl;

	//do mergesort
	t1 = std::chrono::high_resolution_clock::now();

	mergeSort(b, 0, n - 1);

	t2 = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	fileOut << "\nTime run of MergeSort " << (long long)duration << setprecision(5) << "  microseconds" << endl;

	// do heapsort
	t1 = std::chrono::high_resolution_clock::now();

	heapSort(c, n);

	t2 = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	fileOut << "\nTime run of HeapSort " << (long long)duration << setprecision(5) << "  microseconds" << endl;

	// do quicksort
	t1 = std::chrono::high_resolution_clock::now();

	quickSort(d, 0, n - 1);

	t2 = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	fileOut << "\nTime run of QuickSort " << (long long)duration << setprecision(5) << "  microseconds" << endl;

	//do insertionSort
	t1 = std::chrono::high_resolution_clock::now();

	insertionSort(e, n);

	t2 = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	fileOut << "\nTime run of InsertionSort " << (long long)duration << setprecision(5) << "  microseconds" << endl;

	//do bubblesort

	t1 = std::chrono::high_resolution_clock::now();

	bubbleSort(f, n);

	t2 = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	fileOut << "\nTime run of BubbleSort " << (long long)(duration) << setprecision(5) << " microseconds" << endl;

	//do binaryinsertionSort
	t1 = std::chrono::high_resolution_clock::now();

	binaryInsertionSort(g, n);

	t2 = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	fileOut << "\nTime run of BinaryInsertionSort " << (long long)(duration) << setprecision(5) << "  microseconds" << endl;


	destroyArray(a);
	destroyArray(b);
	destroyArray(c);
	destroyArray(d);
	destroyArray(e);
	destroyArray(f);
	destroyArray(g);

	fileOut.close();
}
int main() {


	int n = 0;
	int turn = 1;
	int selection = 0;
	while (turn < 6) {
		switch (turn) {
		case 1: {
			n = 3000;
			while (selection <= 3) {

				TEST(selection, n);
				selection++;
			}
			break;
		}
		case 2: {
			n = 10000;
			while (selection <= 3) {

				TEST(selection, n);
				selection++;
			}
			break;
		}
		case 3: {
			n = 30000;
			while (selection <= 3) {

				TEST(selection, n);
				selection++;
			}
			break;
		}
		case 4: {
			n = 100000;
			while (selection <= 3) {

				TEST(selection, n);
				selection++;
			}
			break;
		}
		case 5: {
			n = 300000;
			while (selection <= 3) {

				TEST(selection, n);
				selection++;
			}

			break;
		}

		}
		turn++;
		selection = 0;

	}
	cout << "\n THE PROGRAM RAN SUCCESSFULLY!";
	return 0;
}