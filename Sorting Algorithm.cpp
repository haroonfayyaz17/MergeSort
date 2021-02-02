#include <iostream>
using namespace std;
const int size = 12;
class Sort
{

public:
	void MergeSort(int A[], int low, int high)
	{
		int mid = (low + high) / 2;
		if (low < high)
		{
			MergeSort(A, low, mid);
			MergeSort(A, mid + 1, high);
			Merge(A, low, mid, high);
		}
	}
	void Merge(int A[], int low, int mid, int high)
	{
		int LH = mid - low + 1;
		int  RH = high - mid;
		int *left = new int[LH];
		int *right = new int[RH];
		for (int i = 0; i < LH; i++)
			left[i] = A[low + i];
		for (int j = 0; j < RH; j++)
			right[j] = A[j + mid + 1];
		int s = 0, j = 0, k = low;
		while (s < LH&&j < RH)
		{
			if (left[s] < right[j])
				A[k++] = left[s++];
			else
				A[k++] = right[j++];
		}
		while (s < LH)
			A[k++] = left[s++];
		while (j < RH)
			A[k++] = right[j++];
		delete[]left;
		delete[]right;
	}
	void QuickSort(int A[], int low, int high)
	{
		if (low < high)
		{
			int index = partition(A, low, high);
			QuickSort(A, low, index - 1);
			QuickSort(A, index + 1, high);
		}
	}
	int partition(int A[], int low, int high)
	{
		int i = low;
		for (int j = low; j < high; j++)
		{
			if (A[j] < A[high])
			{
				swap(A[i], A[j]);
				i++;
			}
		}
		swap(A[i], A[high]);
		//i++;
		return i;
	}
	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	void display(int A[], int size)
	{
		for (int i = 0; i < size; i++)
			cout << A[i] << " ";
		cout << endl;
	}
};

int main()
{
	Sort sort;
	int arr[size] = { 99, 5, 4, 43, 13, 21, 94, 48, 98, 87, 12, 25 };
	sort.MergeSort(arr, 0, size - 1);
	//sort.QuickSort(arr, 0, size - 1);
	sort.display(arr, size);
	system("pause");
}