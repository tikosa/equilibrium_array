#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Watson gives Sherlock an array A of length n. Then he asks him to determine if there exists an element in the array such that the sum of the elements on its left is equal to the sum of the elements on its right. If there are no elements to the left/right, then the sum is considered to be zero. 
// Formally, find an , such that, a0 + ... + a(i-1) == a(i+1) + ... + a(n-1)
// INPUT
// The first line contains T, the number of test cases. For each test case, the first line contains n, the number of elements in the array A. The second line for each test case contains  space-separated integers, denoting the array A.
// Output Format
//
// For each test case print YES if there exists an element in the array, such that the sum of the elements on its left is equal to the sum of the elements on its right; otherwise print NO.

int equilibrium(const std::vector<int>& arr, int n){
    if(n == 0 || n == 2) {
        return -1;
    }
    if(n == 1)
        return 0;
    if(n == 3){
        if(arr[0] == arr[2]) {
            return 0;
        } else
            return -1;
    }
    
    long long sum1 = 0;
    long long sum2 = 0;
    int i = 0;
    int j = n-1;
    while(sum1 != sum2 || (j-i > 2)) {
        if(sum1 < sum2) {
            sum1 += arr[i++];
            if(j-i == 0 && sum1 == sum2)
                return 0;
        } else if (sum1 > sum2) {
            sum2 += arr[j--];
            if(j-i == 0 && sum1 == sum2)
                return 0;
        } else {
            sum1 += arr[i++];
            sum2 += arr[j--];
            if(j-i == 0 && sum1 == sum2)
                return 0;
        }
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    std::cin >> T;
    for(int t = 0; t < T; ++t)
    {
        int arr_size;
        std::cin>> arr_size;
        std::vector<int> arr(arr_size, 0);
        for(int i = 0; i < arr_size; ++i)
        {
            std::cin >> arr[i];
        }
        if(equilibrium(arr, arr_size) == -1)
            {
            std::cout << "NO" << std::endl;
        }
        else
        {
            std::cout << "YES" << std::endl;
        }
    }
    return 0;
}


