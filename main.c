#include "wrap.h"
#include "parse.h"

#define PID_FILE  "pid.file"

static void sigChldHandler(int signno);

static int isShowdir = 1;

char *cwd;

int main(int argc, char **argv) {
    int listenfd, connfd, port, clientlen;
    pid_t pid;
    struct sockaddr_in clientaddr;
    char isdaemon = 0, *portp = NULL, *logp = NULL, tmpcwd[MAXLINE];

#ifdef HTTPS
    int sslport;
    char dossl = 0, *sslportp = NULL;
#endif

    openlog(argv[0], LOG_NDELAY | LOG_PID, LOG_DAEMON);
    cwd = (char *) get_current_dir_name();
    strcpy(tmpcwd, cwd);
    strcat(tmpcwd, "/");

#ifdef HTTPS
#else
    parse_option(argc, argv, &isdaemon, &portp, &logp);
#endif

    portp == NULL ? (port = atoi(Getconfig("http"))) : (port = atoi(portp));

    signal(SIGCHLD, sigChldHandler);

    if (logp == NULL) {
        logp = Getconfig("log");
    }
    initlog(strcat(tmpcwd, logp));

    if (strcmp(Getconfig("dir"), "no") == 0) {
        isShowdir = 0;
    }

    clientlen = sizeof(clientaddr);

}

static void sigChldHandler(int signno) {
    waitpid(-1, NULL, WNOHANG);
}

