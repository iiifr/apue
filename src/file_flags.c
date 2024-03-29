#include "apue.h"
#include <fcntl.h>

/*
*  Turn on one or more of the file status flags for a descriptor
*/
void
set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");
    val |= flags; /* turn on flags */
    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}

/*
*  Turn off one or more of the file status flags for a descriptor
*/
void
clr_fl(int fd, int flags) /* flags are file status flags to turn off */
{
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");
    val &= (~flags); /* turn off flags */
    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}