#ifndef RUDP_H
#define RUDP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct rudp_st RUDP;

/*RUDP *RUDP_new();

int RUDP_bind(RUDP *rudp, const struct sockaddr *addr, socklen_t addrlen)

int RUDP_connect(RUDP *rudp, const struct sockaddr *addr, socklen_t addrlen);

int RUDP_send(RUDP *rudp, const uint8_t *data, uint16_t data_len, int flags);

int RUDP_recv(RUDP *rudp, uint8_t *buf, uint16_t buf_size, int flags);

void RUDP_close(RUDP *rudp);*/

#ifdef __cplusplus
}
#endif

#endif
