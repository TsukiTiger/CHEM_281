#include "hw3.1.h"
#include "MyPotential.h"
#include "MyCosine.h"
#include <iostream>
#include <complex>

std::complex<double> MyPotential::eval(const std::complex<double> r)
{
    const double threshold = 1e-6; // Define a small threshold value
    if (std::abs(r) <= threshold) // Check if magnitude is within the threshold
    {
        std::cout << "The input is effectively zero!" << std::endl;
        return std::complex<double>(0, 0);
    }
    return (std::complex<double>(1)/std::pow(r, 2) - std::complex<double>(1)/std::pow(r, 6));
}

std::complex<double> MyCosine::eval(const std::complex<double> r)
{
  return std::cos(r);
}


/********************************/
#include <stdio.h>
#include <float.h>
#include <hw3.1.h>

#include <complex>
#include <iostream>
#include <cmath>
#include <limits>

double firstDerivative(Derivable& d, const double x)
{
    const double h = std::sqrt(std::numeric_limits<double>::epsilon());

    // Complex step derivative
    std::complex<double> z(x, h);
    double complexStepDerivative = std::imag(d.eval(z) / h);

    // Finite difference method (Forward difference)
    double finiteDiffDerivative = (std::real(d.eval(x + h)) - std::real(d.eval(x))) / h;

    std::cout << "Complex Step Derivative: " << complexStepDerivative << std::endl;
    std::cout << "Finite Difference Derivative: " << finiteDiffDerivative << std::endl;

    // Depending on what you need, return one of the derivatives or both
    return complexStepDerivative; // Or finiteDiffDerivative
}