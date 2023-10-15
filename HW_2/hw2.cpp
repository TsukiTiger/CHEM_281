#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

const float e_reference = 2.718281828459;

float computeE(int n) {
    float approximateValue = 1.0f + (1.0f / n);
    return pow(approximateValue, n);
}

float computeImprovedE(int n) {
    float x = 1.0f / n;
    float logValue = log(1 + x);  // compute the logarithm directly
    return exp(n * logValue);
}

float computeImprovedE2(int n) {
    float x = 1.0f / n;
    float logValue = x;  // compute the logarithm directly
    return exp(n * logValue);
}

int Q2() {
    int n_values[] = {2, 5, 10, 20, 30, 40, 100};

    for (int n : n_values) {
        float x = 100.0f;

        // Take the square root n times
        for (int i = 0; i < n; ++i) {
            x = sqrt(x);
        }

        // Square the result back n times
        for (int i = 0; i < n; ++i) {
            x = x * x;
        }

        cout << "For n = " << n << ", reconstructed x = " << x << endl;
    }

    return 0;
}

int Q3() {
    double x_values[] = {1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10, 1e-11, 1e-12, 1e-13, 1e-14, 1e-15};

    for (double x : x_values) {
        // Original method
        double z_original = (exp(x) - 1.0) / x;

        // Alternative method
        double y = exp(x);
        double z_alternative;
        if (y == 1.0) {
            z_alternative = 1.0;
        } else {
            z_alternative = (y - 1.0) / log(y);
        }

        // Print results
        std::cout << "For x = " << x << ":" << std::endl;
        std::cout << "Original method z = " << z_original << std::endl;
        std::cout << "Alternative method z = " << z_alternative << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}


int getExponent(double num) {
    // Bitwise manipulation to get the exponent
    uint64_t bits = *reinterpret_cast<uint64_t*>(&num);
    uint64_t exponentMask = 0x7FF0000000000000;
    int biasedExponent = (bits & exponentMask) >> 52;
    return biasedExponent - 1023;  // Subtract the bias
}

double estimateExponentExpensive(double num) {
    return log10(std::abs(num));
}

double estimateExponentAlternative(double num) {
    int base2Exponent = getExponent(num);
    return base2Exponent * log10(2);
}

int main() {
    int values[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

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

    cout << "Q2: " << endl << endl;
    Q2();
    cout << "----------------------------------------" << endl;

    cout << "Q3: " << endl << endl;
    Q3();
    cout << "----------------------------------------" << endl;

    cout << "Q4: " << endl << endl;
    double num = 1234.5678;
    std::cout << "Expensive method: " << estimateExponentExpensive(num) << std::endl;
    std::cout << "Alternative method: " << estimateExponentAlternative(num) << std::endl;
    cout << "----------------------------------------" << endl;

    return 0;
}
