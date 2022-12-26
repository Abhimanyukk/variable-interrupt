#include "var_interrupt.h"
#include <stdio.h>
#include <unistd.h>

#define log(chr) printf("%s\n", chr);

static void handler_cb(void *argv)
{
    log("Handler");
}

int main()
{
    int i = 23;
    varint_reg(&i, handler_cb, sizeof(i));
    while (1) {
        sleep(3);
        i++;
    }
}
