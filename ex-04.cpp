#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

bool isSuperPrime(int n) {
    if (!isPrime(n)) return false;

    while (n > 0) {
        if (!isPrime(n)) return false;
        n = n / 10;
    }

    return true;
}

queue<int> superPrimeNumber(int n) {
    queue<int> result;
    for (int i = 2; i <= n; ++i) {
        if (isSuperPrime(i)) {
            result.push(i);
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;

    queue<int> superPrimes = superPrimeNumber(n);

    cout << "Cac so siu nguyen to nho hon hoac bang " << n << " la:" << endl;
    while (!superPrimes.empty()) {
        cout << superPrimes.front() << " ";
        superPrimes.pop();
    }
    cout << endl;

    return 0;
}
