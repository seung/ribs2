#ifndef _EPOLL_WORKER__H_
#define _EPOLL_WORKER__H_

#include "ribs_defs.h"
#include "context.h"
#include "list.h"

extern int ribs_epoll_fd;
extern struct epoll_event last_epollev;

struct epoll_worker_fd_data {
    struct ribs_context *ctx;
    struct list timeout_chain;
    struct timeval timestamp;
};

extern struct epoll_worker_fd_data *epoll_worker_fd_map;

int epoll_worker_init(void);
void epoll_worker_loop(void);
void yield(void);
void courtesy_yield(void);

#include "../src/_epoll_worker.c"

#endif // _EPOLL_WORKER__H_
