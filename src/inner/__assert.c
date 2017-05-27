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

        __print( "ASSERTION FAILED [");
        __print( expr );
        __print( "] @ " );
        __print( filename );
        __print( ":" );
        __print( line_str );
        __print( "\n" );

        while(1){};
    }

    else
    {
        while(1){};
    }
}
