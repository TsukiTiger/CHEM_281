#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

// Reference value for Euler's number (e)
const float e_reference = 2.718281828459;

// Compute the approximation of 'e' using the original method
float computeE(int n) {
    float approximateValue = 1.0f + (1.0f / n);
    return pow(approximateValue, n);
}

// Compute the approximation of 'e' using an improved method
float computeImprovedE(int n) {
    float x = 1.0f / n;
    float logValue = log(1 + x);
    return exp(n * logValue);
}

// Compute the approximation of 'e' using another improved method
float computeImprovedE2(int n) {
    float x = 1.0f / n;
    float logValue = x;
    return exp(n * logValue);
}

// Q2 function for recursive square root exercise
int Q2() {
    int n_values[] = {2, 5, 10, 20, 30, 40, 100};

    for (int n : n_values) {
        float x = 100.0f;

        // Take the square root 'n' times
        for (int i = 0; i < n; ++i) {
            x = sqrt(x);
        }

        // Square the result back 'n' times
        for (int i = 0; i < n; ++i) {
            x = x * x;
        }

        cout << "For n = " << n << ", reconstructed x = " << x << endl;
    }

    return 0;
}

// Q3 function to compare computation methods as x approaches 0
int Q3() {
    double x_values[] = {1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10, 1e-11, 1e-12, 1e-13, 1e-14, 1e-15};

    for (double x : x_values) {
        // Original method of computing z
        double z_original = (exp(x) - 1.0) / x;

        // Alternative method of computing z
        double y = exp(x);
        double z_alternative;
        if (y == 1.0) {
            z_alternative = 1.0;
        } else {
            z_alternative = (y - 1.0) / log(y);
        }

        // Print results
        cout << "For x = " << x << ":" << endl;
        cout << "Original method z = " << z_original << endl;
        cout << "Alternative method z = " << z_alternative << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}

// Function to retrieve the exponent of a DOUBLE PRECISION number using bit manipulation
int getExponent(double num) {
    uint64_t bits = *reinterpret_cast<uint64_t*>(&num);
    uint64_t exponentMask = 0x7FF0000000000000;
    int biasedExponent = (bits & exponentMask) >> 52;
    return biasedExponent - 1023;  // Subtract the bias
}

// Expensive method to estimate the exponent
double estimateExponentExpensive(double num) {
    return log10(std::abs(num));
}

// Alternative method to estimate the exponent using bit manipulation
double estimateExponentAlternative(double num) {
    int base2Exponent = getExponent(num);
    return base2Exponent * log10(2);
}

int main() {
    int values[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

    // Q1: Comparing approximation methods against the reference value of e
    cout << "Q1: " << endl << endl;
    cout << "Comparing methods against reference e: " << e_reference << endl << endl;

    for(int n : values) {
        float e1 = computeE(n);
        float e2 = computeImprovedE(n);
        float e3 = computeImprovedE2(n);

        cout << "For n = " << n << ":" << endl;
        cout << "Original method e ~ " << e1 << ", Error: " << fabs(e1 - e_reference) << endl;
        cout << "Improved method e ~ " << e2 << ", Error: " << fabs(e2 - e_reference) << endl;
        cout << "More Improved method e ~ " << e3 << ", Error: " << fabs(e3 - e_reference) << endl;
        cout << "----------------------------------------" << endl;
    }

    // Q2: Recursive square root exercise
    cout << "Q2: " << endl << endl;
    Q2();
    cout << "----------------------------------------" << endl;

    // Q3: Comparison of computation methods as x approaches 0
    cout << "Q3: " << endl << endl;
    Q3();
    cout << "----------------------------------------" << endl;

    // Q4: Estimating exponent using two different methods
    cout << "Q4: " << endl << endl;
    double num = 1234.5678;
    cout << "Expensive method: " << estimateExponentExpensive(num) << endl;
    cout << "Alternative method: " << estimateExponentAlternative(num) << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}
