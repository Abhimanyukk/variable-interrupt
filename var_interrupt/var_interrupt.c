#include "var_interrupt.h"
#include <stdio.h>

static void *task_handler(void *argv)
{
    varint_t *varint;
    varint = argv;
    varint->old_var = malloc(varint->len);
    memcpy(varint->old_var, varint->var, varint->len);

    while (1) {
        if (memcmp(varint->old_var, varint->var, varint->len)) {
            varint->handler(NULL);
            memcpy(varint->old_var, varint->var, varint->len);
        }
    }
}

void varint_reg(void *var, FUN_PTR handler, size_t len)
{
    varint_t *varint;
    varint = malloc(sizeof(varint_t));
    varint->var = var;
    varint->handler = handler;
    varint->len = len;

    pthread_t task;
    pthread_create(&task, NULL, task_handler, varint);
}
