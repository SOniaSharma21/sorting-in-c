#include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
int size1 = mid - left + 1;
int size2 = right - mid;
int Left[size1], Right[size2];

for (int i = 0; i < size1; i++) Left[i] = arr[left + i]; for
(int j = 0; j < size2; j++) Right[j] = arr[mid + 1 + j];
int i = 0, j = 0, k = left; while (i
< size1 && j < size2) { if
(Left[i] <= Right[j]) {
arr[k] = Left[i];
i++;
} else { arr[k] =
Right[j]; j++;
}
k++;
}

while (i < size1) {
arr[k] = Left[i];
i++; k++;
}


while (j < size2) {
arr[k] = Right[j];
j++; k++;
}
}
void mergeSort(int arr[], int left, int right) {
if (left < right) {
int mid = left + (right - left) / 2;
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
merge(arr, left, mid, right);
}
}
void printArray(int arr[], int n) {
for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
printf("\n");
}
int main() {
int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Unsorted array: \n");
printArray(arr, n);
mergeSort(arr, 0, n - 1);
printf("Sorted array: \n");
printArray(arr, n);



return 0;
}