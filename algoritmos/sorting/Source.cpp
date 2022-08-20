#include<iostream>
#include<conio.h>

using namespace std;
using namespace System; 

template<class T>
void printArray(T array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
}

/*Compares each element with the next ones*/
template<class T>
void bubbleSort(T array[], int size) {
	cout << "Bubble Sort \n";

	T aux;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (int(array[i]) > int(array[j])) {
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				printArray(array, size);
			}
		}
	}
	cout << "End of bubble sort\n\n";
}


/*Suposes that the min or max is the position we are in, then swaps if that is not correct with the next items*/
template<class T>
void selectionSort(T array[], int size) {
	cout << "Selection Sort \n";

	T aux;
	int min;

	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (int(array[j]) < int(array[min])) {
				min = j;
				printArray(array, size);
			}
		}

		aux = array[i];
		array[i] = array[min];
		array[min] = aux;
	}
	cout << "End of selection sort\n\n";
}



/*Compares from the beginning with the previous ones*/
template<class T>
void insertionSort(T array[], int size) {
	cout << "Insertion Sort \n";

	int pos;
	T aux;

	for (int i = 0; i < size; i++) {
		pos = i;
		aux = array[i];

		while ((pos > 0) && (array[pos - 1] > aux)) {
			array[pos] = array[pos - 1];
			pos--;
		}

		array[pos] = aux;
		printArray(array, size);
	}
	cout << "End of insertion sort\n\n";
}

/*Its like insertion sort, makes partitions and begins with partition half of the size of the array */
template<class T>
void shellSort(T array[], int size) {
	cout << "Shell Sort \n";

	T aux; 

	bool band;
	int gap = size;

	while (gap > 1) {
		gap = (gap / 2);
		band = true;

		while (band == true) {
			band = false;

			/*Compares from array[0] with array[0+5] for example*/
			for (int i = 0; i < size - gap; i++) {
				if (int(array[i]) > int(array[i + gap])) {

					aux = array[i];
					array[i] = array[i + gap];
					array[i + gap] = aux;
					band = true;
					
					
				}
			}
		}
	}
	printArray(array, size);

	//for (int gap = size / 2; gap > 0; gap /= 2)
	//{
	//	for (int i = gap; i < size; i ++)
	//	{

	//		int temp = array[i];
	//		int j;
	//		for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
	//			array[j] = array[j - gap];

	//		array[j] = temp;
	//		printArray(array, size);
	//	}
	//}

	cout << "End of shell sort\n\n";
}



template<class T>
void merge(T* L, T* R, T* array, int size) {

	int left_size = size / 2;
	int right_size = size - left_size;
	int i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size) {
		if (L[i] < R[j]) {
			array[k] = L[i];
			k++; i++;
			printArray(array, size);
		}
		else {
			array[k] = R[j];
			k++; j++;
		}
	}

	while (i < left_size) {
		array[k] = L[i];
		k++; i++;
	}

	while (j < right_size) {
		array[k] = R[j];
		k++; j++;
	}
}

template<class T>
void mergeSort(T* array, int size) {
	if (size <= 1) {
		return;
	}

	int mid = size / 2;
	T* L = new T[mid];
	T* R = new T[size - mid];

	for (int i = 0; i < mid; i++) {
		L[i] = array[i];
	}

	for (int i = mid; i < size; i++) {
		R[i - mid] = array[i];
	}

	mergeSort(L, mid);
	mergeSort(R, size - mid);

	merge(L, R, array, size);

	delete[]L;
	delete[]R;
}


template<class T>
int partition(T* array, int left, int right) {
	int pivot = array[right];
	int i = left;
	for (int j = left; j < right; ++j) {
		if (array[j] <= pivot) {
			swap(array[i], array[j]);
			i++;
		}
	}
	swap(array[i], array[right]);
	return i;
}

template<class T>
void quickSort(T* array, int left, int right) {
	if (left < right) {
		int pivot_index = partition(array, left, right);
		quickSort(array, left, pivot_index - 1);
		quickSort(array, pivot_index + 1, right);
	}
}

template<class T>
void heapify(T* array, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i) {
		swap(array[i], array[largest]);
		heapify(array, n, largest);
	}
}

template<class T>
void heapSort(T* array, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(array, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}



int main() {
	srand(time(NULL));

	char array[10] = { 's' ,'s','k', 'y', 'b', 'n', 'v', 'j', 'h', 't' };
	//bubbleSort(array, sizeof(array));			/*Tiempo O(n^2)      Espacio O(1)*/

	char array2[10] = { 's' ,'s','k', 'y', 'b', 'n', 'v', 'j', 'h', 't' };
	//insertionSort(array2, sizeof(array2));	/*Tiempo O(n^2)      Espacio O(1)*/

	char array3[10] = { 's' ,'s','k', 'y', 'b', 'n', 'v', 'j', 'h', 't' };
	//selectionSort(array3, sizeof(array3));	/*Tiempo O(n^2)      Espacio O(1)*/

	char array4[10] = { 's' ,'s','k', 'y', 'b', 'n', 'v', 'j', 'h', 't'};
	//shellSort(array4, sizeof(array4));	/*Tiempo O(nlog(n)^2)      Espacio O(1)*/


	int size = 20;


	char* array5 = new char[size];
	for (int i = 0; i < size; i++) {
		/*97 to 122 ascii*/
		array5[i] = char(rand() % 26 + 97);
	}
	mergeSort(array5, size); /*Tiempo O(nlog(n))      Espacio O(n)*/
	printArray(array5, size);
	

	int* array6 = new int[size];
	for (int i = 0; i < size; i++) {
		/*97 to 122 ascii*/
		array6[i] = rand() % 100 + 10;
	}
	//quickSort(array6, 0, size - 1);		/*Tiempo O(n^2)      Espacio O(log(n))	Mejor caso: cuando el pivote es la mediana, peor cuando el pivot es el primer elemento*/ 
	//printArray(array6, size);
	

	/*Timsort Introsort*/



	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 10;
	}
	heapSort(arr, size);		/*Tiempo O(nlog(n))			Del Heapify O(Log(n))*/
	printArray(arr, size);



	_getch();
	return 0;
}