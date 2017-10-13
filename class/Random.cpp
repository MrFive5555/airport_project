// random.cpp - stupid random engine(textbook page 667)
#include<ctime>
#include<cmath>
#include"Random.h"
int_t Random::reseed()
/* Post: The seed is replaced by a pseudorandom successor. */
{
    seed = seed * multiplier + add_on;
    return seed;
}
Random::Random(bool pseudo)
/* Post: The values of seed, add_on, and multiplier are initialized.initialized randomly only if pseudo == false. */
{
    if (pseudo) seed = 1;
    else seed = time(NULL) % max_int;
    multiplier = 2743;
    add_on = 5923;
}
double Random::random_real()
/* Post: A random real number between 0 and 1 is returned. */
{
    double max = max_int + 1.0;
    double temp = reseed();
    if (temp < 0) temp = temp + max;
    return temp / max;
}
int_t Random::random_integer(int_t low, int_t high)
/* Post: A random integer between low and high (inclusive) is returned. */
{
    if (low > high) return random_integer(high, low);
    else return ((int_t)((high - low + 1) * random_real())) + low;
}
int_t Random::poisson(double mean)
/* Post: A random integer, reflecting a Poisson distribution with parameter mean,
is returned. */
{
    double limit = exp(-mean);
    double product = random_real();
    int_t count = 0;
    while (product > limit) {
        count++;
        product *= random_real();
    }
    return count;
}
