#include "warp.h"
#include "parse.h"

#define PID_FILE  "pid.file"

char *cwd;

int main(int argc, char **argv)
{
    int listenfd, connfd, port, clientlen;
    pid_t pid;
    struct sockaddr_in clientaddr;
    char isdaemon = 0, *portp = NULL, *logp = NULL, tmpcwd[MAXLINE];

    #ifdef HTTPS
        int sslport;
        char dossl = 0, *sslportp = NULL;
    #endif

    openlog(argv[0], LOG_NDELAY|LOG_PID, LOG_DAEMON);
    printf("%s", argv[0]);
    cwd = (char *)get_current_dir_name();
    strcpy(tmpcwd, cwd);
    strcat(tmpcwd, "/");

#ifdef HTTPS
#else
    parse_option(argc, argv, &isdaemon, &portp, &logp);
#endif
}

