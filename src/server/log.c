#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <share/util.h>
#include <log.h>

JJ_EXPORT void jj_log(const char *info)
{
        printf("%s\n", info);
}