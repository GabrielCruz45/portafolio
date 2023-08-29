#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r); // carries out the recursive step of the algorithm
void merge_sorted_arrays(int a[], int l, int m, int r);

int main(void)
{
    int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    merge_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d", array[i]);
    }

    printf("\n");
}

void merge_sort(int a[], int length)
{
    merge_sort_recursion(a, 0, length - 1); // 0 and length - 1 are the bounds of the entire array
    return;
}

void merge_sort_recursion(int a[], int l, int r)
{
    if (l < r)
    {
    int m = l + (r - 1) / 2; // Define the middle portion of the 'current' array

    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);

    merge_sorted_arrays(a, l, m, r);
    }

    return;
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
    int left_length = m - l + 1; // gives us the length of the left portion
    int right_length = r - m;

    int temp_left[left_length];
    int temp_right[right_length];

    // Copy current array into temporary arrays
    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = a[l + i];
    }


    for (int i = 0; i < right_length; i++)
    {
        temp_right[i] = a[m + 1 + i];
    }

    int i, j , k;

    // Merge
    // k is the index of the actual array we are sorting; k is really keeping track of array a[];
    // we are going from the left index to the rightmost index in our array
    for (i = 0, j = 0, k = l; k <= r; k++)
    {




        
        //  Visualization of what is happpening
        //
        //                  i
        //       temp_left: 4, 9, 12
        //
        //                  j
        //      temp_right: 5, 8, 14
        //
        //                  k
        //               a:
        //




        // i < left_length is checking wether you've reached the end of the temp_left array
        // temp_left[i] <= temp_right[j] is looking for the next element;
        // also if j >= right_length is true, then it does not really matter whether temp_left[i] <= temp_right[j] is true

        if  ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++; // Increments the position in the temp_left array
        }
        else
        {
            a[k] = temp_right[j];
            j++;
        }
    }

    return;
}