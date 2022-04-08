#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

std::vector<int> merge(std::vector<int> left, std::vector<int> right){
    std::vector<int> merged;
    int l = 0, r = 0;
    while(l != left.size() && r != right.size()){
        if(left[l] > right[r]){
            merged.push_back(right[r]);
            r++;
        }
        else{
            merged.push_back(left[l]);
            l++;
        }
    }
    while(l != left.size()){
        merged.push_back(left[l]);
        l++;
    }
    while(r != right.size()){
        merged.push_back(right[r]);
        r++;
    }
    return merged;
}

std::vector<int> msort(std::vector<int> list){
    if(list.size() <= 1){
        return list;
    }
    int mid = list.size()/2;
    std::vector<int> l1,l2;
    for(int i = 0; i < list.size(); i++){
        if(i < mid){
            l1.push_back(list[i]);
        }
        else{
            l2.push_back(list[i]);
        }
    }
    l1 = msort(l1);
    l2 = msort(l2);
    list = merge(l1,l2);
    return list;
}
void printVec(int v[], int size){
    for(int i = 0; i < size; i++){
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}

std::vector<int> qsort(std::vector<int> list){
    int i,j; 
    // base case
    if (list.size() <= 1){
        return list;
    }
    // select a pivot value.
    // for now, just pick list[0]
    int pivot = list[0];
    // make 2 new vectors
    std::vector<int> lower,higher;
    // copy all the values < pivot value to lower
    // copy all the values >= pivot value to higher;
    for (i=1; i < list.size(); i++){
        if (list[i] < pivot){
            lower.push_back(list[i]);
        } 
        else {
            higher.push_back(list[i]);
        }
    }
    lower = qsort(lower);
    higher = qsort(higher);

    // copy everything back into list
    for(i=0 ; i < lower.size(); i++){
        list[i]=lower[i];
    }

    list[i] = pivot;
    i++;

    for(j=0;j<higher.size();j++){
        list[i] = higher[j];
        i++;
    }
    // return the sorted list
    return list; 
}

//Credit: too GeeksForGeeks
//https://www.geeksforgeeks.org/quick-sort/

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int size = 30; // default vector size
    //int size = 10000; // default vector size
    int max_val = 100; // default max value for entries
    srand(time(NULL));
    int arr[size];
    int i;
    for(i=0;i<size;i++){
        arr[i] = rand()%max_val;    
    }
    printVec(arr, size);
    //std::vector<int> b = qsort(a);
    quickSort(arr,0,size);
    //printVec(b);
    printVec(arr, size);
    return 0;
}