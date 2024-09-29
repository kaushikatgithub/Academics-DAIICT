#include <iostream>
#include<vector>
using namespace std;

// Time Comlexity : O(N)
// Auxiliary Space : O(1)
int partition(vector<int> &nums, int l, int r) {
    
    int pivot = nums[r]; // Pivot variable
    
    int i = l-1; // Pointer for elements less than or equal to pivot
    
    for(int j = l ; j <= r-1 ; ++j) {
        
        // If element at jth position is less than or eqaul to pivot then put it to ++i position
        if(nums[j] <= pivot) {
            
            ++i;
            swap(nums[i], nums[j]);
            
        }
        
    }
    
    // Final swap to put pivot to its correct position
    swap(nums[++i], nums[r]);
    
    // Returning pivot index
    return i;
}

// Time Comlexity :  1) Worst case : O(N * N)
//                   2) Best case : O(N * LogN)
//                   3) Average case : O(N * LogN)
// Auxiliary Space : 1) Worst case : O(N)
//                   2) Best case : O(LogN)
void quickSort(vector<int> &nums, int l, int r) {
    
    if(l < r) {
        
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot-1);
        quickSort(nums, pivot+1, r);
        
    }
    
}

int main() {
    
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    
    vector<int> nums(n);
    
    cout << "Enter array elements : ";
    for(int i = 0 ; i < n ; ++i) cin >> nums[i];
    
    // Sort the array
    quickSort(nums, 0, n-1);
    
    cout << "Array in sorted order : ";
    for(int i = 0 ; i < n ; ++i) cout << nums[i] << " ";

    return 0;
}

