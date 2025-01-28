#include <stdio.h>
#include <stdbool.h>

bool int_same(int,int);
bool float_same(float, float);


typedef long my_int;

//we want to customize character printing for
//raw char *
void print_string(const char * p)
{
    my_int x = 10;
    int idx = 0;
    char curr = p[idx];
    while(curr != '\0')
    {
        curr = p[idx];
        putchar(curr);
        idx++;
    }
}

void print_array_addresses(int * p, size_t len)
{
    for(int i = 0; i< len; i++)
    {
        printf("%d", (p[i])
    }
}

int main()
{

    print_string("Hello World\0");
}
