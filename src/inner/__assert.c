#include "__assert.h"
#include <stddef.h>
#include "../itoa.h"

#define __LINE_STR__(line_num) STRINGIFY(line_num)

static __print_technique __print = NULL;

void ASSERT_init(__print_technique print)
{
    __print = print;
}

void __ASSERT_failed(char* filename, int line, char* expr)
{
    if(__print != NULL)
    {
        // TODO: disable interrupt
        char line_str[4];
        itoa(line, line_str, 10);

        __print( (unsigned char *)"ASSERTION FAILED [" );
        __print( (unsigned char *)expr );
        __print( (unsigned char *)"] @ " );
        __print( (unsigned char *)filename );
        __print( (unsigned char *)":" );
        __print( (unsigned char *)line_str );
        __print( (unsigned char *)"\n" );

        while(1){};
    }
}
