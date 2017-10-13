// random.h - stupid random engine header
#ifndef RANDOM
#define RANDOM
// provide 16-bit int
#include<cstdint>
// textbook page 669 says it works well on 16-bit computer
typedef int16_t int_t;
// replace
//  max_int(used in random.cpp)
// with
//  INT16_MAX(define in cstdint(stdint.h))
#define max_int INT16_MAX
class Random {
public:
    Random(bool pseudo = true);
    // Declare random-number generation methods here.
    double random_real();
    int_t random_integer(int_t low, int_t high);
    int_t poisson(double mean);
private:
    int_t reseed(); // Re-randomize the seed.
    int_t seed;
    int_t multiplier, add_on; // constants for use in arithmetic operations
};
#endif
