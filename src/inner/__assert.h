#ifndef __ASSERT_H_
#define __ASSERT_H_

typedef void (*__print_technique)(unsigned char*);
void __ASSERT_failed(char* filename, int line, char* expr);

#define STRINGIFY(x) #x
#define __ASSERT(expr) \
    do { \
        if(!(expr))\
            __ASSERT_failed(__FILE__, __LINE__, STRINGIFY(expr)); \
    } while((0));

#endif // __ASSERT_H_
