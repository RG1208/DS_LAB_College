#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    printf("Choose the search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array must be sorted)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int result;
    switch (choice)
    {
    case 1:
        result = linearSearch(arr, n, key);
        break;
    case 2:
        result = binarySearch(arr, 0, n - 1, key);
        break;
    default:
        printf("Invalid choice.\n");
        return 1;
    }

    if (result == -1)
    {
        printf("Element not found.\n");
    }
    else
    {
        printf("Element found at index: %d\n", result);
    }

    return 0;
}
