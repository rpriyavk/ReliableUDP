#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#include "rudp_types.h"

RUDP *RUDP_new()
{
    RUDP *rudp;

    rudp = calloc(1, sizeof(RUDP));
    if (!rudp) {
        printf("RUDP alloc failed\n");
        return NULL;
    }

    rudp->sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (rudp->sfd < 0) {
        printf("Sock fd creation failed, errno=%d\n", errno);
        goto err;
    }

    return rudp;
err:
    free(rudp);
    return NULL;
}

/*
 * @Description: Binds the UDP socket
 *
 * @Return: Returns 0 incase of success and -1 incase of failure
 */
int RUDP_bind(RUDP *rudp, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret;
    if (rudp) {
        ret = bind(rudp->sfd, addr, addrlen);
        if (ret) {
            printf("Bind failed, errno=%d\n", errno);
        } else {
            /* Bind succeeded */
            return 0;
        }
    }
    return -1;
}

/*
 * @Description: Connected UDP socket
 *
 * @Return: Returns 0 incase of success and -1 incase of failure
 */
int RUDP_connect(RUDP *rudp, const struct sockaddr *addr, socklen_t addrlen)
{
    //TODO Need to call connect()
    return -1;
}

int RUDP_send(RUDP *rudp, const uint8_t *data, uint16_t data_len, int flags)
{
    //TODO 
    return -1;
}

int RUDP_sendto(RUDP *rudp, const uint8_t *data, uint16_t data_len, int flags,
                const struct sockaddr *dstaddr, socklen_t dstaddrlen)
{
    int ret;
    ret = sendto(rudp->sfd, data, data_len, flags, dstaddr, dstaddrlen);
    if (ret <= 0) {
        printf("Sendto failed, ret=%d, errno=%d\n", ret, errno);
    } else {
        /* sendto succeeded */
        return ret;
    }
    return -1;
}

int RUDP_recv(RUDP *rudp, uint8_t *buf, uint16_t buf_size, int flags)
{
    //TODO
    return -1;
}


int RUDP_recvfrom(RUDP *rudp, uint8_t *buf, uint16_t buf_size, int flags,
                 struct sockaddr *srcaddr, socklen_t *srcaddrlen)
{
    int ret;
    ret = recvfrom(rudp->sfd, buf, buf_size, flags, srcaddr, srcaddrlen);
    if (ret <= 0) {
        printf("recvfrom failed, ret=%d, errno=%d\n", ret, errno);
    } else {
        /* recvfrom succeeded */
        return ret;
    }
    return -1;
}

void RUDP_close(RUDP *rudp)
{
    if (rudp) {
        close(rudp->sfd);
        free(rudp);
    }
}
