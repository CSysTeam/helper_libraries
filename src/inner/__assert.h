#ifndef __ASSERT_H_
#define __ASSERT_H_

#include <string.h>

#define __FILENAME__ (strrchr("/" __FILE__, '/') + 1)

typedef void (*__print_technique)(char* data);
void __ASSERT_failed(char* filename, int line, char* expr);

#define STRINGIFY(x) #x
#define __ASSERT(expr) \
    do { \
        if(!(expr))\
            __ASSERT_failed(__FILENAME__, __LINE__, STRINGIFY(expr)); \
    } while((0));

#endif // __ASSERT_H_
