#ifndef ASSERT_H_
#define ASSERT_H_

#ifndef NDEBUG
    #include "inner/__assert.h"

    void ASSERT_init(__print_technique print);
    #define ASSERT(expr) __ASSERT(expr)
#else
    #define ASSERT(expr)
#endif // NDEBUG

#endif // ASSERT_H_
