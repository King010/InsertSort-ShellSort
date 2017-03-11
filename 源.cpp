#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//模板，比较器

void InsertSort(int arr[],size_t size)//O(N^2)
{
	for (size_t idx = 1; idx < size; ++idx)
	{
		int temp = arr[idx];
		int end = idx-1;
		while (end >= 0 && temp<arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = temp;
	}
}
//
void InsertSort_P(int arr[], size_t size)//
{

	for (size_t idx = 1; idx < size; ++idx)
	{
		int temp = arr[idx];
		int end = idx-1;
		int left = 0;
		int right = idx-1;
		int pos = 0;
		int mid = 0;
		while (left <= right)
		{
			mid = left + ((right - left) >> 1);
			if (temp < arr[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

		for (pos = end; pos >= left; --pos)
			arr[pos + 1] = arr[pos];

		arr[left] = temp;
	}
}

void ShellSort(int arr[], size_t size)//O(N3 / 2)到O(N7 / 6)
{
	int gap = size;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (size_t idx = gap; idx < size; ++idx)
		{
			int temp = arr[idx];
			int end = idx - gap;
			while (end >= 0 && temp<arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = temp;
		}
	}
}


void PrintfArray(int *array,size_t size)
{
	for (size_t idx = 0; idx < size; ++idx)
	{
		cout << array[idx] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 21,25,49,25,16,8};
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort_P(arr, sizeof(arr) / sizeof(arr[0]));
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintfArray(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
	return 0;
}