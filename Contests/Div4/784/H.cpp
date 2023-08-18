#include <bits/stdc++.h>
using namespace std;
 
// Function to find the maximum possible AND
// of array after performing at most K operations
int max_And(int N, int K, vector<int>& arr)
{
    // Declare a vector bits_Count
    vector<int> bits_Count(31);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 31; j++) {
 
            // storing the set bit count at
            // j-th position
            if ((arr[i] & (1 << j)) != 0)
                bits_Count[j]++;
        }
    }
 
    for (int i = 30; i >= 0; i--) {
 
        // If possible to set the ith bit
        // in all the present array elements
        if (K >= N - bits_Count[i]) {
            K -= (N - bits_Count[i]);
            bits_Count[i] = N;
        }
    }
 
    // Initialize max_Ans = 0
    int max_Ans = 0;
 
    // Loop to find the bits
    // that will be set in the answer and
    // calculate the maximum possible value
    for (int i = 30; i >= 0; i--) {
        if (bits_Count[i] == N) {
            max_Ans += (1 << i);
        }
    }
 
    // Return the maximum possible AND
    return max_Ans;
}
 
// Driver Code
int main()
{
    int K = 2;
    vector<int> arr = { 1, 2, 3 };
    int N = arr.size();
 
    // Function Call
    cout << max_And(N, K, arr) << endl;
    return 0;
}