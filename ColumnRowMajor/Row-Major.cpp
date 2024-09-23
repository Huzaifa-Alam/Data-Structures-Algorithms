#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int I[n] = {1, 2, 3, 4, 5}; // Random data for array I
    int S[n] = {5, 4, 3, 2, 1}; // Random data for array S
    int sum = 0;

    // Fixed loop conditions to iterate correctly
    for (int i = n - 1; i >= 0; i--) // Loop from n-1 to 0
    {
        int mul = I[i]; // Start with I[i]
        
        // Adjusted inner loop to iterate correctly
        for (int j = i - 1; j >= 0; j--) // Loop from i-1 to 0
        {
            mul *= S[j]; // Multiply by S[j]
        }
        
        sum += mul; // Accumulate the product
    }

    cout << "The total sum is: " << sum << endl; // Output the result
    return 0;
}
