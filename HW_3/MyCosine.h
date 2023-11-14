#if !defined(MYCOSINE_H)
#define MYCOSINE_H

#include <complex>
#include "hw3.1.h"

class MyCosine : public Derivable
{
public:

    // Override the eval function
    std::complex<double> eval(const std::complex<double> r) override;
};

#endif // MYCOSINE_H
