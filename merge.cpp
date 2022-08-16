#include <iostream>

using namespace std;
void merge(int* arr, const int left, const int mid, const int right);
void merge_sort(int* arr, const int begin, const int end);
int main()
{
	int arr[10]{2,32,1,4,64,23,66,39,1,9};
	merge_sort(arr, 0, 9);
	for(int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	return 0;
}

void merge(int* arr, const int left, const int mid, const int right)
{
	int i, j;
	// getting the sizes
	auto const m = mid - left + 1;
	auto const n = right - mid;
	// creating dynamic arrays
	auto left_arr = new int[m];
	auto right_arr = new int[n];
	// filling arrays
	for(i = 0; i < m; ++i)
		left_arr[i] = arr[left + i];
	for(j = 0; j < n; ++j)
		right_arr[j] = arr[mid + 1 + j];
	
	auto index_left = 0, index_right = 0;
	int index_merge = left;
	
	// filling the final array
	while(index_left < m && index_right < n)
	{
		if(left_arr[index_left] <= right_arr[index_right])
		{
			arr[index_merge] = left_arr[index_left];
			++index_left;
		}
		else
		{
			arr[index_merge] = right_arr[index_right];
			++index_right;
		}
		++index_merge;
	}
	while(index_left < m)
	{
		arr[index_merge] = left_arr[index_left];
		++index_merge;
		++index_left;
	}
	while(index_right < n)
	{
		arr[index_merge] = right_arr[index_right];
		++index_merge;
		++index_right;
	}	

}
void merge_sort(int* arr, const int begin, const int end)
{
	if(begin >= end)
		return;
	
	int mid = (begin + end) / 2;
	merge_sort(arr, begin, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}









