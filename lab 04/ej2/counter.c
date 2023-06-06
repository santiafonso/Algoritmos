#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {


    counter c= NULL;

    c = malloc(sizeof(struct _counter));

    c->count=0;

    assert(counter_is_init(c));

    return c;

}

void counter_inc(counter c) {

    c->count++;

}

bool counter_is_init(counter c) {
    

    
    bool b = (c->count==0);

    return b;
}

void counter_dec(counter c) {

    assert(!counter_is_init(c));
    
    c->count=c->count-1;
    
}

counter counter_copy(counter c) {

    counter p = NULL;

    p = counter_init();

    p->count = c->count;

    return p;


}

void counter_destroy(counter c) {
    
    free(c);
    c= NULL;

}
