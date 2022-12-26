#ifndef VAR_INTERRUPT_H
#define VAR_INTERRUPT_H

#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef void (*FUN_PTR)(void *arg);

typedef struct {
    void *var;
    void *old_var;
    size_t len;
    FUN_PTR handler;
} varint_t;

void varint_reg(void *var, FUN_PTR handler, size_t len);

#endif /* VAR_INTERRUPT_H */
