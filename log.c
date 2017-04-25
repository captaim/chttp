#include "parse.h"
#include "wrap.h"

FILE *logfp = NULL;

void initlog(const char *logp) {
    logfp = fopen(logp, "a+");
}



