#include<stdio.h>
#include "sort.h"
#include<time.h>

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void insertSort(int *a,int n){
    int i,j,temp;
    for (i=1;i<n;i++){
            temp = a[i];
            for (j=i;j>0 && a[j-1]>temp;j--)
                    a[j] = a[j-1];
            a[j] = temp;
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp); //迭代 

void MergeSort(int *a,int begin,int end,int *temp){
    if (begin >= end)
	    return;
    int len = end - begin, mid = (len >> 1) + begin;
    int begin1 = begin, end1 = mid;
    int begin2 = mid + 1, end2 = end;
    MergeSort(a, begin1, end1, temp);
    MergeSort(a, begin2, end2, temp);
    int k = begin;
    while (begin1 <= end1 && begin2 <= end2)
        temp[k++] = a[begin1] < a[begin2] ? a[begin1++] : a[begin2++];
    while (begin1 <= end1)
        temp[k++] = a[begin1++];
    while (begin2 <= end2)
        temp[k++] = a[begin2++];
    for (k = begin; k <= end; k++)
        a[k] = temp[k];
}

void QuickSort_Recursion(int *a, int begin, int end){
	if (begin >= end)
        return;
    int mid = a[end];
    int left = begin, right = end - 1;
    while (left < right) {
        while (a[left] < mid && left < right)
            left++;
        while (a[right] >= mid && left < right)
            right--;
        swap(&a[left], &a[right]);
    }
    if (a[left] >= a[end])
        swap(&a[left], &a[end]);
    else
        left++;
    if (left)
        QuickSort_Recursion(a, begin, left - 1);
    QuickSort_Recursion(a, left + 1, end);
}

void QuickSort(int *a,int size);

int Partition(int *a, int begin, int end);

int max(int x, int y) {
    return x < y ? y : x;
}

void CountSort(int *a, int size, int *sorted_data){
	int *count_arr = (int *)malloc(sizeof(int) * 10000);
	int *sorted_arr = (int *)malloc(sizeof(int) * size);
	int i; 
	for(i = 0; i<10000; i++)
		count_arr[i] = 0;
		
	for(i = 0;i<size;i++)
		count_arr[a[i]]++;
		
	for(i = 1; i<10000; i++)
		count_arr[i] += count_arr[i-1]; 
		
	for(i = size; i>0; i--)
	{
		sorted_arr[count_arr[a[i-1]]-1] = a[i-1];
		count_arr[a[i-1]]--;	
	}
	free(count_arr);
}


int GetNumInPos(int num,int pos)
{
	int temp = 1,i;
	for (i=0; i < pos-1; i++)
		temp *= 10;
    
	return (num / temp) % 10;
}


void RadixCountSort(int *a,int size){
	start = clock();
	int *radixArrays[size];
	int i,pos,k,j;
	for (i = 0; i < 100; i++)
	{
		radixArrays[i] = (int *)malloc(sizeof(int) * (size + 1));
		radixArrays[i][0] = 0;
	}
	
	for (pos = 1; pos <= 10; pos++)
	{
		for (i = 0; i < size; i++)
		{
			int num = GetNumInPos(a[i], pos);
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}
        
		for (i = 0, j =0; i < 10; i++) 
		{
			for (k = 1; k <= radixArrays[i][0]; k++)
				a[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0;
		}
	}
	stop = clock();
    diff = (double)(stop - start)/1;
	printf("用时:%f(μs)\n",diff);
}


void ColorSort(int *a,int size){
	start = clock();
    int i = 0, j = 0, k = size - 1, left = 0, right = size - 1, index = 0;
    while(left < right) {
        for(i = left; i <= right; i++) {
            if(a[i] == 2) {
                swap(&a[i], &a[k]);
                k--;
                break;
            }
            else if(a[i] == 0 && i > j) {
                swap(&a[i], &a[j]);
                j++;
                break;
            } 
        }
        left = i;
        
        for(i = right; i >= left; i--) {
            if(a[i] == 0) {
                swap(&a[i], &a[j]);
                j++;
                break;
            }
            else if(a[i] == 2 && i < k) {
                swap(&a[i], &a[k]);
                k--;
                break;
            } 
        }
        right = i; 
    }
    stop = clock();
    diff = (double)(stop - start)/1;
	printf("用时:%f(μs)\n",diff);
}
