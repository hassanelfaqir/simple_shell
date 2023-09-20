#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DELIM " \t\n"

extern char **environ;
char **tokenizer(char *line);
int _exec(char **cmd, char **argv, int index);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void free_arry(char **ar);
char *r_line(void);
char *_strdup(const char *str);
char *_getenv(char *vall);
char *get_path(char *cmd);
char *intToString(int num);
void p_error(char *nm, char *cmd, int index);

#endif
