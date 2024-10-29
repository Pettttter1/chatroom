#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include 

#define bool int
#define true 1
#define false 0

struct server {
        int size;
};

struct chat_room {
        struct server *server;
        const char *name;
        int fd;
        int id;
        int sum;
};

static struct server *create_server(const char *name, int size)
{

}

static struct chat_room *create_chat_room(const char *name, int fd)
{
        static int id = 0;
        struct chat_room *r = calloc(1, sizeof(struct chat_room));
        r->server = NULL;
        r->fd = fd;
        r->id = id;
        r->sum = 0;
        r->name = name;
}

static void server_handle_data(struct server *s)
{
        
}

int main()
{

}