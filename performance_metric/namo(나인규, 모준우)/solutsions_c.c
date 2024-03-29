#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#define ARR_SIZE 100000

//Create 100000 random number
void random_arr(int random_number[]) {
	int temp;
	int check = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		while (1) {
			temp = ((int)rand() << 16) | ((int)rand());
			check = 0;
			for (int j = 0; j <= i; j++) {
				if (random_number[j] != temp) {
					continue;
				}
				else {
					check += 1;
					break;
				}
			}
			if (check == 0) {
				random_number[i] = temp;
				break;
			}
		}
	}
}

//Insertion Sort
void insertion_sort(int random_number[]) {
	int j = 0;
	for (int i = 1; i < ARR_SIZE; i++) {
		int current_val = random_number[i];
		for (j = i - 1; j >= 0; j--) {
			if (random_number[j] > current_val) {
				random_number[j + 1] = random_number[j];
			}
			else {
				break;
			}
		}
		random_number[j + 1] = current_val;
	}
}

//Quick Sort
void quick_sort(int random_number[], int start, int last) {
	if (start >= last) {
		return;
	}
	int pivot = start;
	int left = pivot + 1;
	int right = last;
	int temp;
	while (left <= right) {
		while (left <= last && random_number[left] <= random_number[pivot]) {
			left += 1;
		}
		while (right > start && random_number[right] >= random_number[pivot]) {
			right -= 1;
		}

		if (left > right) {
			temp = random_number[right];
			random_number[right] = random_number[pivot];
			random_number[pivot] = temp;
		}
		else {
			temp = random_number[left];
			random_number[left] = random_number[right];
			random_number[right] = temp;
		}
	}
	quick_sort(random_number, start, right - 1);
	quick_sort(random_number, right + 1, last);
}

//Merge Sort
void merge(int random_number[], int sorted[], int start, int mid, int last) {
	int left_list_index = start;
	int right_list_index = mid + 1;
	int sorted_index = start;

	int remain_list;
	while (left_list_index <= mid && right_list_index <= last) {
		if (random_number[left_list_index] <= random_number[right_list_index]) {
			sorted[sorted_index++] = random_number[left_list_index++];
		}
		else {
			sorted[sorted_index++] = random_number[right_list_index++];
		}
	}

	if (left_list_index > mid) {
		remain_list = right_list_index;
		while (remain_list <= last) {
			sorted[sorted_index++] = random_number[remain_list];
			remain_list += 1;
		}
	}
	else {
		remain_list = left_list_index;
		while (remain_list <= mid) {
			sorted[sorted_index++] = random_number[remain_list];
			remain_list += 1;
		}
	}
	for (int l = start; l <= last; l++) {
		random_number[l] = sorted[l];
	}
}

void merge_sort(int random_number[], int sorted[], int start, int last) {
	if (start < last) {
		int mid = (start + last) / 2;
		merge_sort(random_number, sorted, start, mid);
		merge_sort(random_number, sorted, mid + 1, last);
		merge(random_number, sorted, start, mid, last);
	}
}

//Heap Sort
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int random_number[], int index, int size) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int max_index = index;
	if (left < size && random_number[left] > random_number[max_index]) {
		max_index = left;
	}
	if (right < size && random_number[right] > random_number[max_index]) {
		max_index = right;
	}

	if (max_index != index) {
		swap(&random_number[index], &random_number[max_index]);
		heapify(random_number, max_index, size);
	}

}
void heap_sort(int random_number[], int size) {

	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(random_number, i, size);
	}

	for (int i = size - 1; i >= 0; i--) {
		swap(&random_number[0], &random_number[i]);
		heapify(random_number, 0, i);
	}
}

//Selection
int Partition(int arr[], int left, int right)
{
	int pos = arr[left];
	int low = left + 1, high = right;
	while (low <= high)
	{
		while (low <= right && arr[low] <= pos)
		{
			low++;
		}
		while (high >= (left + 1) && arr[high] >= pos)
		{
			high--;
		}
		if (low <= high)
		{
			swap(&arr[low], &arr[high]);
		}
	}
	swap(&arr[left], &arr[high]);
	return high;
}

int selection(int arr[], int left, int right, int select){

	if (select > 0 && select <= right - left + 1)
	{
		int pos = Partition(arr, left, right);

		if (pos - left == select - 1)
		{
			return arr[pos];
		}
		else if (pos - left > select - 1)
		{
			return selection(arr, left, pos - 1, select);
		}
		else
		{
			return selection(arr, pos + 1, right, select - pos + left - 1);
		}
	}
	return -1;
}


int main(void) {
	clock_t time;
	int random_number[ARR_SIZE];
	random_arr(random_number);

	int temp[ARR_SIZE];
	int *sorted = (int *)malloc(sizeof(int) * ARR_SIZE);

    clock_t all_time;
    all_time = clock();
	//Insertion Sort
	memcpy(temp, random_number, sizeof(random_number));
	time = clock();
	insertion_sort(temp);
	time = clock() - time;
	printf("Insertion Sort Running Time (O(n^2)): %lf\n", time / 1000.0);

	//Quick Sort
	memcpy(temp, random_number, sizeof(random_number));
	time = clock();
	quick_sort(temp, 0, ARR_SIZE-1);
	time = clock() - time;
	printf("Quick Sort Running Time (O(n*log(n))): %lf\n", time / 1000.0);

	//Merge Sort
	memcpy(temp, random_number, sizeof(random_number));
	time = clock();
	merge_sort(temp, sorted, 0, ARR_SIZE - 1);
	time = clock() - time;
	printf("Merge Sort Running Time (O(n*log(n))): %lf\n", time / 1000.0);

	//Heap Sort
	memcpy(temp, random_number, sizeof(random_number));
	time = clock();
	heap_sort(temp, ARR_SIZE);
	time = clock() - time;
	printf("Heap Sort Running Time (O(n*log(n))): %lf\n", time / 1000.0);

	//Selection
	memcpy(temp, random_number, sizeof(random_number));
	time = clock();
	int answer = selection(temp, 0, ARR_SIZE - 1, ARR_SIZE / 2);
	time = clock() - time;
	printf("Selection Running Time (O(n)): %lf -> ", time / 1000.0);
	if (answer == -1) {
		printf("Fail Searching\n");
	}
	else {
		printf("(Median: %d)\n", answer);
	}
    all_time = clock() - all_time;
    printf("All Time: %lf -> ", all_time / 1000.0);
	return 0;
}