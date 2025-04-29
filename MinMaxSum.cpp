#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>
using namespace std;

void compute_stats(const vector<int>& arr) {
    int min_val = INT_MAX, max_val = INT_MIN, sum = 0;

    #pragma omp parallel for reduction(min:min_val) reduction(max:max_val) reduction(+:sum)
    for (int i = 0; i < arr.size(); i++) {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
        sum += arr[i];
    }

    cout << "Minimum: " << min_val << endl;
    cout << "Maximum: " << max_val << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << (double)sum / arr.size() << endl;
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 7, 6, 8, 3, 4};
    compute_stats(arr);
    return 0;
}
