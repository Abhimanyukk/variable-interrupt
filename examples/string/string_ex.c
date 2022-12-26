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
    char str[100];
    varint_reg(str, handler_cb, sizeof(str));

    while (1) {
        scanf("%s", str);
    }
}
