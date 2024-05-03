#include <iostream>
#include <vector>

using namespace std;

long long sumOfDivisors(int n) {
    long long sum = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    int T;
    cout << "Input:" << endl;
    cin >> T;

    vector<int> testCases(T);

    for (int i = 0; i < T; ++i) {
        cin >> testCases[i];
    }

    cout << "Output:" << endl;
    for (int i = 0; i < T; ++i) {
        long long result = sumOfDivisors(testCases[i]);
        cout << result << endl;
    }

    return 0;
}
