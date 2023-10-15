Q1:
- a: e = (1 + 1/n)^n The error of the estimated e and the referenced e is getting smaller as the value of n is larger. But, after 1*10^5, the error is getting larger. This might because the precision of the Single Precision Float of the 1/n part reaches its smallest limit, but the exponent n is not limited, so the error is getting larger. 
- In single precision arithmetic, as n becomes large, the addition operation 1/n can lead to a loss of precision, as most of the significant bits of are lost in the addition. This error is then propagated through the remaining calculations.
- b: e = exp(n * log(1 + 1/n)) The new method does not improving the estimation. But as the log(1+x) = 0 as x is approaching to 0, the new equation could be e = exp(1) as n is approaching to infinite.
- With the more improved method, e = exp(n * (1/n)), the accuracy of the estimation was improved.

Q2: 

The output illustrates the cumulative inaccuracies of single precision arithmetic when performing repeated operations. For small values of \( n \) (2 and 5), the reconstructed value remains accurate. However, as \( n \) increases, rounding errors compound, leading to noticeable deviations by \( n = 10 \) and significant inaccuracies by \( n = 20 \). Beyond \( n = 30 \), the value collapses to 1, highlighting the severe loss of precision. This behavior underscores the limitations of single precision arithmetic, where repeated mathematical operations can amplify minor errors, causing substantial deviations from expected results.

Q3:
The output from `Q3` underscores the nuances of numerical computation and the pitfalls of handling values that approach limits. For values of \( x \) closer to zero, the direct computation method (`Original method`) becomes unstable, resulting in values of \( z \) that deviate from the expected 1. On the other hand, the `Alternative method` consistently provides the expected value of \( z \), which is 1, even as \( x \) nears zero.

This exercise illustrates the benefit of using double precision over single precision. Double precision offers a greater number of significant digits and a larger exponent range, ensuring that intermediate computations retain more accuracy and are less prone to rounding errors. In essence, double precision enhances the reliability of numerical calculations, especially in scenarios where precision is paramount or where values are very close to computational limits.

Q4:
From the output of Q4, there's a noticeable difference between the exponents obtained through the expensive method and the alternative method. The expensive method, which involves directly using the logarithm function, provides a more accurate estimation of the exponent, albeit at a potentially higher computational cost. In contrast, the alternative method leverages knowledge of the IEEE double precision format and bit manipulation to quickly approximate the exponent, but it may not be as precise due to the conversion from a base-2 to a base-10 logarithm.

The divergence between the two methods underscores the trade-off between precision and computational efficiency. While direct mathematical operations often yield more accurate results, understanding and utilizing the underlying representations of data, as seen in the alternative method, can offer substantial computational savings. This is particularly relevant in scenarios where performance is a priority and slight inaccuracies can be tolerated.