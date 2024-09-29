#include <iostream>
#include<vector>
using namespace std;

// Time complexity : O(N)
// Auxiliary Space : O(N)
void merge(vector<int> &nums, int l, int m, int r) {
 
    vector<int> temp(r - l + 1);
    
    int idx = 0; // Pointer for temp
    int i = l; // Pointer for left array
    int j = m+1; // Pointer for right array
    
    while(i <= m && j <= r) {
        
        if(nums[i] <= nums[j]) {
            
            temp[idx] = nums[i];
            ++idx;
            ++i;
            
        } else {
            
            temp[idx] = nums[j];
            ++idx;
            ++j;
            
        }
        
    }
    
    while(i <= m) {
        
        temp[idx] = nums[i];
        ++idx;
        ++i;
        
    }
    
    while(j <= r) {
        
        temp[idx] = nums[j];
        ++idx;
        ++j;
        
    }
    
    idx = l; // Pointer for nums
    i = 0; // Pointer for temp
    while(i < temp.size()) {
        nums[idx] = temp[i];
        ++idx;
        ++i;
    }
    
}

// Time Complexity : O(N * LogN)
// Auxiliary Space : O(LogN)
void mergeSort(vector<int> &nums, int l, int r) {
    
    if(l < r) {
        
        int m = (r-l)/2 + l;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
        
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
    mergeSort(nums, 0, n-1);
    
    cout << "Array in sorted order : ";
    for(int i = 0 ; i < n ; ++i) cout << nums[i] << " ";

    return 0;
}

