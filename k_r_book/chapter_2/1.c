#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    /* Unsigned char, short, int, long */
    printf("%d <= unsigned char  <= %d\n", 0, UCHAR_MAX);
    printf("%d <= unsigned short <= %d\n", 0, USHRT_MAX);
    printf("%u <= unsigned int   <= %u\n", 0, UINT_MAX);
    printf("%d <= unsigned long  <= %ld\n\n\n", 0, ULONG_MAX);
    
    /* Signed char, short, int, long */
    printf("%d <= signed char   <= %d\n", SCHAR_MIN, CHAR_MAX);
    printf("%d <= signed short  <= %d\n", SHRT_MIN,  SHRT_MAX);
    printf("%d <= signed int    <= %d\n", INT_MIN,   INT_MAX);
    printf("%ld <= signed long  <= %ld\n\n\n", LONG_MIN,  LONG_MAX);

    /* float and double */
    printf("%f <= float             <= %f\n", FLT_MIN,      FLT_MAX);
    printf("%d <= float exponents   <= %d\n", FLT_MIN_EXP,  FLT_MAX_EXP);
    printf("%f <= double            <= %f\n", DBL_MIN,      DBL_MAX);
    printf("%d <= double exponents  <= %d\n\n", DBL_MIN_EXP,  DBL_MAX_EXP);

    return 0;
}
