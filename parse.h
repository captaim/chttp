#ifndef _PARSE_CONFIG_H
#define _PARSE_CONFIG_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <syslog.h>
#include <dirent.h>

#include <getopt.h>

char *Getconfig(char *);

#ifdef HTTPS
#else

void parse_option(int argc, char **argv, char *d, char **portp, char **logp);

#endif

#endif