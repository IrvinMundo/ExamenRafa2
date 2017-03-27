#include <stdio.h>
#include <stdlib.h>

void merge(int numbers[], int left, int mid, int right);

void print_array(int arr[], int len) {
    int i;
    
    for (i=0; i < len; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void merge_sort(int numbers[], int left, int right)
{
    int mid;
    
    if (right > left)
    {
        mid = (right + left) / 2;
        merge_sort(numbers, left, mid);
        merge_sort(numbers, mid+1, right);
        
        merge(numbers, left, mid+1, right);
    }
}

void merge(int numbers[], const int left, const int mid, const int right)
{
    int left1 = left;
    int mid1 = mid;
    
    int left_end, num_elements, tmp_pos;
    
    left_end = mid - 1;
    tmp_pos = 0;
    num_elements = right - left + 1;
    int temp[num_elements];
    
    while ((left1 <= left_end) && (mid1 <= right))
    {
        if (numbers[left1] <= numbers[mid1])
        {
            temp[tmp_pos++] = numbers[left1++];
        }
        else
        {
            temp[tmp_pos++] = numbers[mid1++];
        }
    }
    
    while (left1 <= left_end)
    {
        temp[tmp_pos++] = numbers[left1++];
    }
    while (mid1 <= right)
    {
        temp[tmp_pos++] = numbers[mid1++];
    }
    
    int i;
    left1 = left;
    for (i=0; i < num_elements; i++, left1++)
    {
        numbers[left1] = temp[i];
    }
}


