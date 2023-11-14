#if !defined(MYPOTENTIAL_H)
#define MYPOTENTIAL_H

#include <complex>
#include "hw3.1.h"

class MyPotential : public Derivable
{
public:

    // Override the eval function
    std::complex<double> eval(const std::complex<double> r) override;
};

#endif // MYPOTENTIAL_H
