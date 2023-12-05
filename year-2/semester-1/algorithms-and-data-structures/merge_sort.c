#include <stdio.h>
#include <stdlib.h>

int* mergeSortedArrays(const int array1[], int size1, const int array2[], int size2);
int* mergeSort(int array[], int size);
void sliceArray(const int *source, int *destination, int start, int end);


int main() {
    int arr[] = {15,3,0,14,16,9,6,19,5,19,9,8,1,8,9,12,9,11,15,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Initial: [");
    for(int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n\n");

    int* merged = mergeSort(arr, size);

    printf("Sorted: [");
    for(int i = 0; i < size; i++) {
        printf("%d, ", merged[i]);
    }
    printf("]");

    return 0;
}

int* mergeSort(int array[], int size) {
    if(size <= 1) {
        return array;
    }

    int middle = size / 2;

    int sliceLeftHalf[middle];
    sliceArray(array, sliceLeftHalf, 0, middle);
    int slicedRightHalf[(size) - middle];
    sliceArray(array, slicedRightHalf, middle, (size));

    int* sortedLeft = mergeSort(sliceLeftHalf, middle);
    int* sortedRight = mergeSort(slicedRightHalf, size - middle);

    int* combined = mergeSortedArrays(sortedLeft, middle, sortedRight, size - middle);

    return combined;
}

void sliceArray(const int *source, int *destination, int start, int end) {
    int j = 0;
    for (int i = start; i < end; ++i) {
        destination[j++] = source[i];
    }
}

int* mergeSortedArrays(const int array1[], int size1, const int array2[], int size2) {
    int combinedSize = size1 + size2;

    int* mergedArray = (int*)malloc(combinedSize * sizeof(int));

    int left = 0;
    int right = 0;

    for(int i = 0; i < combinedSize; i++) {
        int isLeftInBounds = left < size1 ? 1 : 0;
        int isRightInBounds = right < size2 ? 1 : 0;

        if(isLeftInBounds == 1 && array1[left] <= array2[right]) {
            mergedArray[i] = array1[left];
            left++;
            continue;
        }
        if(isRightInBounds == 1 && array2[right] <= array1[left]) {
            mergedArray[i] = array2[right];
            right++;
            continue;
        }

        if(isLeftInBounds == 1 && isRightInBounds == 0) {
            mergedArray[i] = array1[left];
            left++;
            continue;
        }

        if(isRightInBounds == 1 && isLeftInBounds == 0) {
            mergedArray[i] = array2[right];
            right++;
            continue;
        }

    }

    return mergedArray;
}