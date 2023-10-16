## Q1: Estimation of Euler's Number (e)

**a. Using the formula:**
\[ e = (1 + \frac{1}{n})^n \]
- The error between the estimated \( e \) and the referenced \( e \) decreases as \( n \) grows. However, starting from \( n = 1 \times 10^5 \), the error begins to grow again. This is likely due to the precision limits of single-precision floating-point arithmetic. When \( n \) is large, the term \( \frac{1}{n} \) becomes very small, and adding it to 1 can lead to a significant loss of precision.

**b. Using the improved formula:**
\[ e = \exp(n \times \log(1 + \frac{1}{n})) \]
- While the improved method doesn't necessarily enhance the estimation accuracy, it provides a theoretical benefit. As \( \log(1+x) \) approaches 0 when \( x \) approaches 0, the equation converges to \( e = \exp(1) \) as \( n \) goes to infinity.
- The further improved method:
  \[ e = \exp(n \times \frac{1}{n}) \]
  improves the accuracy of the estimation.

---

## Q2: Cumulative Errors in Repeated Arithmetic

The exercise demonstrates the accumulation of rounding errors in single precision arithmetic. For smaller values of \( n \), the reconstructed value is accurate. However, as \( n \) increases, rounding errors compound:
- For \( n = 2 \) and \( n = 5 \), the results are fairly accurate.
- By \( n = 10 \), the errors become evident.
- By \( n = 20 \), the inaccuracies are significant.
- Beyond \( n = 30 \), the result collapses to 1, highlighting the substantial loss of precision.

---

## Q3: Evaluating Mathematical Limits

The results from `Q3` highlight the nuances of numerical computation:
- As \( x \) approaches zero, the `Original method` becomes unstable, leading to deviations from the expected value of \( z \) which should be 1.
- The `Alternative method` consistently yields the correct value, even for values of \( x \) very close to zero.

This comparison emphasizes the advantage of double over single precision, especially when dealing with values nearing computational limits.

---

## Q4: Estimating Exponents

The output for `Q4` demonstrates a clear difference between the two exponent estimation methods:
- The **Expensive method**, which uses direct logarithm computation, offers more accuracy but at a potentially higher computational cost.
- The **Alternative method** quickly approximates the exponent by exploiting the IEEE double precision format's bit representation. However, the conversion from a base-2 to a base-10 logarithm may introduce some inaccuracy.

This distinction highlights the trade-offs between precision and computational efficiency. Direct mathematical approaches might be more accurate, but leveraging data representations, as done in the alternative method, can enhance computational speed at the expense of slight inaccuracies.

---