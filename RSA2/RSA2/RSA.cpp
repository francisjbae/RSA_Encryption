// RSA.cpp
#include "RSA.h"
#include <iostream>
#include <climits>

bool isPrime(unsigned long long n) {
    if (n <= 1) return false;
    for (unsigned long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

unsigned long long getPrime(unsigned long long min, unsigned long long max) {
    unsigned long long prime;
    do {
        prime = rand() % (max - min + 1) + min;
    } while (!isPrime(prime));
    return prime;
}

unsigned long long gcd(unsigned long long x, unsigned long long y) {
    while (y != 0) {
        unsigned long long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

unsigned long long lcm(unsigned long long x, unsigned long long y) {
    return (x * y) / gcd(x, y);
}

unsigned long long modInverse(unsigned long long e, unsigned long long lam) {
    for (unsigned long long d = 1; d <= lam; d++) {
        if ((e * d) % lam == 1) {
            return d;
        }
    }
    return 0; // Should not reach here if inputs are valid.
}

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long n) {
    unsigned long long ans = 1;
    for (unsigned long long i = 0; i < exp; i++)
        ans = (ans * base) % n;
    return ans;
}
