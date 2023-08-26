/*
Given a sorted array and a value x, the floor of x is the largest element in the array smaller than or equal to x.
Write efficient functions to find the floor of x
Input: arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
Output: 2
Explanation: 2 is the largest element in
arr[] smaller than 5

Input: arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20
Output: 19
Explanation: 19 is the largest element in
arr[] smaller than 20

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 0
Output : -1
Explanation: Since floor doesn’t exist, output is -1.
*/

#include <iostream>

int main()
{
    // int arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5;
    int arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20;
    // int arr[] = {1, 2, 8, 10, 10, 12, 19}, x = -1 ;

    int size = sizeof(arr) / sizeof(int), flag = 0;

// Solution 1
// Time Complexity: O(n) , Space Complexity: O(1)

    if (arr[size - 1] <= x)
        std ::cout << "Floor Element is: " << arr[size - 1];
    else if (arr[0] > x)
        std ::cout << "Floor Element is: " << -1;
    else
    {
        int i = 0;
        for (; i < size; i++)
        {

            if (arr[i] > x)
            {
                flag = 1;
                std ::cout << "Floor Element is: " << arr[--i];
                break;
            }
        }
        if (flag == 0)
            std ::cout << "Absent";
    }

    std ::cout << "\n";

// Solution 2
// Time Complexity: O(logn) , Space Complexity: O(1)

    int start = 0, end = size - 1, mid = start + ((end - start) / 2);
    int ans;

    while (start <= end)
    {
        if (arr[mid] == x)
        {
            ans = arr[mid];
            break;
        }
        else if (arr[mid] < x)
        {
            ans = arr[mid];
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + ((end - start) / 2);
    }
    std ::cout << "Floor Element is: " << ans;
}